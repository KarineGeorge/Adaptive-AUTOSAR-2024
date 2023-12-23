/*
 * PipeInput.h
 *
 *  Created on: Nov 23, 2023
 *      Author: karine
 */

#ifndef PIPEINPUT_H_
#define PIPEINPUT_H_

#include <stdint.h>
#include <unistd.h>
#include <mutex>

namespace ara
{
	namespace exec
	{
		namespace internal
		{

			class PipeInput {
				private:
					int32_t writeFd;
					std::mutex pipeWriteLock;
					//std::mutex pipeThreadLock;
				public:

					PipeInput(int32_t writeFd);
					bool write(char* buffer, size_t size);
					~PipeInput();
			};
		}
	}
}

#endif /* PIPEINPUT_H_ */
