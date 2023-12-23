/*
 * RequestResultEvaluation.cpp
 *
 *  Created on: Nov 19, 2023
 *      Author: Reemoo
 */


#include "../inc/RequestResultEvaluation.hpp"

 

RequestResultEvaluation::RequestResultEvaluation(shared_ptr<StateRequestBuffer>& requestBuffer) : requestBuffer_(requestBuffer)
{

}


void RequestResultEvaluation::Evaluate(const StateRequest& stateRequest, const bool& changeRequestResult)

{

    if (changeRequestResult)
    {
        cout << " Evaluation omitted as request was successful. ";
        return;
    }

    if (stateRequest.maxNumberOfAttempts > 0)
    {
        cout << "Request for " << stateRequest.newState << "of" << stateRequest.functionGroup << "failed , Try Again !";
        requestBuffer_->Insert(StateRequest{
            stateRequest.functionGroup , stateRequest.newState , false ,stateRequest.maxNumberOfAttempts - 1 });
    }
}


