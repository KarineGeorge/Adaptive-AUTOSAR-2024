#include "../inc/StateManager.hpp"

//deactivate 8lllllllllllllllllt

#define calibrationDataPath "/home/liliane/SM/CalibrationData.json"
//#define MachinePath "machine_manifest.json"




EmFacade StateManager::extract(vector<adp::sm::internal::GroupsAndStates>& groupsAndStates)
{

	string machineManifestPath = "/home/liliane/Downloads/Execution_Management_Functional_Cluster-main (1)/machine_manifest.json";
	ara::exec::MachineManifest obj(machineManifestPath);
	obj.parseMachineManifest();

	listOfGroupsAndStates_ = obj.GetAllGroupsAndStates();
	return EmFacade(groupsAndStates);
}

StateManager::StateManager() :emFacade_(extract(listOfGroupsAndStates_))
{
	std::cout << "\t\t\"Initializing State Manager Application\"\n\n";
	std::cout << "parsing Machine Manifest\n";
	std::cout << "parsing Machine Manifest Done\n\n";
	stateRequestBuffer_ = make_shared<StateRequestBuffer>();/////////////
	stateRequestProcessor_ = make_shared<StateRequestProcessor>(emFacade_, stateRequestBuffer_, listOfGroupsAndStates_);





	if (!InitializeServiceInterfaces())
	{
		cout << "Initialization of service interfaces failed";
	}
	else
	{

		for (auto it = listOfGroupsAndStates_.begin(); it != listOfGroupsAndStates_.end(); it++) {
			std::cout << "\n" << "Name of function group : " << it->GetGroupName() << "\t\t\t";
			std::vector<std::string> AllStates = it->GetGroupStates();

			std::cout << "\nAll states : [";
			for (auto it2 = AllStates.begin(); it2 != AllStates.end(); it2++) {
				std::cout << (*it2) << ",";
			}
			std::cout << "]";
			cout << "\n current state :" << emFacade_.GetState(it->GetGroupName()) << "\n";
		}



		DeactivatedFunctionGroupsFromCalibrationdata();
		cout << " \n Initialization finished.\n ";

	}

}

//constructor shimaa
/*
StateManager::StateManager() {

			listOfGroupsAndStates = manf.GetAllGroupsAndStates();

			StateManager::DeactivatedFunctionGroupsFromCalibrationdata();


		}



		void StateManager::DeactivatedFunctionGroupsFromCalibrationdata()
		{
			CalibrationData CalibrationData_{calibrationDataPath};
			CalibrationData_.parseCalibrationData();
			std::vector<std::string> fGSCalibrationData = CalibrationData_.GetDeactivatedFunctionGroups();
			for (std::string fGCalibrationData : fGSCalibrationData) {
				auto it = std::find_if(listOfGroupsAndStates.begin(), listOfGroupsAndStates.end(), [&fGCalibrationData](const adp::sm::internal::GroupsAndStates& functiongroup) {
					return fGCalibrationData==functiongroup.GetGroupName();
					});
				if (it != std::end(listOfGroupsAndStates)) {
					std::cout << "deactivating this Function Group :" << it->GetGroupName() << std::endl;
					it->Deactivate();
					std::cout << "Deactivating Done. " << std::endl;

				}
			}

		}
		StateManager::~StateManager() {
			std::cout << "\n\t\t\"Initializing Finished\"\n";
		}




*/


void StateManager::Run() // extract request from stateRequestBuffer and start processing it
{

	ara::core::Optional<StateRequest> requestOptional = stateRequestBuffer_->Extract();


	if (!requestOptional.HasValue()) return;

	else {
		stateRequestProcessor_->ProcessStateRequest(*requestOptional);

	}

}

void StateManager::Start() // set MachineState to Running
{
	cout << "Set Machine State Running.";
	constexpr int kAdditionalAttempts = 0;
	auto stateChangeResult = emFacade_.ChangeState(StateRequest{ "MachineFG", "running", false , kAdditionalAttempts });
	if (!stateChangeResult)
	{
		cout << "ChangeState failed ";
		return;

	}
	cout << "Successfully set MachineState to Running.\n";

}

