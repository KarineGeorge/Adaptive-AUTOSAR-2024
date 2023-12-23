/*
 * StateStartupConfiguration.cpp
 *
 *  Created on: Nov 28, 2023
 *      Author: karine
 */

#include "../include/StateStartupConfiguration.h"
#include "../include/ExecutionClient.h"

namespace ara {
	namespace exec {
		namespace internal {

			StateStartupConfiguration::StateStartupConfiguration(Executable executable, ProcessConfig processConfig, bool isFunctionalClusterProcess, bool isStateClientProcess)
					:StartupConfiguration(executable, processConfig, isFunctionalClusterProcess, isStateClientProcess),
					 EmInSmOut(ara::exec::internal::Pipe()),
					 pipeInput(ara::exec::internal::PipeInput(EmInSmOut.getWriteFd()))
					 {}

			bool StateStartupConfiguration::StateStartupConfiguration::start(){

				if(pid != 0){

					std::cout<< "EM: An Error process is already running \n";
					return false;
				}

				enterStartTime = std::chrono::steady_clock::now();

				pid = fork();

				if(pid == -1){

					std::cout<< "EM: An Error occurred with fork \n";
					return false;
				}
				else if(pid == 0){
					//child process

					const struct sched_param param = {0};

					if(sched_setscheduler(getpid(), SCHED_OTHER, &param) == -1){

						if (errno == EPERM)
							std::cout << "Cannot set scheduling policy" << std::endl;


						std::cout << "Cannot set scheduling policy" << std::endl;
					}


					const char *exePath = executable.exePath.c_str();

					char* argv[args.size() + 2];

					argv[0] = new char[executable.exePath.size() + 1];
					std::strcpy(argv[0], exePath);

					for(size_t i = 0; i < args.size(); i++){
						argv[i + 1] = new char[args[i].size() + 1];
						std::strcpy(argv[i + 1], args[i].c_str());
					}

					argv[args.size() + 1] = new char[1];
					argv[args.size() + 1] = NULL;



					if(close(pipe.getReadFd()) == -1){
						std::cout<< "EM: Error has occurred while closing readFd \n";
						return false;
					}

					if(dup2(pipe.getWriteFd(), ExecutionClient_WRITE_FD) == -1){
						std::cout<< "EM: Error has occurred while duplicating the writeFD \n";
						return false;
					}

					if(close(EmInSmOut.getWriteFd()) == -1){
						std::cout<< "EM: Error has occurred while closing state's pipe writeFd \n";
						return false;
					}

					if(dup2(EmInSmOut.getReadFd(), STATE_CLIENT_READ_FD) == -1){
						std::cout<< "EM: Error has occurred while duplicating state's pipe the readFD \n";
						return false;
					}

					//without env variables
					execv(exePath, argv);


					//The below is executed only if execv failed
					std::cout<< "EM: Error is occurred while executing the child executable\n";
					for(uint8_t i = 0; i < args.size() + 2; ++i){

						delete[] argv[i];
					}

					exit(1);
				}
				else{
					//parent process

					//Child process was created successfully
					processState = ProcessState::kStarting;

					//Close the write end file descriptor for the executionManager
					if(close(pipe.getWriteFd()) == -1){

						std::cout<< "EM: Error is occurred while closing writeFd \n";
						return false;
					}
				}

				return true;
			}

			void StateStartupConfiguration::readRequest(StateRequest &stateRequest){

				bool isEmpty = true;
				std::uint8_t fgSize;
				std::uint8_t fgsSize;

				while(isEmpty)
					pipeOutput.read((char*) &stateRequest.requestId, 1, &isEmpty);
				isEmpty = true;

				while(isEmpty)
					pipeOutput.read((char*) &fgSize, 1, &isEmpty);
				isEmpty = true;

				char *fg= new char[fgSize];

				while(isEmpty)
					pipeOutput.read(fg, fgSize, &isEmpty);
				isEmpty = true;
				stateRequest.functionGroupName= std::string_view(fg, fgSize - 1);

				while(isEmpty)
					pipeOutput.read((char*) &fgsSize, 1, &isEmpty);
				isEmpty = true;

				char *fgs = new char[fgsSize];

				while(isEmpty)
					pipeOutput.read(fgs, fgsSize, &isEmpty);
				isEmpty = true;

				stateRequest.newStateName= std::string_view(fgs, fgsSize - 1);
			}

			StateStartupConfiguration::~StateStartupConfiguration()
			{
				// TODO Auto-generated destructor stub
			}

		} /* namespace internal */
	} /* namespace exec */
} /* namespace ara */
