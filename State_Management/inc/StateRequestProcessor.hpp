/*
 * StateRequestProcessor.hpp
 *
 *  Created on: Nov 19, 2023
 *      Author: Reemoo
 */

#ifndef STATEREQUESTPROCESSOR_HPP_
#define STATEREQUESTPROCESSOR_HPP_
#include "EmFacade.hpp"
#include "other.hpp"
#include "ShutdownHandler.hpp"
#include "RequestResultEvaluation.hpp"

class StateRequestProcessor
{
private:
    EmFacade& emFacade_;
    ShutdownHandler shutdownHandler_;
    shared_ptr<StateRequestBuffer> stateRequestBuffer_;
    shared_ptr<UpdateHandler> updateHandler_{};
    vector<adp::sm::internal::GroupsAndStates> listOfGroupsAndStates_;
    RequestResultEvaluation requestResultEvaluation_;
    //bool processStateRequests_;
    //mutex processStateRequestsMutex_;

public:
    StateRequestProcessor(EmFacade& emFacade, shared_ptr<StateRequestBuffer>& stateRequestBuffer, vector<adp::sm::internal::GroupsAndStates>& groupsAndStates);
    void ProcessStateRequest(const StateRequest& stateRequest);
    //void StopProcessingStateRequests();
   // void RestartProcessingStateRequests();
    bool IsRequestDeclined(const StateRequest& stateRequest);
    void ProcessShutDown();

};



#endif /* STATEREQUESTPROCESSOR_HPP_ */
