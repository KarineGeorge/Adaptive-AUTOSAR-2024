/*
 * Pipe.h
 *
 *  Created on: Nov 23, 2023
 *      Author: karine
 */

#ifndef PIPE_H_
#define PIPE_H_

#include <stdint.h>


namespace ara
{
	namespace exec
	{
		namespace internal
		{

			class Pipe {
				private:
					int32_t pipeFd[2];
				public:
					Pipe();
					~Pipe();
					int32_t getReadFd();
					int32_t getWriteFd();
			};
		}
	}
}

#endif /* PIPE_H_ */
