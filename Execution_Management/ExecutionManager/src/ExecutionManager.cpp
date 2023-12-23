//============================================================================
// Name        : ExecutionManagement.cpp
// Author      : Karine
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "../include/ExecutionManager.h"
#define MachineFG "MachineFG"
#define startup "startup"
using namespace rapidjson;
namespace fs = std::filesystem;

namespace ara
{
	namespace exec
	{
		namespace internal
		{

			ExecutionManager::ExecutionManager()
				: stateManagementProcess(StateStartupConfiguration({}, {}, true, true))
			{
			}

			void ExecutionManager::extractSWPackages()
			{
                                                       
				// Specify the path to the folder of software packages
				
				// std::string folderPath = "/home/karine/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/SW_packages";

				std::string folderPath = "../../SW_packages";
				// /home/karine/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager
				// /home/karine/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src

				// Iterate over the contents of the directory
				for (const auto &entry : fs::directory_iterator(folderPath))
				{

					// entry.path().filename() returns the name of the directory
					Executable current_executable;
					current_executable.name = entry.path().filename();

					if (fs::is_directory(entry.path()))
					{

						// Get the execution manifest and executable of each process
						for (const auto &entry : fs::directory_iterator(entry.path().string()))
						{
							if (entry.path().extension() == ".json")
							{
								current_executable.json_path = entry.path();
							}
							else
							{
								current_executable.exe_path = entry.path();
							}
						}
						process_executables.push_back(current_executable);
					}
				}
			}

			void ExecutionManager::extractMachineManifest()
			{
				MachineManifest machineManifest("../../machine_manifest.json");

				machineManifest.parseMachineManifest(functionGroups);
			}

			void ExecutionManager::extractExecutionManifests()
			{
				/*Extracting Manifests and initializing startup configurations*/
				for (const auto &process : process_executables)
				{
					
					ExecutionManifest executionManifest(process.json_path);
					vector<ProcessConfig> processConfigs;
					executionManifest.parseStateDependentStartupConfigs(processConfigs);
					ara::exec::internal::StartupConfiguration::Executable exe = {process.name, process.exe_path};

					/*Adding each process configuration to a startup configuration*/
					for (const auto &processConfig : processConfigs)
					{

						if (executionManifest.isStateClientProcess())
						{
							stateManagementProcess.setExecutable(exe);
							stateManagementProcess.setProcessConfig(processConfigs[0]);
							startupConfigs.push_back(stateManagementProcess);
						}
						else
						{
							startupConfigs.push_back(ara::exec::internal::StartupConfiguration(exe, processConfig, executionManifest.isFunctionalClusterProcess(),
																							   executionManifest.isStateClientProcess()));
						}

						/*Adding each startup configuration to state in a function group*/
						std::vector<FunctionGroup>::iterator functiongGroup_it = findFunctionGroup(startupConfigs.back().functionGroup);

						if (functiongGroup_it != functionGroups.end())
						{
							for (const auto &state : startupConfigs.back().functionGroupState)
							{
								if (find(functiongGroup_it->GetAllStates().begin(), functiongGroup_it->GetAllStates().end(), state) != functiongGroup_it->GetAllStates().end())
								{
									functiongGroup_it->AddStartupConfiguration(state, startupConfigs.back());
								}
							}
						}
					}
				}
			}

