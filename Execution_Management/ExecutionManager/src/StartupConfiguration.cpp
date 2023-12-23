/*
 * StartupConfiguration.cpp
 *
 *  Created on: 22 Nov 2023
 *      Author: karin
 */

#include "../include/StartupConfiguration.h"
#include <signal.h>
#include <csignal>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sched.h>
#include <errno.h>
#include "../include/ExecutionClient.h"
#include <sys/wait.h>
#include <stdio.h>


namespace ara{

	namespace exec{

		namespace internal{

			/* Constructor
			 *
			 * Initializes the configuration parameters of the process
			 */

			StartupConfiguration::StartupConfiguration(Executable executable, ProcessConfig processConfig, bool isFunctionalClusterProcess, bool isStateClientProcess)
			:pid(0),
			 executable(executable),
			 processState(ProcessState::kIdle),
			 isFunctionalClusterProcess(isFunctionalClusterProcess),
			 isStateClientProcess(isStateClientProcess),
			 configName(processConfig.configName),
			 functionGroup(processConfig.functionGroup),
			 functionGroupState(processConfig.functionGroupState),
			 executionDependency(processConfig.executionDependencies),
			 schedulingPolicy(processConfig.schedulingPolicy),
			 schedulingPriority(processConfig.schedulingPriority),
			 args(processConfig.args),
			 envs(processConfig.envs),
			 enterTimeout(processConfig.enterTimeout),
			 exitTimeout(processConfig.exitTimeout),
			 enterStartTime(std::chrono::steady_clock::time_point::min()),
			 exitStartTime(std::chrono::steady_clock::time_point::min()),
			 pipe(Pipe()),
			 pipeOutput(PipeOutput(pipe.getReadFd()))
			 {

			 }



			/* Starts a new process */
			bool StartupConfiguration::start(){


				/* Checks if the process have not been already started */
				if(pid != 0){

					std::cout<< "EM: An Error process is already running \n";
					return false;
				}

				/* Gets the current time */
				enterStartTime = std::chrono::steady_clock::now();


				/* Execution Management forks a new Child */
				pid = fork();

				/* Checks if the fork operation was successful */
				if(pid == -1){

					std::cout<< "EM: An Error occurred with fork \n";
					return false;
				}
				else if(pid == 0){ /* Checks if this process is the created Child */
					//child process

					std::uint8_t schedPolicy;	/* Scheduling Policy */
					const struct sched_param param = {schedulingPriority};	/* Scheduling Priority */
					const char *exePath = executable.exePath.c_str(); /* Path of The Executable in C String Style */


					/* Configures The Scheduling Policy Configuration Parameter With The Right Configuration */
					if(schedulingPolicy == "SCHED_RR"){
						schedPolicy = SCHED_RR;
					}
					else if(schedulingPolicy == "SCHED_FIFO"){
						schedPolicy = SCHED_FIFO;
					}
					else{
						schedPolicy = SCHED_OTHER;
					}

					/* Configures The OS According To The Configuration Parameters */
					if(sched_setscheduler(getpid(), schedPolicy, &param) == -1){

						/* Process Does Not Have The Right Privileges To Run With The Configured Scheduling Policy */
						if (errno == EPERM)
							std::cout << "Cannot set scheduling policy" << std::endl;

					}


					/* Allocate an array of pointers to char with size args + 2 */
					char* argv[args.size() + 2];

					/* Allocate the right number of bytes to which the pointer points according to the length of each arg string */
					argv[0] = new char[executable.exePath.size() + 1];
					std::strcpy(argv[0], exePath);

					for(size_t i = 0; i < args.size(); i++){
						argv[i + 1] = new char[args[i].size() + 1];
						std::strcpy(argv[i + 1], args[i].c_str());
					}

					/* Last argument in the args passed to execv must be NULL */
					argv[args.size() + 1] = new char[1];
					argv[args.size() + 1] = NULL;


					/* Close the read end of the pipe for the Child, since the Child process will only be reporting kRunning */
					if(close(pipe.getReadFd()) == -1){
						std::cout<< "EM: Error is occurred while closing readFd \n";
						return false;
					}



					/* Make the ExecutionClient_WRITE_FD index point to the Write FD of the Pipe */
					if(dup2(pipe.getWriteFd(), ExecutionClient_WRITE_FD) == -1){
						std::cout<< "EM: Error is occurred while duplicating the writeFD \n";
						return false;
					}

					//without env variables
					/* Execute the Executable of the Process */
					execv(exePath, argv);


					/* Below is executed only if we fail to execute the Executable */

					/* Deallocate the memory allocated for the arguments */
					std::cout<< "EM: Error is occurred while executing the child executable\n";
					for(uint8_t i = 0; i < args.size() + 2; ++i){

						delete[] argv[i];
					}

					exit(1);
				}
				else{ /* Parent Process */

					/* Child process was created successfully */
					processState = ProcessState::kStarting;

					/* Close the write end file descriptor for the Execution Manager */
					if(close(pipe.getWriteFd()) == -1){

						std::cout<< "EM: Error is occurred while closing writeFd \n";
						return false;
					}
				}

				return true;
			}

