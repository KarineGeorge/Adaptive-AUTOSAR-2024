/*
 * RequestResultEvaluation.hpp
 *
 *  Created on: Nov 19, 2023
 *      Author: Reemoo
 */

#ifndef REQUESTRESULTEVALUATION_HPP_
#define REQUESTRESULTEVALUATION_HPP_

#include <memory>
#include "StateRequestBuffer.hpp"
#include <iostream>
using namespace std;

class RequestResultEvaluation
{

private:
	shared_ptr<StateRequestBuffer>  requestBuffer_;

public:
	RequestResultEvaluation() = default;
	RequestResultEvaluation(shared_ptr<StateRequestBuffer>& requestBuffer);
	void Evaluate(const StateRequest& stateRequest, const bool& changeRequestResult);
	//void Evaluate(const StateRequest& stateRequest, const ara::core::Result<ara::exec::internal::StateResponse::Status>& changeRequestResult);

};
#endif /* REQUESTRESULTEVALUATION_HPP_ */