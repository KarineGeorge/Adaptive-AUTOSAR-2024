/*
 * StateClient.cpp
 *
 *  Created on: Nov 26, 2023
 *  Author: tantawy
 */

#include <thread>
#include <future>
#include "../include/StateClient.h"
#include "../include/StateClientImpl.h"

namespace ara {
    namespace exec {

		// Initialize the static member variable 'requestId' to 0
		std::uint8_t StateClient::requestId{0};

        // Constructor for StateClient
        StateClient::StateClient() noexcept
            : stateClientImpl(ara::exec::internal::StateClientImpl()) {
        }

        // Set the state asynchronously and return a future with the result
        std::future<ara::exec::internal::StateResponse::Status> StateClient::SetState(const FunctionGroupState& state) const noexcept {

        	// Use std::packaged_task to capture the result of the function
            std::packaged_task<ara::exec::internal::StateResponse::Status()> task([&] {

            	// Create a StateRequest object
                const ara::exec::internal::StateRequest stateRequest = { state.getFunctionGroupName(), state.getMetaModelIdentifier(), requestId++ };
                return stateClientImpl.setState(stateRequest);
            });

            // Get the future associated with the packaged_task
            std::future<ara::exec::internal::StateResponse::Status> result = task.get_future();

            // Launch the task asynchronously in a separate thread
            std::thread(std::move(task)).detach();

            // Return the future
            return result;
        }

        // Get the initial machine state transition result asynchronously and return a future with the result
        std::future<ara::exec::internal::StateResponse::Status> StateClient::GetInitialMachineStateTransitionResult() const noexcept {
            // Use std::packaged_task to capture the result of the function
            std::packaged_task<ara::exec::internal::StateResponse::Status()> task([&] {
                return stateClientImpl.getInitialMachineStateTransitionResult();
            });

            // Get the future associated with the packaged_task
            std::future<ara::exec::internal::StateResponse::Status> result = task.get_future();

            // Launch the task asynchronously in a separate thread
            std::thread(std::move(task)).detach();

            // Return the future
            return result;
        }

        // Destructor for StateClient
        StateClient::~StateClient() noexcept {
            // No specific cleanup needed in the destructor
        }

    } /* namespace exec */
} /* namespace ara */




