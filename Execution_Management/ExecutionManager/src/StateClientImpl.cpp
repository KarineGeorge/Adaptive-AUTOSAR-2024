/*
 * StateClientImpl.cpp
 *
 *  Created on: Nov 26, 2023
 *      Author: tantawy
 */
#include "../include/StateClientImpl.h"
#include "../include/ExecutionClient.h"
#include <iostream>
#include <thread>

namespace ara {
	namespace exec {
		namespace internal {


			StateClientImpl::StateClientImpl()
				:pipeInput(PipeInput(ExecutionClient_WRITE_FD)),
				pipeOutput(PipeOutput(STATE_CLIENT_READ_FD)),
				requestCounter(0)
				{}


			ara::exec::internal::StateResponse::Status StateClientImpl::setState(const StateRequest& request) {

				// Acquire lock before modifying thread-related variable "requestCounter"
				pipeReaderThreadLock.lock();

				// If this is the first request, start the pipeReaderThread
				if (requestCounter == 0) {
					pipeReaderThread = std::thread(&StateClientImpl::pipeReader, this);
					pipeReaderThread.detach();
				}

				// Increment the request counter and release the lock
				requestCounter++;
				pipeReaderThreadLock.unlock();

				// Prepare data to be written to the pipe
				std::uint8_t fgSize = request.functionGroupName.size() + 1;
				std::uint8_t fgsSize = request.newStateName.size() + 1;
				const char* requestFG = request.functionGroupName.data();
				const char* requestFGS = request.newStateName.data();

				// Write the request data to the pipe
				pipeInput.write((char*)&request.requestId, 1);
				pipeInput.write((char*)&fgSize, 1);
				pipeInput.write((char*)requestFG, fgSize);
				pipeInput.write((char*)&fgsSize, 1);
				pipeInput.write((char*)requestFGS, fgsSize);

				// Prepare a StateResponse object with the corresponding requestId to store the result
				StateResponse stateResponse;
				stateResponse.responseId = request.requestId;

				// Queue the StateResponse for reading
				queueReader(stateResponse);

				// Acquire lock before modifying thread-related variables
				pipeReaderThreadLock.lock();

				// Decrement the request counter
				requestCounter--;

				// If no more pending requests, terminate the pipeReaderThread
				if (requestCounter == 0) {
					pipeReaderThread.~thread();
				}

				// Release the lock
				pipeReaderThreadLock.unlock();

				// Return the status from the StateResponse
				return stateResponse.status;
			}


			ara::exec::internal::StateResponse::Status StateClientImpl::getInitialMachineStateTransitionResult() {

				ara::exec::internal::StateResponse::Status initialMachineStateTransitionResult;
				bool isEmpty = true;

				while (1) {
					// Attempt to read the result from the pipe
					if (!pipeOutput.read((char*)&initialMachineStateTransitionResult, 1, &isEmpty)) {
						std::cout << "initialMachineStateTransitionResult: Error While Reading From Pipe" << std::endl;
					}

					// If data is available, return the result
					if (!isEmpty) {
						return initialMachineStateTransitionResult;
					}
				}
			}


			void StateClientImpl::pipeReader(void) {

				StateResponse stateResponse;
				bool isEmpty = true;

				while (1) {

					// Attempt to read a StateResponse from the pipe
					if (!pipeOutput.read((char*)&stateResponse, sizeof(stateResponse), &isEmpty)) {
						std::cout << "pipeReader: Error While Reading From Pipe" << std::endl;
					}

					// If data is available, queue the StateResponse
					if (!isEmpty) {
						queueWriter(stateResponse);
						isEmpty = true;
					}
				}
			}


			void StateClientImpl::queueReader(StateResponse& stateResponse) {

				bool isReady = false;

				while (!isReady) {
					// Acquire lock before accessing the response queue
					queueLock.lock();

					// If the queue is not empty and the response ID matches, extract the StateResponse
					if (!responses.empty() && stateResponse.responseId == responses.front().responseId) {
						stateResponse.status = responses.front().status;
						responses.pop();
						isReady = true;
					}

					// Release the lock
					queueLock.unlock();
				}
			}


			void StateClientImpl::queueWriter(const StateResponse& stateResponse) {

				// Acquire lock before accessing the response queue
				queueLock.lock();

				// Push the StateResponse to the queue
				responses.push(stateResponse);

				// Release the lock
				queueLock.unlock();
			}


			StateClientImpl::~StateClientImpl() {

				// Terminate the pipeReaderThread
				pipeReaderThread.~thread();
			}

		} /* namespace internal */
	} /* namespace exec */
} /* namespace ara */
