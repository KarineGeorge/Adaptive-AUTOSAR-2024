/*
 * GetStateResponse.h
 *
 *  Created on: Nov 26, 2023
 *      Author: tantawy
 */

#ifndef GETSTATERESPONSE_H_
#define GETSTATERESPONSE_H_

#include <string>
#include <cstdint>

namespace ara{
	namespace exec{
		namespace internal{

			typedef struct{

				enum class Status: std::uint8_t{

					kSuccess,
					kTransition,
					kStateFailed,
					kTransitionFailed,
					kTimeout,
					kInvalidRequest,
					kNotInvokedByStateManagement


				};

				Status status;
				std::string currentState;

			}GetStateReponse;



		}
	}
}


#endif /* GETSTATERESPONSE_H_ */
