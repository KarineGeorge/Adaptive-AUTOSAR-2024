/*
 * execution_error_event.h
 *
 *  Created on: Nov 26, 2023
 *      Author: tantawy
 */

#ifndef EXECUTION_ERROR_EVENT_H_
#define EXECUTION_ERROR_EVENT_H_

#include <cstdint>
#include <string_view>

namespace ara{
	namespace exec{


//		To do
//		enum class ExecErrc : ara::core::ErrorDomain::CodeType {
//
//			kGeneralError = 1,
//			kCommunicationError = 3,
//			kMetaModelError = 4,
//			kCancelled = 5,
//			kFailed = 6,
//			FailedUnexpectedTerminationOnEnter = 8,
//			kInvalidTransition = 9,
//			kAlreadyInState = 10,
//			kInTransitionToSameState = 11,
//			kNoTimeStamp = 12,
//			kCycleOverrun = 13,
//			kIntegrityOrAuthenticityCheckFailed = 14
//		};

		enum class ExecErrc : std::int32_t {

			kGeneralError = 1,
			kCommunicationError = 3,
			//kMetaModelError = 4,
			kCancelled = 5,
			kFailed = 6,
			FailedUnexpectedTerminationOnEnter = 8,
			kInvalidTransition = 9,
			kAlreadyInState = 10,
			kInTransitionToSameState = 11,
			//kNoTimeStamp = 12,
			//kCycleOverrun = 13,
			kIntegrityOrAuthenticityCheckFailed = 14
		};

		using ExecutionError = std::uint32_t;

		struct ExecutionErrorEvent final{

				ExecutionError executionError;

				std::string_view functionGroup;
		};
	}
}



#endif /* EXECUTION_ERROR_EVENT_H_ */