			void ExecutionManager::terminatestartupConfigs(deque<StartupConfiguration *> &configs, bool &threadIsCancelled, std::mutex &threadIsCancelledLock)
			{

				for (auto &config : configs)
				{
					threadIsCancelledLock.lock();
					if (threadIsCancelled)
					{
						threadIsCancelledLock.unlock();
						return;
					}
					else
					{
						threadIsCancelledLock.unlock();
					}

					if (!config->isTerminated())
					{
						cout << config->configName << endl;
						config->term();
					}

					threadIsCancelledLock.lock();
					while (!config->isTerminated() && !threadIsCancelled)
					{
						threadIsCancelledLock.unlock();
						std::cout << "From EM Main: Terminating Child" << std::endl;
						sleep(1);

						if (config->exitTimeoutExpired())
						{

							std::cout << "From EM Main: Terminating Child Timeout" << std::endl;

							std::cout << "From EM Main: Killing Child" << std::endl;

							config->kill();

							std::cout << "From EM Main: Child Killed" << std::endl;
						}
						threadIsCancelledLock.lock();
					}
					threadIsCancelledLock.unlock();

					threadIsCancelledLock.lock();
					if (threadIsCancelled)
					{
						threadIsCancelledLock.unlock();
						return;
					}
					else
					{
						threadIsCancelledLock.unlock();
					}

					std::cout << "From EM Main: Child Terminated" << std::endl;
				}
			}

			void ExecutionManager::startStartupConfigs(deque<StartupConfiguration *> &configs, ara::exec::internal::StateResponse::Status &status, bool &threadIsCancelled, std::mutex &threadIsCancelledLock)
			{

				for (auto &config : configs)
				{

					threadIsCancelledLock.lock();
					if (threadIsCancelled)
					{
						threadIsCancelledLock.unlock();
						return;
					}
					else
					{
						threadIsCancelledLock.unlock();
					}

					if (!config->start())
					{
						std::cout << "EM: Couldn't start process" << std::endl;
						status = ara::exec::internal::StateResponse::Status::kFailed;
						return;
					}

					cout << config->configName << endl;

					if (config->isTerminated())
					{
						std::terminate();
					}

					threadIsCancelledLock.lock();
					while (!config->handleReportExecutionState() && !threadIsCancelled)
					{
						threadIsCancelledLock.unlock();
						std::cout << "From EM Main: Child Have Not Reported kRunning" << std::endl;
						sleep(1);

						if (config->enterTimeoutExpired())
						{

							std::cout << "From EM Main: kRunning Timeout" << std::endl;
							std::cout << "From EM Main: Will Terminate Child" << std::endl;
							config->term();
							status = ara::exec::internal::StateResponse::Status::kFailed;
							std::cout << "From EM Main: Child Terminated" << std::endl;
						}
						threadIsCancelledLock.lock();
					}
					threadIsCancelledLock.unlock();

					std::cout << "From EM Main: Child Have Reported kRunning" << std::endl;
				}
			}

			ara::exec::internal::StateResponse::Status ExecutionManager::validate(bool &isvalid, string_view functionGroup, string_view newState)
			{

				string tempFGN = string(functionGroup);
				string tempNFGS = string(newState);
				ara::exec::internal::StateResponse::Status status;
				isvalid = true;
				std::vector<FunctionGroup>::iterator functionGroup_it = findFunctionGroup(tempFGN);

				std::cout << "From EM Main: Received transition request [" << tempFGN << ", " << tempNFGS << "]" << std::endl;
				// validating function group
				if (functionGroup_it == functionGroups.end())
				{
					cout << "function group :" << tempFGN << " not found" << endl;
					// returning error function group not found in function groups
					status = ara::exec::internal::StateResponse::Status::kMetaModelError;
					isvalid = false;
				}

				// validating state
				bool stateExist = functionGroup_it->StateExist(tempNFGS);

				if (!stateExist)
				{
					cout << "State " << tempNFGS << " does not exist in function group " << tempFGN << endl;
					// returning error state not found in function group
					status = ara::exec::internal::StateResponse::Status::kMetaModelError;
					isvalid = false;
				}

				// checking if transition to a new state not to the same state the function group is in it
				if (tempNFGS == functionGroup_it->GetCurrentStateName())
				{
					cout << "function group " << tempFGN << " is already in state " << functionGroup_it->GetCurrentStateName() << endl;
					status = ara::exec::internal::StateResponse::Status::kAlreadyInState;
					isvalid = false;
				}

				return status;
			}

