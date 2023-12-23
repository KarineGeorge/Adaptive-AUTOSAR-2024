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
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "FunctionGroup.h"
#include <deque>

namespace ara
{
	namespace exec
	{
		namespace internal
		{

//			typedef struct{
//					std::string Name;
//					std::vector<std::string> states;
//			}FunctionGroupConfig;


			class MachineManifest {
				private:
					rapidjson::Document document;
				public:
					MachineManifest(std::string machineManifestPath);
					void parseMachineManifest(std::vector<ara::exec::internal::FunctionGroup>& functionGroupConfigs);
					virtual ~MachineManifest();
			};

		}
	}
}

#endif /* MACHINEMANIFEST_H_ */
