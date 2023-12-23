/*
 * ExecutionClient.h
 *
 *  Created on: Nov 23, 2023
 *      Author: tantawy
 */

#ifndef ExecutionClient_H_
#define ExecutionClient_H_


#define ExecutionClient_WRITE_FD	1024

#include <stdint.h>

namespace ara
{
	namespace exec
	{

		enum class ExecutionState : uint8_t
		{
			kRunning = 0 ///< Application process performs normally
		};

		class ExecutionClient final {
		private:

		public:
			ExecutionClient() noexcept;

			~ExecutionClient() noexcept;

			void ReportExecutionState(ara::exec::ExecutionState state) const noexcept;
		};

	}
}

#endif /* ExecutionClient_H_ */