			void ExecutionManager::initialMachineTransition()
			{
				string tempFGN = MachineFG;
				std::vector<FunctionGroup>::iterator functionGroup_it = findFunctionGroup(tempFGN);

				if (functionGroup_it != functionGroups.end())
				{
					functionGroup_it->SetCurrentState(startup);
				}

				cout << functionGroup_it->GetCurrentStateName() << endl;
				vector<StartupConfiguration *> requiredStartupConfigs = functionGroup_it->GetStartupConfigurations(startup);
				if (functionGroup_it->GetCurrentStateName() == startup)
				{
					// Starting state Management process (SM)
					stateManagementProcess.start();
					while (!stateManagementProcess.handleReportExecutionState())
					{

						std::cout << "From EM Main: Child Have Not Reported kRunning" << std::endl;
						sleep(1);

						if (stateManagementProcess.enterTimeoutExpired())
						{

							std::cout << "From EM Main: kRunning Timeout" << std::endl;
							std::cout << "From EM Main: Will Terminate Child" << std::endl;
							stateManagementProcess.term();
							std::cout << "From EM Main: Child Terminated" << std::endl;
						}
					}
					std::cout << "From EM Main: Child Have Reported kRunning" << std::endl;

					for (auto &startupConfig : requiredStartupConfigs)
					{
						if (!startupConfig->isStateClientProcess && startupConfig->getProcessState() == StartupConfiguration::ProcessState::kIdle)
						{
							// starting other processes in the startup state in Machine function group
							std::cout << startupConfig->configName << std::endl;
							startupConfig->start();
							while (!startupConfig->handleReportExecutionState())
							{

								std::cout << "From EM Main: Child Have Not Reported kRunning" << std::endl;
								sleep(1);

								if (startupConfig->enterTimeoutExpired())
								{

									std::cout << "From EM Main: kRunning Timeout" << std::endl;
									std::cout << "From EM Main: Will Terminate Child" << std::endl;
									startupConfig->term();
									std::cout << "From EM Main: Child Terminated" << std::endl;
								}
							}
							std::cout << "From EM Main: Child Have Reported kRunning" << std::endl;
						}
					}
					cout << "initial transition done" << endl;
					ara::exec::internal::StateResponse::Status initialMachineStateTRansitionResult = ara::exec::internal::StateResponse::Status::kSuccess;
					stateManagementProcess.pipeInput.write((char *)&initialMachineStateTRansitionResult, 1);
				}
				else
				{

					cout << "Error in initial machine transition" << endl;
				}
			}