			/* Make sure to call isTerminated() before calling term() */
			/* Used To Terminate a Process */
			void StartupConfiguration::term(){

				/* Terminates The Process Using SIGTERM Signal */
				if(::kill(pid, SIGTERM) == -1){

					std::cout << "EM: an error is occurred while sending SIGTERM" << std::endl;
					return;
				}

				exitStartTime = std::chrono::steady_clock::now();
				handleProcessStateTerminating();
			}


			/* Used To Kill a Process */
			void StartupConfiguration::kill(){

				/* Kill a Process Using SIGKILL Signal */
				if(::kill(pid, SIGKILL) == -1){

					std::cout << "EM: an error is occurred while sending SIGKILL" << std::endl;
					return;
				}
			}


			/* Check If The Created Process Has Reported kRunning and Change The Process State Accordingly */
			bool StartupConfiguration::handleReportExecutionState(){

				bool isEmpty;
				char executionState;

				pipeOutput.read(&executionState, 1, &isEmpty);

				if(!isEmpty){

					if(static_cast<ara::exec::ExecutionState>(executionState) == ara::exec::ExecutionState::kRunning){

						processState = ProcessState::kRunning;

						exitStartTime = std::chrono::steady_clock::time_point::min();

						return true;
					}
				}

				return false;
			}


			/* Checks If A Process Have Been Terminated */
			bool StartupConfiguration::isTerminated(){


				pid_t term_pid = waitpid(pid, NULL, WNOHANG);


				if(term_pid == 0){ /* The Process Has Not Terminated */

					return false;
				}
				else if(term_pid == pid){	/* The Non Self-Terminating Process Has Been Terminated */

					exitStartTime = std::chrono::steady_clock::time_point::min();
					handleProcessStateTerminated();
					return true;
				}
				else{


					/* The Self-Terminating Process Has Terminated */
					if(errno == ECHILD){

						std::cout << "Self Terminated Process" << std::endl;
						handleProcessStateTerminated();
						return true;
					}

					/* Error while executing waitpid systemCall */
					std::cout << "EM: an error has occurred while executing waitpid syscall" << std::endl;
					return false;
				}
			}

			bool StartupConfiguration::enterTimeoutExpired(){

				if(enterStartTime == std::chrono::steady_clock::time_point::min()){

					return false;
				}

				std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
				std::chrono::milliseconds elapsedDuration = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - enterStartTime);

		        return elapsedDuration >= enterTimeout;

			}

			void StartupConfiguration::handleProcessStateTerminating(){

				if(processState == ProcessState::kRunning){

					processState = ProcessState::kTerminating;
				}
			}

			void StartupConfiguration::handleProcessStateTerminated(){

				if((processState == ProcessState::kRunning) | (processState == ProcessState::kTerminating)){

					processState = ProcessState::kTerminated;
				}
				else{
					processState = ProcessState::kIdle;
				}
			}


			bool StartupConfiguration::exitTimeoutExpired(){

				if(exitStartTime == std::chrono::steady_clock::time_point::min()){

					return false;
				}

				std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
				std::chrono::milliseconds elapsedDuration = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - exitStartTime);

				return elapsedDuration >= exitTimeout;

			}



			void StartupConfiguration::setProcessState(StartupConfiguration::ProcessState state){

				processState = state;
			}

			StartupConfiguration::ProcessState StartupConfiguration::getProcessState(){

				return processState;
			}

			void StartupConfiguration::setExecutable(Executable executable){

				this->executable = executable;

			}

			void StartupConfiguration::setProcessConfig(ProcessConfig processConfig){

				 this->configName = processConfig.configName;
				 this->functionGroup = processConfig.functionGroup;
				 this->functionGroupState = processConfig.functionGroupState;
				 this->executionDependency = processConfig.executionDependencies;
				 this->schedulingPolicy = processConfig.schedulingPolicy;
				 this->schedulingPriority = processConfig.schedulingPriority;
				 this->args = processConfig.args;
				 this->envs = processConfig.envs;
				 this->enterTimeout = (std::chrono::milliseconds)processConfig.enterTimeout;
				 this->exitTimeout = (std::chrono::milliseconds)processConfig.exitTimeout;

			}

			StartupConfiguration::~StartupConfiguration() {

			}

		}

	}

}

