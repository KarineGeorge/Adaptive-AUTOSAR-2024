/*
 * StateClientImpl.h
 *
 *  Created on: Nov 26, 2023
 *      Author: tantawy
 */

#ifndef STATECLIENTIMPL_H_
#define STATECLIENTIMPL_H_

#include <queue>
#include <chrono>
#include <mutex>
#include <thread>
#include "PipeInput.h"
#include "PipeOutput.h"
#include "StateRequest.h"
#include "StateResponse.h"

#define STATE_CLIENT_READ_FD	1023
#define DEFAULT_TIMEOUT         5000

namespace ara {

	namespace exec {

		namespace internal {

			class StateClientImpl {

				private:
					PipeInput pipeInput;
					PipeOutput pipeOutput;
					std::queue<StateResponse> responses;
					std::mutex queueLock;
					std::uint8_t requestCounter;
					std::mutex pipeReaderThreadLock;
					std::thread pipeReaderThread;


					// Function: pipeReader
					// Read from the pipe and queue StateResponses
					void pipeReader(void);

					// Function: queueReader
					// Waits for and read a specific StateResponse from the queue
					void queueReader(StateResponse &stateResponse);

					// Function: queueWriter
					// Writes a StateResponse to the queue
					void queueWriter(const StateResponse &stateResponse);

				public:

					// Constructor for StateClientImpl initializes member variables
					StateClientImpl();

					// Destructor for StateClientImpl
					~StateClientImpl();

					// Function: setState
					// It sets the state by sending a state change request and waiting for the corresponding response
					// Params:
					// - request: The StateRequest object containing information about the state change request
					// Returns:
					// The status of the state change operation encapsulated in a StateResponse object.
					ara::exec::internal::StateResponse::Status setState(const StateRequest& request);

					// Function: getInitialMachineStateTransitionResult
					// Get the initial machine state transition result.
					// Returns:
					// The status of the initial machine state transition.
					ara::exec::internal::StateResponse::Status getInitialMachineStateTransitionResult();
			};

		} /* namespace internal */

	} /* namespace exec */

} /* namespace ara */

#endif /* STATECLIENTIMPL_H_ */
