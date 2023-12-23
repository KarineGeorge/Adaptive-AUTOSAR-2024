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

namespace ara{
	namespace exec{
		class PipeInput {
			private:
				int32_t writeFd;
			public:
				PipeInput(int32_t readFd);
				bool write(char* buffer, size_t size);
				~PipeInput();
		};
	}
}


#endif /* PIPEINPUT_H_ */
