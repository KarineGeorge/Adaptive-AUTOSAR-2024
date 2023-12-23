/*
 * ExecutionClient.cpp
 *
 *  Created on: Nov 23, 2023
 *      Author: tantawy
 */

#include "../include/ExecutionClient.h"
#include "../include/PipeInput.h"


namespace ara
{
    namespace exec
    {
		ExecutionClient::ExecutionClient() noexcept{

		}

		ExecutionClient::~ExecutionClient() noexcept{

		}

		void ExecutionClient::ReportExecutionState(ara::exec::ExecutionState state) const noexcept
		{

			ara::exec::internal::PipeInput pipeInput(ExecutionClient_WRITE_FD);
			pipeInput.write((char*)&state, 1);
		}

		bool operator==(ExecutionState lhs, ExecutionState rhs) {

			return static_cast<uint8_t>(lhs) == static_cast<uint8_t>(rhs);
		}
    }

}