bool StateManager::CheckInitialStateTransition()
{
	
	bool InitialStateTransitionResult = emFacade_.WaitForStartup();
	
	cout << "reemo l 42yana ";
	if (!InitialStateTransitionResult)
	{
		cout << "Initial Machine State transition to startup state failed";
		return false;
	}

	else
	{
		cout << "Initial Machine State transition to startup state was successful .";
		return true;
	}

}

bool StateManager::InitializeServiceInterfaces()
{
	// knowing Services' IDS to be created

	ara::com::InstanceIdentifierContainer URinstanceIDS = ara::com::runtime::ResolveInstanceIDs(ara::core::InstanceSpecifier{ "update_request" });
	ara::com::InstanceIdentifierContainer TIinstanceIDS = ara::com::runtime::ResolveInstanceIDs(ara::core::InstanceSpecifier { "trigger_in" });
	ara::com::InstanceIdentifierContainer TOinstanceIDS = ara::com::runtime::ResolveInstanceIDs(ara::core::InstanceSpecifier { "trigger_out" });
	ara::com::InstanceIdentifierContainer TOIinstanceIDS =ara::com::runtime::ResolveInstanceIDs(ara::core::InstanceSpecifier { "trigger_in_out" });

    
	if (URinstanceIDS.empty() || TIinstanceIDS.empty() || TOinstanceIDS.empty())
	{
		cout << "Initialization failed";
		return false;
	}

	//creating Services
	UpdateRequestService_ = make_unique<UpdateRequestService>(URinstanceIDS[0]);
	TriggerInService_ = make_unique<TriggerInService>(TIinstanceIDS[0], stateRequestBuffer_);
	TriggerOutService_ = make_shared<TriggerOutService>(TOinstanceIDS[0]);
	TriggerInOutService_ = make_shared<TriggerInOutService>(TOinstanceIDS[0], stateRequestBuffer_);

	if (!UpdateRequestService_)
	{
		cout << "Initialization failed (failed to connect to Update Request ServiceInterface)";
		return false;
	}

	if (!TriggerInService_)
	{
		cout << "Initialization failed (failed to connect to Trigger In ServiceInterface)";
		return false;
	}

	if (!TriggerOutService_)
	{
		cout << "Initialization failed (failed to connect to Trigger Out ServiceInterface)";
		return false;
	}
    //
	//UpdateRequestService_->init();
	//TriggerInService_->init();
	//TriggerOutService_->init();
	cout << " State Management Start offering Services";
	//UpdateRequestService_->OfferService();
	//TriggerInService_->InitializeService();
	//TriggerOutService_->InitializeService();

	return true;
}

// wrong logic
void StateManager::DeactivatedFunctionGroupsFromCalibrationdata()
{
	CalibrationData CalibrationData_(calibrationDataPath);
	CalibrationData_.parseCalibrationData();
	std::vector<std::string> CalibrationData = CalibrationData_.GetDeactivatedFunctionGroups();
	std::cout << "Deactivated Function Group: ";
	std:: vector<string> groups;
	for (string calibrationData : CalibrationData)

	{
	
	
		auto it = std:: find_if(listOfGroupsAndStates_.begin(), listOfGroupsAndStates_.end(), [&calibrationData](const adp::sm::internal::GroupsAndStates& fg) 
		{
			return calibrationData== fg.GetGroupName();
		});
		if (it != end(listOfGroupsAndStates_))
		{
			cout<< "deactivating the functiongroup: " << it->GetGroupName() << endl;
			it->Deactive();
		}

	}



	
	
}



shared_ptr<StateRequestBuffer> StateManager::get()
{
	return stateRequestBuffer_;
}


vector<string> StateManager::GetAllActiveFunctionGroups()
{

	return emFacade_.GetAllActiveFunctionGroups();

}

void StateManager::shutDown()
{
	stateRequestProcessor_->ProcessShutDown();
}


//handler