			void ExecutionManager::transition(StateRequest request, bool &threadIsRunning, std::mutex &threadIsRunningLock, bool &threadIsCancelled, std::mutex &threadIsCancelledLock)
			{

				ara::exec::internal::StateResponse::Status status = ara::exec::internal::StateResponse::Status::kSuccess;

				string targetName = string(request.functionGroupName);
				std::vector<FunctionGroup>::iterator functionGroup_it = findFunctionGroup(targetName);

				// Get all past startup configuration to terminate it
				std::vector<StartupConfiguration *> startupConfigs = functionGroup_it->GetStartupConfigurations(functionGroup_it->GetCurrentStateName());

				// set current state of the function group by new state
				functionGroup_it->SetCurrentState(string(request.newStateName));

				// Terminate processes
				deque<StartupConfiguration *> TerminatingStartupConfigs;

				for (auto &startupConfig : startupConfigs)
				{
					if (startupConfig->getProcessState() == StartupConfiguration::ProcessState::kStarting || startupConfig->getProcessState() == StartupConfiguration::ProcessState::kRunning)
					{
						bool flagtoterminate = functionGroup_it->CheckForStartupConfiguration(*startupConfig);
						if (flagtoterminate == false)
						{
							TerminatingStartupConfigs.push_back(startupConfig);
						}
					}
				}

				threadIsCancelledLock.lock();
				if (threadIsCancelled)
				{
					threadIsCancelledLock.unlock();
					threadIsRunning = false;
					return;
				}
				else
				{
					threadIsCancelledLock.unlock();
				}

				terminatestartupConfigs(TerminatingStartupConfigs, threadIsCancelled, threadIsCancelledLock);

				threadIsCancelledLock.lock();
				if (threadIsCancelled)
				{
					threadIsCancelledLock.unlock();
					threadIsRunning = false;
					return;
				}
				else
				{
					threadIsCancelledLock.unlock();
				}

				// starting processes
				vector<StartupConfiguration *> requiredStartupConfigs = functionGroup_it->GetStartupConfigurations(functionGroup_it->GetCurrentStateName());
				vector<StartupConfiguration *> nonDependenStartupConfigs;
				deque<StartupConfiguration *> StartingStartupConfigs;

				// Check for dependency
				for (auto &startupConfig : requiredStartupConfigs)
				{

					if (startupConfig->getProcessState() == ara::exec::internal::StartupConfiguration::ProcessState::kIdle && !(startupConfig->executionDependency).empty())
					{

						for (const auto &startupConfigdependency : startupConfig->executionDependency)
						{

							if (startupConfigdependency.dependency == "Running")
							{

								for (size_t i = 0; i < requiredStartupConfigs.size(); i++)
								{
									if (requiredStartupConfigs[i]->configName == startupConfigdependency.processName)
									{
										if (requiredStartupConfigs[i]->getProcessState() == ara::exec::internal::StartupConfiguration::ProcessState::kIdle)
										{

											StartingStartupConfigs.push_back(requiredStartupConfigs[i]);
										}
									}
								}
							}
						}

						StartingStartupConfigs.push_back(startupConfig);
					}

					nonDependenStartupConfigs.push_back(startupConfig);
				}

				for (auto &startupConfig : nonDependenStartupConfigs)
				{

					bool exist = false;
					for (size_t i = 0; i < StartingStartupConfigs.size(); i++)
					{
						if (StartingStartupConfigs[i]->configName == startupConfig->configName)
						{
							exist = true;
							break;
						}
					}
					if (!exist)
					{
						if (startupConfig->getProcessState() == ara::exec::internal::StartupConfiguration::ProcessState::kIdle)
						{
							StartingStartupConfigs.push_back(startupConfig);
						}
					}
				}

				threadIsCancelledLock.lock();
				if (threadIsCancelled)
				{
					threadIsCancelledLock.unlock();
					threadIsRunning = false;
					return;
				}
				else
				{
					threadIsCancelledLock.unlock();
				}

				startStartupConfigs(StartingStartupConfigs, status, threadIsCancelled, threadIsCancelledLock);

				threadIsCancelledLock.lock();
				if (threadIsCancelled)
				{
					threadIsCancelledLock.unlock();
					threadIsRunning = false;
					return;
				}
				else
				{
					threadIsCancelledLock.unlock();
				}

				ara::exec::internal::StateResponse stateResponse = {request.requestId, status};
				stateManagementProcess.pipeInput.write((char *)&stateResponse, sizeof(stateResponse));

				threadIsRunningLock.lock();
				threadIsRunning = false;
				threadIsRunningLock.unlock();
				return;
			}

			std::vector<FunctionGroup>::iterator ExecutionManager::findFunctionGroup(string targetName)
			{

				std::vector<FunctionGroup>::iterator functionGroup_it = find_if(functionGroups.begin(), functionGroups.end(),
																				[targetName](const FunctionGroup &fg)
																				{
																					return fg.GetName() == targetName;
																				});

				// Check if the element was found before dereferencing the iterator
				return functionGroup_it;
			}

			ExecutionManager::~ExecutionManager()
			{
				// TODO Auto-generated destructor stub
			}

		} /* namespace internal */
	}	  /* namespace exec */
} /* namespace ara */
