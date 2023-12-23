//============================================================================
// Name        : StateClientProcess.cpp
// Author      : karine
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unistd.h>
#include "../include/ExecutionClient.h"
#include <csignal>
#include <future>
#include "../include/FunctionGroupState.h"
#include "../include/state_client.h"

/*int main() {

	std::cout << "From SM Main: I'm Running" << std::endl;

	ara::exec::ExecutionClient ExecutionClient;

	std::cout << "From SM Main: Reporting kRunning" << std::endl;

	ExecutionClient.ReportExecutionState(ara::exec::ExecutionState::kRunning);

	ara::exec::StateClient stateClient;

	std::future<ara::exec::internal::StateResponse::Status> result = stateClient.GetInitialMachineStateTransitionResult();

	std::future_status resultStatus;

	while(1){
		resultStatus = result.wait_for(std::chrono::milliseconds(50));

		if(resultStatus == std::future_status::ready){

			std::cout << "From SM Main: Initial Machine State Transition Result = ";
			std::cout << (int) result.get() << std::endl;
			break;
		}
	}


	ara::exec::FunctionGroup functionGroup = std::get<ara::exec::FunctionGroup>(ara::exec::FunctionGroup::Create("FG1"));
	ara::exec::FunctionGroupState functionGroupState = std::get<ara::exec::FunctionGroupState>(ara::exec::FunctionGroupState::Create(functionGroup,"sleep"));

	std::future<ara::exec::internal::StateResponse::Status> responseFuture = stateClient.SetState(functionGroupState);

	std::future_status responseStatus;

	while(1){

		responseStatus = responseFuture.wait_for(std::chrono::milliseconds(10));

		if(responseStatus == std::future_status::ready){

			std::cout << "From SM Main: Received Transition Response [";

			std::cout << functionGroupState.getFunctionGroupName() << ", " <<  functionGroupState.getMetaModelIdentifier() << "] Transition Status = ";
			std::cout << (int) responseFuture.get() << std::endl;
			break;
		}
	}


	while(1){

	}

}*/

/*
int main() {

	std::cout << "From SM Main: I'm Running" << std::endl;

	ara::exec::ExecutionClient ExecutionClient;

	std::cout << "From SM Main: Reporting kRunning" << std::endl;

	ExecutionClient.ReportExecutionState(ara::exec::ExecutionState::kRunning);

	ara::exec::StateClient stateClient;

	std::future<ara::exec::internal::StateResponse::Status> result = stateClient.GetInitialMachineStateTransitionResult();

	std::future_status resultStatus;

	while(1){
		resultStatus = result.wait_for(std::chrono::milliseconds(50));

		if(resultStatus == std::future_status::ready){

			std::cout << "From SM Main: Initial Machine State Transition Result = ";
			std::cout << (int) result.get() << std::endl;
			break;
		}
	}


	ara::exec::FunctionGroup FG1 = std::get<ara::exec::FunctionGroup>(ara::exec::FunctionGroup::Create("FG1"));
	ara::exec::FunctionGroup FG2 = std::get<ara::exec::FunctionGroup>(ara::exec::FunctionGroup::Create("FG2"));
	ara::exec::FunctionGroup FG3 = std::get<ara::exec::FunctionGroup>(ara::exec::FunctionGroup::Create("FG3"));

	ara::exec::FunctionGroupState FGState1 = std::get<ara::exec::FunctionGroupState>(ara::exec::FunctionGroupState::Create(FG1,"start"));
	ara::exec::FunctionGroupState FGState2 = std::get<ara::exec::FunctionGroupState>(ara::exec::FunctionGroupState::Create(FG2,"sleep"));
	ara::exec::FunctionGroupState FGState3 = std::get<ara::exec::FunctionGroupState>(ara::exec::FunctionGroupState::Create(FG3,"shutdown"));

	std::vector<ara::exec::FunctionGroupState> functionGroupStates;
	functionGroupStates.push_back(std::move(FGState1));
	functionGroupStates.push_back(std::move(FGState2));
	functionGroupStates.push_back(std::move(FGState3));

	std::vector<std::future<ara::exec::internal::StateResponse::Status>> responsesFuture;
	responsesFuture.push_back(stateClient.SetState(functionGroupStates[0]));
	responsesFuture.push_back(stateClient.SetState(functionGroupStates[1]));
	responsesFuture.push_back(stateClient.SetState(functionGroupStates[2]));

	std::future_status responsesStatus[3];
	bool flag[3] = {0,0,0};


	while(1){

		for(std::uint8_t i=0; i<3; i++){

			if(!flag[i]){
				responsesStatus[i] = responsesFuture[i].wait_for(std::chrono::milliseconds(10));


				if(responsesStatus[i] == std::future_status::ready){
					std::cout << "From SM Main: Received Transition Response [";
					std::cout << functionGroupStates[i].getFunctionGroupName() << ", " <<  functionGroupStates[i].getMetaModelIdentifier() << "] Transition Status = ";
					std::cout << (int) responsesFuture[i].get() << std::endl;
					flag[i] = true;
				}
			}

		}

	}

}
*/


