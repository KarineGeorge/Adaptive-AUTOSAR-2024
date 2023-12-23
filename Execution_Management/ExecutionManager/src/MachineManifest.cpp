/*
 * MachineManifest.cpp
 *
 *  Created on: Nov 20, 2023
 *      Author: atef
 */

#include "../include/MachineManifest.h"
#include<bits/stdc++.h>
using namespace rapidjson;
using namespace std;

namespace ara
{
	namespace exec
	{
		namespace internal
		{

			MachineManifest::MachineManifest(std::string machineManifestPath) {

				std::ifstream file(machineManifestPath);

				if (!file) {
					std::cerr << "Error opening file.\n";
					return;
				}

				std::ostringstream contentStream;
				contentStream << file.rdbuf();
				std::string jsonString = contentStream.str();
				const char *json = jsonString.c_str();
				document.Parse(json);
			}

			void MachineManifest::parseMachineManifest(std::vector<ara::exec::internal::FunctionGroup>& functionGroupConfigs) {
				bool flag=false;
				assert(document.HasMember("function_groups"));
				assert(document["function_groups"].IsArray());
				const rapidjson::Value& function_groups = document["function_groups"];
				for (rapidjson::Value::ConstValueIterator function_group = function_groups.Begin() ;function_group != function_groups.End(); function_group++) {

//					FunctionGroup currentFunctionGroupConfig;


					assert((*function_group).HasMember("function_group"));

					assert((*function_group)["function_group"].HasMember("name"));
					assert((*function_group)["function_group"]["name"].IsString());
					std::string Name = (*function_group)["function_group"]["name"].GetString();

					const rapidjson::Value& FGState = (*function_group)["function_group"];
					assert(FGState.HasMember("states"));
					assert(FGState["states"].IsArray());

					const rapidjson::Value& FGstates=FGState["states"].GetArray();
					if(Name == "MachineFG"){
						flag=true;
						vector <string> Astates;
						for(rapidjson::Value::ConstValueIterator state = FGstates.Begin(); state != FGstates.End(); state++){
							assert((*state).IsString());
							Astates.push_back((*state).GetString());
						}
						if(find(Astates.begin(), Astates.end(), "startup") == Astates.end()){
							Astates.push_back("startup");
						}
						if(find(Astates.begin(), Astates.end(), "restart") == Astates.end()){
							Astates.push_back("restart");
						}
						if(find(Astates.begin(), Astates.end(), "shutdown") == Astates.end()){
							Astates.push_back("shutdown");
						}
						if(find(Astates.begin(), Astates.end(), "running") == Astates.end()){
							Astates.push_back("running");
						}
						functionGroupConfigs.push_back(FunctionGroup(Name,Astates));
					}else{
						if(flag){
							 std::vector<string> convertedValues;
							for(rapidjson::Value::ConstValueIterator state = FGstates.Begin(); state != FGstates.End(); state++){
								convertedValues.push_back((*state).GetString());
							}
//							FunctionGroup currentFunctionGroupConfig = FunctionGroup(Name,convertedValues);
							functionGroupConfigs.push_back(FunctionGroup(Name,convertedValues));
						}
						else{
							assert(false);
						}
					}

				}

			}

			MachineManifest::~MachineManifest() {
				// TODO Auto-generated destructor stub
			}

		}
	}
}
