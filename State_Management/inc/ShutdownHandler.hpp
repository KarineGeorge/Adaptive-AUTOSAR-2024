/*
 * ShutdownHandler.hpp
 *
 *  Created on: Nov 19, 2023
 *      Author: Reemoo
 */

#ifndef SHUTDOWNHANDLER_HPP_
#define SHUTDOWNHANDLER_HPP_

#include "EmFacade.hpp"
#include "other.hpp"


class ShutdownHandler
{
private:
	EmFacade& emFacade_;

public:
	//ShutdownHandler();
	ShutdownHandler(EmFacade& emFacade);
	//void Execute(const StateRequest& stateRequest);
	void SetAllFunctionGroupsToOff();


};



#endif /* SHUTDOWNHANDLER_HPP_ */