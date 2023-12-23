/*
 * ExecutionClient.cpp
 *
 *  Created on: Nov 23, 2023
 *      Author: tantawy
 */

#include "../inc/ExecutionClient.h"
#include "../inc/PipeInput.h"


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
			internal::PipeInput pipe(EXECUTION_CLIENT_WRITE_FD);
			pipe.write((char*)&state, 1);
		}
    }

}


