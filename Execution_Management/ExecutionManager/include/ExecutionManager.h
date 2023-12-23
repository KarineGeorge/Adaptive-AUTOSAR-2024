/*
 * ExecutionManager.h
 *
 *  Created on: Dec 19, 2023
 *      Author: karine
 */

#ifndef EXECUTIONMANAGER_H_
#define EXECUTIONMANAGER_H_


#include <vector>
#include "ExecutionManager.h"
#include "ExecutionManifest.h"
#include "MachineManifest.h"
#include "StartupConfiguration.h"
#include "StateStartupConfiguration.h"
#include "StateRequest.h"
#include "StateResponse.h"
#include <string_view>
#include <filesystem>
#include "FunctionGroup.h"
#include <queue>
#include <deque>
#include <bits/stdc++.h>
#include <utility>

using namespace std;

namespace ara {
	namespace exec {
		namespace internal {

			typedef struct {
				std::string name;
				std::string json_path;
				std::string exe_path;
			}Executable;



			class ExecutionManager {
				public:

					std::vector<FunctionGroup> functionGroups;
					std::vector<ara::exec::internal::StartupConfiguration> startupConfigs;
					std::vector<Executable> process_executables;
					ara::exec::internal::StateStartupConfiguration stateManagementProcess;


					ExecutionManager();
					virtual ~ExecutionManager();
					std::vector<FunctionGroup>::iterator findFunctionGroup(std::string targetName);
//					std::vector<FunctionGroup>::iterator& findFunctionGroup(std::string targetName);
					void extractSWPackages();
					void extractMachineManifest();
					void extractExecutionManifests();
					void terminatestartupConfigs(deque<StartupConfiguration*>& configs, bool& threadIsCancelled,std::mutex& threadIsCancelledLock);
					void startStartupConfigs(deque<StartupConfiguration*>& configs,ara::exec::internal::StateResponse::Status& status, bool& threadIsCancelled,std::mutex& threadIsCancelledLock);
					ara::exec::internal::StateResponse::Status validate(bool& isvalid ,string_view functionGroup, string_view newState);
					// void checkChanges(string_view functionGroup, string_view newState,ara::exec::internal::StateResponse::Status& status);
					// void checkDependency(string_view functionGroup, string_view newState,ara::exec::internal::StateResponse::Status& status);
					void initialMachineTransition();
					void transition(StateRequest request, bool& threadIsRunning, std::mutex& threadIsRunningLock, bool& threadIsCancelled, std::mutex& threadIsCancelledLock);
					void TerminateAllStartupConfiguration();
			};
		} /* namespace internal */
	} /* namespace exec */
} /* namespace ara */

#endif /* EXECUTIONMANAGER2_H_ */
