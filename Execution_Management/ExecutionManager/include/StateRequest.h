/*
 * SetStateRequest.h
 *
 *  Created on: Nov 26, 2023
 *      Author: tantawy
 */

#ifndef STATEREQUEST_H_
#define STATEREQUEST_H_

#include <vector>
#include <chrono>
#include <string_view>

namespace ara{
	namespace exec{
		namespace internal{

			typedef struct{

					std::string_view functionGroupName;
					std::string_view newStateName;
					std::uint8_t requestId;
			}StateRequest;

		}
	}
}


#endif /* STATEREQUEST_H_ */
