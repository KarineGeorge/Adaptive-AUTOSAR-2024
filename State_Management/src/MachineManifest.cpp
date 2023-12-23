/*
 * MachineManifest.cpp
 *
 *  Created on: Nov 20, 2023
 *      Author: atef
 */

#include "../inc/MachineManifest.h"
#include<bits/stdc++.h>
using namespace rapidjson;
using namespace std;

namespace ara {
namespace exec {

  
            MachineManifest::MachineManifest(string machineManifestPath)
            {
                std::ifstream file(machineManifestPath);

                if (!file) {
                    std::cerr << "Error opening file.\n";
                    return;
                }

                std::ostringstream contentStream;
                contentStream << file.rdbuf();
                std::string jsonString = contentStream.str();
                const char* json = jsonString.c_str();
                document.Parse(json);

            }
            std::vector<adp::sm::internal::GroupsAndStates> MachineManifest::GetAllGroupsAndStates() const noexcept
            {
                return this->allGroupsAndStates_;

            }
            void MachineManifest::parseMachineManifest()
            {
                assert(document.HasMember("function_groups"));
                assert(document["function_groups"].IsArray());
                const rapidjson::Value& function_groups = document["function_groups"];
                for (rapidjson::Value::ConstValueIterator function_group = function_groups.Begin(); function_group != function_groups.End(); function_group++) {

                    adp::sm::internal::GroupsAndStates currentFunctionGroupConfig;


                    assert((*function_group).HasMember("function_group"));

                    assert((*function_group)["function_group"].HasMember("name"));
                    assert((*function_group)["function_group"]["name"].IsString());
                    currentFunctionGroupConfig.SetGroupName((*function_group)["function_group"]["name"].GetString());//MachineFG

                    const rapidjson::Value& FGState = (*function_group)["function_group"];
                    assert(FGState.HasMember("states"));
                    assert(FGState["states"].IsArray());

                    const rapidjson::Value& FGstates = FGState["states"].GetArray();//"running","sleep"
                    if (currentFunctionGroupConfig.GetGroupName() == "MachineFG") {
                        vector <string> Astates;
                        for (rapidjson::Value::ConstValueIterator state = FGstates.Begin(); state != FGstates.End(); state++) {
                            assert((*state).IsString());
                            Astates.push_back((*state).GetString());//"running","sleep"
                        }
                        if (std::find(Astates.begin(), Astates.end(), "startup") == Astates.end()) {
                            Astates.push_back("startup");
                        }
                        if (find(Astates.begin(), Astates.end(), "restart") == Astates.end()) {
                            Astates.push_back("restart");
                        }
                        if (find(Astates.begin(), Astates.end(), "shutdown") == Astates.end()) {
                            Astates.push_back("shutdown");
                        }
                        if (find(Astates.begin(), Astates.end(), "running") == Astates.end()) {
                            Astates.push_back("running");
                        }
                        for (vector<string>::iterator state = Astates.begin(); state != Astates.end(); state++) {
                            currentFunctionGroupConfig.SetGroupStaes(Astates);
                        }
                        allGroupsAndStates_.push_back(currentFunctionGroupConfig);

                    }
                    else {
                        for (rapidjson::Value::ConstValueIterator state = FGstates.Begin(); state != FGstates.End(); state++) {
                            currentFunctionGroupConfig.SetGroupStaesElement((*state).GetString());
                        }
                        allGroupsAndStates_.push_back(currentFunctionGroupConfig);
                    }
                }

            }



        };
}



