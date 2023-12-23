/*
 * StateClient.h
 *
 *  Created on: Nov 26, 2023
 *      Author: tantawy
 */

#ifndef STATE_CLIENT_H_
#define STATE_CLIENT_H_

#include <functional>
#include <cstdint>
#include <future>
#include "FunctionGroupState.h"
#include "FunctionGroup.h"
#include "StateClientImpl.h"
#include "execution_error_event.h"


namespace ara {

	namespace exec {

		class StateClient final {

			private:

				/*
				 * stateClientImpl
				 * mutable keyword is used to be modified through const functions [StateClient::SetState & StateClient::GetInitialMachineStateTransitionResult].
				 */
				mutable ara::exec::internal::StateClientImpl stateClientImpl;

				/*
				 * requestId
				 * static keyword is used to keep track of each request id.
				 */
				static std::uint8_t requestId;

			public:

				/*
				 * Constructor that creates State Client instance.
				 * Registers given callback which is called in case a Function Group changes its state unexpectedly to an Undefined Function Group State
				 */

				//To Be Done
				//explicit StateClient(std::function<void(const ExecutionErrorEvent&)> undefinedStateCallback) noexcept;
				explicit StateClient() noexcept;

				/*
				 *  Destructor of the State Client instance.
				 */
				~StateClient() noexcept;

				/*
				 * SetState()
				 * Method to request state transition for a single Function Group.
				 * This method will request Execution Management to perform state transition and return immediately.
				 * Returned ara::core::Future can be used to determine result of requested transition.
				 */
				std::future<ara::exec::internal::StateResponse::Status> SetState (const FunctionGroupState &state) const noexcept;

				/*
				 * GetInitialMachineStateTransitionResult ()
				 * Method to retrieve result of Machine State initial transition to Startup state.
				 * This method allows State Management to retrieve result of the MachineFG transition to startup state.
				 * Please note that this transition happens once per machine life cycle, thus result delivered by this method shall not change (unless machine is started again).
				 */
				std::future<ara::exec::internal::StateResponse::Status> GetInitialMachineStateTransitionResult () const noexcept;

				//To Be Done
				//std::variant<ExecutionErrorEvent> GetExecutionError (const FunctionGroup &functionGroup) noexcept;
		};

	} /* namespace exec */

} /* namespace ara */

#endif /* STATE_CLIENT_H_ */
