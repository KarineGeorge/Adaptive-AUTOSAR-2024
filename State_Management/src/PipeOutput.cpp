/*
 * PipeOutput.cpp
 *
 *  Created on: Nov 23, 2023
 *      Author: karine
 */

#include "../inc/PipeOutput.h"

#include <iostream>
#include <fcntl.h>


namespace ara
{
	namespace exec
	{
		namespace internal
		{

			PipeOutput::PipeOutput(int32_t readFd) {
				this->readFd = readFd;
				fcntl(readFd, F_SETFL, O_NONBLOCK);
			}

			bool PipeOutput::read(char* buffer, size_t size, bool* isEmpty){
				if(::read(readFd, buffer, size) == -1){
					if(errno == EAGAIN){
						*isEmpty = true;
						return true;
					}
					std::cout<<"PipeOutput: An Error occurred with reading from the pipe\n";
					return false;
				}
				*isEmpty = false;
				return true;
			}

			PipeOutput::~PipeOutput() {
				// TODO Auto-generated destructor stub
			}


		}
	}
}


