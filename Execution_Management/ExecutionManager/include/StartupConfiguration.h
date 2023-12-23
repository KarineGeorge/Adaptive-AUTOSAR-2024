/*
 * StartupConfiguration.h
 *
 *  Created on: 22 Nov 2023
 *      Author: karin
 */

#include <string.h>
#include <vector>
#include <cstdint>
#include <unistd.h>
#include <chrono>

#include "ExecutionManifest.h"
#include "Pipe.h"
#include "PipeOutput.h"


#ifndef STARTUPCONFIGURATION_H_
#define STARTUPCONFIGURATION_H_



namespace ara{

	namespace exec{

		namespace internal{

			class StartupConfiguration {
				private:

				public:

				typedef struct {
					std::string exeName;
					std::string exePath;
				}Executable;

				enum class ProcessState: std::uint8_t {
					kIdle,
					kStarting,
					kRunning,
					kTerminating,
					kTerminated
				};

				pid_t pid;
				Executable executable;
				ProcessState processState;
				bool isFunctionalClusterProcess;
				bool isStateClientProcess;
				std::string configName;
				std::string functionGroup;
				std::vector<std::string> functionGroupState;
				std::vector<ExecutionDependency> executionDependency;
				std::string schedulingPolicy;
				std::uint8_t schedulingPriority;
				std::vector<std::string> args;
				std::vector<std::string> envs;
				std::chrono::milliseconds enterTimeout;
				std::chrono::milliseconds exitTimeout;
				std::chrono::steady_clock::time_point enterStartTime;
				std::chrono::steady_clock::time_point exitStartTime;

				Pipe pipe;
				PipeOutput pipeOutput;


				StartupConfiguration(Executable executable, ProcessConfig processConfig, bool isFunctionalClusterProcess, bool isStateClientProcess);
				~StartupConfiguration();
				bool start();
				void term();
				void kill();
				bool handleReportExecutionState();
				bool isTerminated();
				bool enterTimeoutExpired();
				bool exitTimeoutExpired();
				void handleProcessStateTerminating();
				void handleProcessStateTerminated();
				void setProcessState(ProcessState state);
				ProcessState getProcessState();

				void setExecutable(Executable executable);
				void setProcessConfig(ProcessConfig processConfig);


			};

		}

	}

}

#endif /* STARTUPCONFIGURATION_H_ */
