//============================================================================
// Name        : ExecutionClientProcess.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unistd.h>
#include "../include/ExecutionClient.h"
#include <csignal>


int main() {

	std::cout << "From Child Process Main: I'm Running" << std::endl;

	ara::exec::ExecutionClient ExecutionClient;

	std::cout << "From Child Process Main: Reporting kRunning" << std::endl;

	ExecutionClient.ReportExecutionState(ara::exec::ExecutionState::kRunning);


	while(1){

		std::cout << "From Child Process Main: Working" << std::endl;
		sleep(1);
	}

	return 0;
}


/*int main() {

	std::cout << "From Child Process Main: I'm Running" << std::endl;

	ara::exec::ExecutionClient ExecutionClient;

	std::cout << "From Child Process Main: Will Not Report kRunning" << std::endl;


	while(1){

		std::cout << "From Child Process Main: Working" << std::endl;
		sleep(1);
	}

	return 0;
}*/


/*int main() {

	std::cout << "From Child Process Main: I'm Running" << std::endl;

	ara::exec::ExecutionClient ExecutionClient;

	std::cout << "From Child Process Main: Reporting kRunning" << std::endl;

	ExecutionClient.ReportExecutionState(ara::exec::ExecutionState::kRunning);


	std::cout << "From Child Process Main: Will Ignore SIGTERM" << std::endl;

	signal(SIGTERM, SIG_IGN);

	while(1){

		std::cout << "From Child Process Main: Working" << std::endl;
		sleep(1);
	}

	return 0;
}*/

