/*
 * ExecutionManifest.cpp
 *
 *  Created on: 19 Nov 2023
 *      Author: karin
 */

#include "../include/ExecutionManifest.h"
using namespace rapidjson;
using namespace std;

namespace ara
{
	namespace exec
	{
		namespace internal
		{

			ExecutionManifest::ExecutionManifest(std::string executionManifestPath) {

				std::ifstream file(executionManifestPath);

				if (!file.is_open()) {
					std::cerr << "Error opening file.\n";
					return;
				}

				std::ostringstream contentStream;
				contentStream << file.rdbuf();
				std::string jsonString = contentStream.str();
				const char* json = jsonString.c_str();

				document.Parse(json);

			}

			bool ExecutionManifest::isFunctionalClusterProcess(){
				assert(document.HasMember("functional_cluster_process"));
				assert(document["functional_cluster_process"].IsBool());
				return document["functional_cluster_process"].GetBool();
			}

			bool ExecutionManifest::isStateClientProcess(){
				assert(document.HasMember("state_client_process"));
				assert(document["state_client_process"].IsBool());
				return document["state_client_process"].GetBool();
			}

			void ExecutionManifest::parseStateDependentStartupConfigs(std::vector<ProcessConfig>& processConfigs){

				assert(document.HasMember("startup_configs"));
				assert(document["startup_configs"].IsArray());

				const rapidjson::Value &configs = document["startup_configs"];


				for (rapidjson::Value::ConstValueIterator config = configs.Begin(); config != configs.End(); config++){

					ProcessConfig currentProcessConfig;
					ExecutionDependency execDependency;


					assert((*config).HasMember("config_name"));
					assert((*config)["config_name"].IsString());

					currentProcessConfig.configName = (*config)["config_name"].GetString();




					assert((*config).HasMember("execution_dependency"));
					assert((*config)["execution_dependency"].IsArray());
					const rapidjson::Value &execDependencies = (*config)["execution_dependency"].GetArray();

					for(rapidjson::Value::ConstValueIterator execDependency = execDependencies.Begin(); execDependency != execDependencies.End(); execDependency++){

						size_t dotPos = string((*execDependency).GetString()).find('.');

						std::string exeDependencyName = string((*execDependency).GetString()).substr(0, dotPos);

						std::string exeDependencyState = string((*execDependency).GetString()).substr(dotPos+1);

						currentProcessConfig.executionDependencies.push_back({exeDependencyName, exeDependencyState});

					}




					assert((*config).HasMember("machine_states"));
					assert((*config)["machine_states"].IsArray());

					assert((*config).HasMember("function_group_states"));
					const rapidjson::Value &functionGroup = (*config)["function_group_states"];
					assert((functionGroup).HasMember("function_group_name"));
					assert((functionGroup)["function_group_name"].IsString());
					assert((*config)["function_group_states"].HasMember("function_group_state"));
					assert((*config)["function_group_states"]["function_group_state"].IsArray());

					bool isMachineFunctionGroup = !(*config)["machine_states"].GetArray().Empty();
					bool isOtherFunctionGroup = !(*config)["function_group_states"]["function_group_state"].GetArray().Empty();

					if(!isMachineFunctionGroup && !isOtherFunctionGroup){
						assert(false && "Error both empty");
					}else if(isMachineFunctionGroup && isOtherFunctionGroup){
						assert(false && "Error both full");
					}

					currentProcessConfig.functionGroup = (functionGroup)["function_group_name"].GetString();


					const rapidjson::Value &fgStates = isMachineFunctionGroup ?
							(*config)["machine_states"].GetArray()
							:(functionGroup)["function_group_state"].GetArray();

					if(isMachineFunctionGroup){
						currentProcessConfig.functionGroup = "MachineFG";
					}
					else{
						assert(currentProcessConfig.functionGroup.length() != 0);
					}


					for(rapidjson::Value::ConstValueIterator fgState = fgStates.Begin(); fgState != fgStates.End(); fgState++){
						assert((*fgState).IsString());
						currentProcessConfig.functionGroupState.push_back((*fgState).GetString());
					}




					assert((*config).HasMember("scheduling_policy"));
					assert((*config)["scheduling_policy"].IsString());
					currentProcessConfig.schedulingPolicy = (*config)["scheduling_policy"].GetString();

					assert((*config).HasMember("scheduling_priority"));
					assert((*config)["scheduling_priority"].IsString());
					currentProcessConfig.schedulingPriority = atoi((*config)["scheduling_priority"].GetString());




					assert((*config).HasMember("arguments"));
					assert((*config)["arguments"].IsArray());
					const rapidjson::Value &args = (*config)["arguments"].GetArray();

					for(rapidjson::Value::ConstValueIterator arg = args.Begin(); arg != args.End(); arg++){
						currentProcessConfig.args.push_back((*arg).GetString());
					}

					assert((*config).HasMember("environments"));
					assert((*config)["environments"].IsArray());
					const rapidjson::Value &envs = (*config)["environments"].GetArray();

					for(rapidjson::Value::ConstValueIterator env = envs.Begin(); env != envs.End(); env++){
						currentProcessConfig.envs.push_back((*env).GetString());
					}




					assert((*config).HasMember("timeout"));
					const rapidjson::Value &timeout = (*config)["timeout"];

					assert((timeout).HasMember("enter_timeout_ns"));
					assert((timeout)["enter_timeout_ns"].IsInt());
					currentProcessConfig.enterTimeout = (timeout)["enter_timeout_ns"].GetInt();

					assert((timeout).HasMember("exit_timeout_ns"));
					assert((timeout)["exit_timeout_ns"].IsInt());
					currentProcessConfig.exitTimeout = (timeout)["exit_timeout_ns"].GetInt();

					processConfigs.push_back(currentProcessConfig);

				}

			}

			ExecutionManifest::~ExecutionManifest() {
				// TODO Auto-generated destructor stub
			}

		}
	}
}


