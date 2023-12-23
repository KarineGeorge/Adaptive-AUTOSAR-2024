/*
 * PipeOutput.h
 *
 *  Created on: Nov 23, 2023
 *      Author: karine
 */

#ifndef PIPEOUTPUT_H_
#define PIPEOUTPUT_H_


#include <stdint.h>
#include <unistd.h>


namespace ara
{
	namespace exec
	{
		namespace internal
		{

			class PipeOutput {
				private:
					uint32_t readFd;

				public:
					
					PipeOutput(int32_t readFd);
					bool read(char* buffer, size_t size, bool* isEmpty);
					~PipeOutput();
			};

		}
	}
}

#endif /* PIPEOUTPUT_H_ */


