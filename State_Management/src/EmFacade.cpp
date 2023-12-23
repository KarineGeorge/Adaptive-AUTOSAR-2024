#include "../inc/EmFacade.hpp"

//return result value and result error
// x caps or small

EmFacade::EmFacade()
{

}

EmFacade::EmFacade(vector<adp::sm::internal::GroupsAndStates>& groupsAndStates)
{

	for (adp::sm::internal::GroupsAndStates i : groupsAndStates)
	{
		if (i.GetGroupName() == "MachineFG")
		{
			currentStates_[i.GetGroupName()] = "";
			continue;
		}
		lock_guard<std::mutex> guard(currentStatesMutex_);
		currentStates_[i.GetGroupName()] = "shutdown";
	}


}


bool EmFacade::WaitForStartup()
{
	std::future<ara::exec::internal::StateResponse::Status> x= stateClient_.GetInitialMachineStateTransitionResult();
	
	//ara::core::Result<void> InitialStateTransitionResult = stateClient_.GetInitialMachineStateTransitionResult().GetResult();
	//ara::exec::internal::StateResponse::Status InitialStateTransitionResult = x.get();
	//ara::core::Result<ara::exec::internal::StateResponse::Status> InitialStateTransitionResult = x.get();
    
    std::future_status resultStatus;
    
	while(1){
		resultStatus = x.wait_for(std::chrono::milliseconds(50)); //e7tmal nzwd lw2t hna

		if(resultStatus == std::future_status::ready){
			if (!(int) x.get()){// process is successful
			  
			
		    lock_guard<std::mutex> guard(currentStatesMutex_);
			cout<< "sondos bt4of " << endl;
		    currentStates_["MachineFG"] = "startup";
	

			return true;

		}
		return false;
	}
     

}

}


//ara::core::Result<ara::exec::internal::StateResponse::Status>
 bool EmFacade::ChangeState(const StateRequest& stateRequest)
{
	//std::variant<ara::exec::FunctionGroup> groupResult = ara::exec::FunctionGroup::Create(stateRequest.functionGroup);
	//std::variant<ara::exec::FunctionGroupState> stateResult = ara::exec::FunctionGroupState::Create(get<ara::exec::FunctionGroup>(groupResult),
	//	stateRequest.newState);
	//ara::exec::FunctionGroupState state = std::move(get<ara::exec::FunctionGroupState>(stateResult));
	//future<ara::exec::internal::StateResponse::Status>  x = stateClient_.SetState(state);
		//ara::core::Result<ara::exec::internal::StateResponse::Status> setStateResult = x.get();
	

ara::exec::FunctionGroup functionGroup = std::get<ara::exec::FunctionGroup>(ara::exec::FunctionGroup::Create(stateRequest.functionGroup));
ara::exec::FunctionGroupState functionGroupState = std::get<ara::exec::FunctionGroupState>(ara::exec::FunctionGroupState::Create(functionGroup,stateRequest.newState));

std::future<ara::exec::internal::StateResponse::Status> responseFuture = stateClient_.SetState(functionGroupState);

std::future_status responseStatus;


while(1){
//10    
		responseStatus = responseFuture.wait_for(std::chrono::milliseconds(10));

		if(responseStatus == std::future_status::ready){
			if (!(int) responseFuture.get()){// process is successful 
				std::cout << functionGroupState.getFunctionGroupName() << ", " <<  functionGroupState.getMetaModelIdentifier() << "] Transition Status = ";
			//std::cout << (int) responseFuture.get() << std::endl;
			//update map
			std::lock_guard<std::mutex> guard(currentStatesMutex_);
		    currentStates_[string(stateRequest.functionGroup)] = stateRequest.newState;
			return true;


			}
			

		
		return false; 
		}
}
}
/*
	if (!(setStateResult.HasValue()))
	{
		const string stateChangeMessage = string(stateRequest.functionGroup) + "." + std::string(stateRequest.newState);
		//obj.setNotifier(stateChangeMessage);

		std::lock_guard<std::mutex> guard(currentStatesMutex_);
		currentStates_[string(stateRequest.functionGroup)] = stateRequest.newState;

	}

	return setStateResult;
}




ara::exec::FunctionGroup functionGroup = std::get<ara::exec::FunctionGroup>(ara::exec::FunctionGroup::Create("FG1"));
	ara::exec::FunctionGroupState functionGroupState = std::get<ara::exec::FunctionGroupState>(ara::exec::FunctionGroupState::Create(functionGroup,"sleep"));

	std::future<ara::exec::internal::StateResponse::Status> responseFuture = stateClient.SetState(functionGroupState);

	std::future_status responseStatus;

	*/

////////////////////////////////////////





string EmFacade::GetState(string  functionGroup)
{
	//std::variant<ara::exec::FunctionGroup> groupResult = ara::exec::FunctionGroup::Create(functionGroup);
	// check if a state of the FG has been set with SetState
	const auto currentStateIt = currentStates_.find(functionGroup);
	if (currentStateIt != currentStates_.cend())
	{
		return currentStateIt->second;
	}
	// there is no information about the FG state
	return "";

}
//not sure
/*void EmFacade::EnableTriggerOutService(std::shared_ptr<TriggerOutService> triggerout)
{
	 if (triggerout) // Check if the given TriggerOutService pointer is not null
			{
				if (triggerOut_ != triggerout) // Check if the given TriggerOutService pointer is different from the currently enabled TriggerOutService
				{
					if (triggerOut_) // If there is a currently enabled TriggerOutService, disable it
					{
						triggerOut_= nullptr ;
					}

					triggerOut_ = triggerout; // Enable the given TriggerOutService
					triggerOut_->InitializeService();
				}
			}

}*/

//void EmFacade::EnableDiagnosticRoutineService(std::shared_ptr<DiagnosticRoutineService> routineService)
//{



//}



vector<string> EmFacade::GetAllActiveFunctionGroups()
{
	//  currentStates_ is a map where the key is the function group and the value is the current state.

	vector<string> activeFunctionGroups;

	std::lock_guard<std::mutex> guard(currentStatesMutex_);

	for (auto& currentState : currentStates_)
	{

		if (currentState.second != "shutdown")
			activeFunctionGroups.push_back(currentState.first);
	}

	return activeFunctionGroups;

}


