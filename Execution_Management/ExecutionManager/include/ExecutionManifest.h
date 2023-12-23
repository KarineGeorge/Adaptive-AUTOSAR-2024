/*
 * ExecutionManifest.h
 *
 *  Created on: 19 Nov 2023
 *      Author: karin
 */

#ifndef EXECUTIONMANIFEST_H_
#define EXECUTIONMANIFEST_H_

#include <string>
#include <vector>
#include <cstdint>
#include <fstream>
#include <sstream>
#include <iostream>
#include <assert.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

namespace ara
{
    namespace exec
	{
		namespace internal
		{

			typedef struct{
				std::string processName;
				std::string dependency;
			}ExecutionDependency;

			typedef struct{
				std::string configName;
				std::vector<ExecutionDependency> executionDependencies;
				std::string functionGroup;
				std::vector<std::string> functionGroupState;
				std::string schedulingPolicy;
				std::uint32_t schedulingPriority;
				std::vector<std::string> args;
				std::vector<std::string> envs;
				uint32_t enterTimeout;
				uint32_t exitTimeout;
			}ProcessConfig;


			class ExecutionManifest {
			private:

				rapidjson::Document document;
			public:
				ExecutionManifest(std::string executionManifestPath);
				bool isFunctionalClusterProcess();
				bool isStateClientProcess();
				void parseStateDependentStartupConfigs(std::vector<ProcessConfig>& processConfig);
				virtual ~ExecutionManifest();
			};

		}
	}
}
#endif /* EXECUTIONMANIFEST_H_ */
