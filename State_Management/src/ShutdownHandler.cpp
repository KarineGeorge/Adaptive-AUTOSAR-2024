/*
 * ShutdownHandler.cpp
 *
 *  Created on: Nov 19, 2023
 *      Author: Reemoo
 */
#include "../inc/ShutdownHandler.hpp"


ShutdownHandler::ShutdownHandler(EmFacade& emFacade) : emFacade_(emFacade)
{

}

/*void ShutdownHandler::Execute(const StateRequest& stateRequest)
{
	// If the state request is a shutdown request, we call the Shutdown() method of the EmFacade.
		if ( stateRequest.newState == "shutdown")
		{
			emFacade_.ChangeState(stateRequest);
		}
		// If the state request is not a shutdown request, we ignore it.
		else
		{
			// In a real-world application, you would also handle this case appropriately,
			// for example by sending a diagnostic message or triggering an internal event.
		}

}*/



void ShutdownHandler::SetAllFunctionGroupsToOff()
{
	vector<string> functionGroups = emFacade_.GetAllActiveFunctionGroups();
	/*
		StateRequest stateRequest.insert(functionGroup, "off",false,0);
	 */
	for (string i : functionGroups)
	{
		if (i == "MachineFG") continue;
		auto stateChangeResult = emFacade_.ChangeState(StateRequest{ i, "shutdown", false , 0 });
		if (!stateChangeResult)
		{
			cout << "Change State failed ";
			return;

		}
		cout << "Successfully set Function Groups to off.\n";


	}
	emFacade_.ChangeState(StateRequest{ "MachineFG", "shutdown", false , 0 });

}



