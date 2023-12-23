/*
 * Pipe.cpp
 *
 *  Created on: Nov 23, 2023
 *      Author: karine
 */

#include "../include/Pipe.h"
#include <unistd.h>
#include <iostream>

namespace ara
{
	namespace exec
	{
		namespace internal
		{

			Pipe::Pipe() {
				if(pipe(pipeFd) == -1){
					std::cout<<"EM: An error occurred with opening the pipe\n";
					return;
				}
			}

			int32_t Pipe::getReadFd(){
				return pipeFd[0];
			}

			int32_t Pipe::getWriteFd(){
				return pipeFd[1];
			}

			Pipe::~Pipe() {
				//			if(pipeFd[0]!=-1){
				//				close(pipeFd[0]);
				//			}
				//			if(pipeFd[1]!=-1){
				//				close(pipeFd[1]);
				//			}
			}

		}
	}
}
