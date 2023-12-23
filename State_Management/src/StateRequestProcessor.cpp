#include "../inc/StateRequestProcessor.hpp"

StateRequestProcessor::StateRequestProcessor(EmFacade& emFacade, shared_ptr<StateRequestBuffer>& stateRequestBuffer, vector<adp::sm::internal::GroupsAndStates>& groupsAndStates) :emFacade_(emFacade), shutdownHandler_(emFacade), stateRequestBuffer_(stateRequestBuffer),
listOfGroupsAndStates_(groupsAndStates), requestResultEvaluation_(stateRequestBuffer)
{


}

void StateRequestProcessor::ProcessStateRequest(const StateRequest& stateRequest)
{
    if (IsRequestDeclined(stateRequest))
    {
        cout << "Requested State transition of FunctionGroup  " << stateRequest.functionGroup << " is declined because this FunctionGroup is deactivated or invalid FG name or state  ";
        return;
    }

    bool changeResult = emFacade_.ChangeState(stateRequest);
    requestResultEvaluation_.Evaluate(stateRequest, changeResult);
}




bool StateRequestProcessor::IsRequestDeclined(const StateRequest& stateRequest)
{
    auto it = find_if(listOfGroupsAndStates_.begin(), listOfGroupsAndStates_.end(), [&stateRequest](const adp::sm::internal::GroupsAndStates& functiongroup)
        {
            if (stateRequest.functionGroup == functiongroup.GetGroupName())
            {
                const auto& groupStates = functiongroup.GetGroupStates();
                auto r = find(groupStates.begin(), groupStates.end(), stateRequest.newState);
                return r != groupStates.end();
            }
            return false;
        });

    if (it != listOfGroupsAndStates_.end())
    {
        return it->IsDeactivated();
    }
    return true;
}

void StateRequestProcessor::ProcessShutDown()
{
    shutdownHandler_.SetAllFunctionGroupsToOff();
}


