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
			PipeInput pipe(ExecutionClient_WRITE_FD);
			pipe.write((char*)&state, 1);
		}
    }

}


