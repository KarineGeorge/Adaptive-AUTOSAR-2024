/*
 * SetStateResponse.h
 *
 *  Created on: Nov 26, 2023
 *      Author: tantawy
 */

#ifndef STATERESPONSE_H_
#define STATERESPONSE_H_

#include <vector>
#include <cstdint>


namespace ara{
	namespace exec{
		namespace internal{


			typedef struct{

					enum class Status: std::uint8_t{
						kSuccess = 0,
						kGeneralError = 1,
						kCommunicationError = 3,
						kMetaModelError = 4,
						kCancelled = 5,
						kFailed = 6,
						FailedUnexpectedTerminationOnEnter = 8,
						kInvalidTransition = 9,
						kAlreadyInState = 10,
						kInTransitionToSameState = 11,
						kNoTimeStamp = 12,
						kCycleOverrun = 13,
						kIntegrityOrAuthenticityCheckFailed = 14
					};

					std::uint8_t responseId;
					Status status;

			}StateResponse;

		}
	}
}



#endif /* STATERESPONSE_H_ */
