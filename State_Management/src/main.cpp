/*
 * main.cpp
 *
 * Created on: Dec 5, 2023
 * Author: Reemoo
 */





///instance specifier shahhhd
#include "../inc/other.hpp"
#include "../inc/StateManager.hpp"
#include "../inc/ExecutionClient.h"
#include "../inc/PipeInput.h"
#include "../inc/instance_id.h"
#include "../inc/instance_specifier.h"

//name space add 
//deactivate modify
//test mu7trm b3d el integerate
int main() {
    //ara::exec::internal::StateResponse::Status result = ara::exec::internal::StateResponse::Status::kSuccess;
    //ara::exec::internal::PipeInput input; 


    StateManager sm;
    //create obj of each skeleton
   //ara::com::InstanceIdentifier iden;

   
   // TriggerInOutSkeleton inout{iden};
  

    //sm.Start();

    
    ara::exec::ExecutionClient executionclient ;
    executionclient.ReportExecutionState(ara::exec::ExecutionState::kRunning);
    
    //demo 
    //app setter(); in proxy
    //server proccssing (nnady l run ) binding from sm
    // server update skeleton
    //app getter  proxy


    //sm.Start();
  cout << sm.CheckInitialStateTransition();
    /*sm.Start();

    //Create a StateRequestBuffer
    std::shared_ptr<StateRequestBuffer> stateRequestBuffer = sm.get(); // till skeleton is done by aracom

    // Create an instance of TriggerInOutService
    int instanceId = 7;
    TriggerInOutService triggerInOutService(instanceId, stateRequestBuffer);

    // Call the SetTrigger method with a test transition string
    std::string testTransition = "fn1.play";
    ara::core::future resultFuture = triggerInOutService.SetTrigger(testTransition);

    // Wait for the future to be ready (assuming it might be an async operation)
    resultFuture.wait();
    sm.Run();
    std::vector<std::string> activeGroups = sm.GetAllActiveFunctionGroups();
    // Print the results in the console
    std::cout << "Active Function Groups:" << std::endl;
    for (string& group : activeGroups) {
        std::cout << group << std::endl;
    }
    sm.shutDown();
    activeGroups = sm.GetAllActiveFunctionGroups();
    // Print the results in the console
    std::cout << "Active Function Groups:" << std::endl;
    for (string& group : activeGroups) {
        std::cout << group << std::endl;
    }*/
    while(1){}
   return 0;

}
/*
sm.Run();
sm.Run();

        sm.shutDown();
       // sm.GetAllActiveFunctionGroups();
         std::vector<std::string> activeGroups = sm.GetAllActiveFunctionGroups();
        // Print the results in the console
std::cout << "Active Function Groups:" << std::endl;
for (string& group : activeGroups) {
    std::cout << group << std::endl;
} */

// sm.GetAllActiveFunctionGroups();

            // Call the SetTrigger method with a test transition string
          //  std::string testTransition = "fn2.turnOff";//off lw error 

          // ara::core::future resultFuture = triggerInOutService.SetTrigger(testTransition);


