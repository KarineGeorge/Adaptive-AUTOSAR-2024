// headers
#include <iostream>
//#include "com/sm_interfaces/TriggerInSkeleton.h"
#include <thread>
#include "SM/inc/StateManager.hpp"
#include <chrono>



#include "Execution_Management/ExecutionManager/include/ExecutionClient.h"

// namespaces



 //global variables
 bool executing4 = true;
 Poller* poller;
 const int cTimeoutMs = 100;





int main()
{   	std::cout << "From Child Skeleton Process Main: I'm Running" << std::endl;

	ara::exec::ExecutionClient ExecutionClient;

	std::cout << "From Child Skeleton Process Main: Reporting kRunning" << std::endl;


	ExecutionClient.ReportExecutionState(ara::exec::ExecutionState::kRunning);
  

 
    
   StateManager sm;
   
   sm.CheckInitialStateTransition();
   
   
   //sm.Start();

    std::vector<std::string> fg =  sm.GetAllActiveFunctionGroups();
    for(auto x : fg){
      std::cout << x << "\n";
    }


   // Create Object from TriggerInSkeleton 
   ara::com::InstanceIdentifier id("3");
   ara::com::skelton::TriggerInSkelton mySkeleton(id);


   // Create thread using a lambda expression
   poller = new Poller();
   poller = mySkeleton.getPoller();
   std::thread t1([](){
      while(executing4)
      { 
        poller->TryPoll(cTimeoutMs);
      }
   });

   // initilize the service before offer it
    
   std::vector<uint8_t> currentValue = {47,48,49};
   auto handle = std::bind(&StateManager::process, &sm, std::placeholders::_1);
   mySkeleton.init(currentValue, handle);


   // offer the service
   std::cout << "before offering the service\n";
   mySkeleton.offerService();
   std::this_thread::sleep_for(std::chrono::seconds(2));
   std::cout << "after offering the service\n";
   sm.initialTransition();

   // Join the thread with the main thread
   std::this_thread::sleep_for(std::chrono::seconds(30));
   executing4 = false;

   t1.join();
   sm.shutDown();
   return 0;
}