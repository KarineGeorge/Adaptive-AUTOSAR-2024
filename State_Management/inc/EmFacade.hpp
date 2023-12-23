#ifndef EMFACADE_HPP_
#define EMFACADE_HPP_


#include "state_client.h"
#include "triggers.hpp"
#include "GroupsAndStates.hpp"


using namespace std;



class EmFacade
{

private:
    ara::exec::StateClient stateClient_;
    std::map<std::string, std::string> currentStates_;
    mutex currentStatesMutex_;
    //ara::core::Optional<StateRequest> OngoingStateTransition_;
    //std::mutex OngoingStateTransitionMutex_;
    std::shared_ptr<TriggerInOutService> triggerinOut_;
    std::shared_ptr<TriggerOutService> triggerOut_;
    



public:
    EmFacade();
    EmFacade(vector<adp::sm::internal::GroupsAndStates>& groupsAndStates);
    bool WaitForStartup();
    bool ChangeState(const StateRequest& stateRequest);
    string GetState(string functionGroup);
    // void EnableTriggerOutService(std::shared_ptr<TriggerOutService> triggerOut);
     //void EnableDiagnosticRoutineService(std::shared_ptr<DiagnosticRoutineService> routineService);
     //ara::core::Optional<StateRequest> GetOngoingStateTransition();
    std::vector<string> GetAllActiveFunctionGroups();
    // void SetOngoingStateTransition(const StateRequest& transition);
    // void SetNoCurrentStateTransition();
    
    ~EmFacade() noexcept = default; 


};

#endif /* EMFACADE_HPP_ */




