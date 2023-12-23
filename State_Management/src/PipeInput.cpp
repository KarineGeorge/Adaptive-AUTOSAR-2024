/*
 * PipeInput.cpp
 *
 *  Created on: Nov 23, 2023
 *      Author: karine
 */

#include "../inc/PipeInput.h"

#include <iostream>


namespace ara
{
	namespace exec
	{
		namespace internal
		{

			PipeInput::PipeInput(int32_t writeFd) {
				this->writeFd = writeFd;
			}

			bool PipeInput::write(char* buffer, size_t size){
				if(::write(writeFd, buffer, size) == -1){
					std::cout<<"pipeInput: An Error occurred with writing to the pipe\n";
					return false;
				}
				return true;
			}

			PipeInput::~PipeInput() {
				// TODO Auto-generated destructor stub
			}


		}
	}
}
