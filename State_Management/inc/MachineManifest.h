/*
 * MachineManifest.h
 *
 *  Created on: Nov 20, 2023
 *      Author: georg
 */


#ifndef MACHINEMANIFEST_H_
#define MACHINEMANIFEST_H_

#include <string>
#include <vector>
#include <cstdint>
#include <fstream>
#include <sstream>
#include <iostream>

#include "../rapidjson/document.h"
#include "../rapidjson/writer.h"
#include "../rapidjson/stringbuffer.h"
#include "GroupsAndStates.hpp"
using namespace std;

namespace ara{

    namespace exec{

    	typedef struct{
    		std::string Name;
    		std::vector<std::string> states;
    	}FunctionGroupConfig;


    	class MachineManifest {
        private:
            std::vector<adp::sm::internal::GroupsAndStates> allGroupsAndStates_;
            rapidjson::Document document;
        public:
            // MachineManifest();
            MachineManifest(string machineManifestPath);
            
            std::vector<adp::sm::internal::GroupsAndStates> GetAllGroupsAndStates() const noexcept;
            
            void parseMachineManifest();
            



        };
	}
}

#endif /* MACHINEMANIFEST_H_ */
