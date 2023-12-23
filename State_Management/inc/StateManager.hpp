

#ifndef STATEMANAGER_HPP_
#define STATEMANAGER_HPP_


#include "EmFacade.hpp"
#include "StateRequestProcessor.hpp"
#include "other.hpp"
#include "triggers.hpp"
#include "GroupsAndStates.hpp"
#include "CalibirationData.hpp"
#include "MachineManifest.h"
#include "StateRequestBuffer.hpp"
#include "instance_id.h"

class StateManager
{

private:
    shared_ptr<StateRequestBuffer> stateRequestBuffer_;
    shared_ptr<StateRequestProcessor> stateRequestProcessor_;
    shared_ptr<UpdateHandler> updateHandler_;
    unique_ptr<TriggerInService> TriggerInService_;
    shared_ptr<TriggerOutService> TriggerOutService_;
    shared_ptr<TriggerInOutService> TriggerInOutService_;
    shared_ptr<DiagnosticRoutineService> diagnosticRoutine_;
    unique_ptr<UpdateRequestService> UpdateRequestService_;
    vector<adp::sm::internal::GroupsAndStates> listOfGroupsAndStates_;
    EmFacade emFacade_;


public:
    StateManager();
    void Run();
    void Start();
    bool CheckInitialStateTransition();
    bool InitializeServiceInterfaces();
    void DeactivatedFunctionGroupsFromCalibrationdata();
    EmFacade extract(vector<adp::sm::internal::GroupsAndStates>& groupsAndStates);
    shared_ptr<StateRequestBuffer> get();


    vector<string> GetAllActiveFunctionGroups();
    void shutDown();
    ~StateManager() noexcept = default;

    
};

#endif /* STATEMANAGER_HPP_ */