int main() {

	std::cout << "From SM Main: I'm Running" << std::endl;

	ara::exec::ExecutionClient ExecutionClient;

	std::cout << "From SM Main: Reporting kRunning" << std::endl;

	ExecutionClient.ReportExecutionState(ara::exec::ExecutionState::kRunning);

	ara::exec::StateClient stateClient;

	std::future<ara::exec::internal::StateResponse::Status> result = stateClient.GetInitialMachineStateTransitionResult();

	std::future_status resultStatus;

	while(1){
		resultStatus = result.wait_for(std::chrono::milliseconds(50));

		if(resultStatus == std::future_status::ready){

			std::cout << "From SM Main: Initial Machine State Transition Result = ";
			std::cout << (int) result.get() << std::endl;
			break;
		}
	}

    //sw package 1
	ara::exec::FunctionGroup FG1 = std::get<ara::exec::FunctionGroup>(ara::exec::FunctionGroup::Create("fn1"));
	ara::exec::FunctionGroup FG2 = std::get<ara::exec::FunctionGroup>(ara::exec::FunctionGroup::Create("fn1"));
	ara::exec::FunctionGroup FG3 = std::get<ara::exec::FunctionGroup>(ara::exec::FunctionGroup::Create("fn2"));

	ara::exec::FunctionGroupState FGState1 = std::get<ara::exec::FunctionGroupState>(ara::exec::FunctionGroupState::Create(FG1,"play"));
	ara::exec::FunctionGroupState FGState2 = std::get<ara::exec::FunctionGroupState>(ara::exec::FunctionGroupState::Create(FG2,"stop"));
	ara::exec::FunctionGroupState FGState3 = std::get<ara::exec::FunctionGroupState>(ara::exec::FunctionGroupState::Create(FG3,"shutdown"));

	//sw package 2
	// ara::exec::FunctionGroup FG1 = std::get<ara::exec::FunctionGroup>(ara::exec::FunctionGroup::Create("fn1"));
	// ara::exec::FunctionGroup FG2 = std::get<ara::exec::FunctionGroup>(ara::exec::FunctionGroup::Create("fn2"));
	// ara::exec::FunctionGroup FG3 = std::get<ara::exec::FunctionGroup>(ara::exec::FunctionGroup::Create("MachineFG"));

	// ara::exec::FunctionGroupState FGState1 = std::get<ara::exec::FunctionGroupState>(ara::exec::FunctionGroupState::Create(FG1,"play"));
	// ara::exec::FunctionGroupState FGState2 = std::get<ara::exec::FunctionGroupState>(ara::exec::FunctionGroupState::Create(FG2,"stop"));
	// ara::exec::FunctionGroupState FGState3 = std::get<ara::exec::FunctionGroupState>(ara::exec::FunctionGroupState::Create(FG3,"shutdown"));

	std::vector<ara::exec::FunctionGroupState> functionGroupStates;
	functionGroupStates.push_back(std::move(FGState1));
	functionGroupStates.push_back(std::move(FGState2));
	functionGroupStates.push_back(std::move(FGState3));

	std::vector<std::future<ara::exec::internal::StateResponse::Status>> responsesFuture;
	responsesFuture.push_back(stateClient.SetState(functionGroupStates[0]));
	sleep(2);
	responsesFuture.push_back(stateClient.SetState(functionGroupStates[1]));
	responsesFuture.push_back(stateClient.SetState(functionGroupStates[2]));

	std::future_status responsesStatus[3];
	bool flag[3] = {0,0,0};
	//bool flag[2] ={0,0};

	while(1){

		for(std::uint8_t i=0; i<3; i++){

			if(!flag[i]){
				responsesStatus[i] = responsesFuture[i].wait_for(std::chrono::milliseconds(10));


				if(responsesStatus[i] == std::future_status::ready){
					std::cout << "From SM Main: Received Transition Response [";
					std::cout << functionGroupStates[i].getFunctionGroupName() << ", " <<  functionGroupStates[i].getMetaModelIdentifier() << "] Transition Status = ";
					std::cout << (int) responsesFuture[i].get() << std::endl;
					flag[i] = true;
				}
			}

		}

	}

}


