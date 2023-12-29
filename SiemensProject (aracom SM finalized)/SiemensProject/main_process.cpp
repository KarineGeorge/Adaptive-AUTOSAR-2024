#include <iostream>
#include "com/someip/DiscoveryProcess/Process.h"
#include <thread>
// for delay
#include <thread>
#include <chrono>

#include "Execution_Management/ExecutionManager/include/ExecutionClient.h"


using namespace ara::com::someip::sd;
using namespace ara::com::helper;
using namespace AsyncBsdSocketLib;


const std::string cAnyIpAddress{"0.0.0.0"};
const std::string cNicIpAddress{"127.0.0.1"};
const std::string cMulticastGroup{"239.0.0.1"};
const uint16_t cOfferingPort{5555};
const uint16_t cFindingPort{6666};
const int cTimeoutMs = 100;
bool executing = true ;

int main()
{  

     std::cout << "From Child Process Main: I'm Running" << std::endl;

	  ara::exec::ExecutionClient ExecutionClient;

	  std::cout << "From Child Process Main: Reporting kRunning" << std::endl;

	ExecutionClient.ReportExecutionState(ara::exec::ExecutionState::kRunning);

    Poller* poller;
    poller = new Poller();
    

    ServiceDiscoveryProcess *process;
    process = new ServiceDiscoveryProcess(poller,cNicIpAddress,cMulticastGroup,cOfferingPort,cFindingPort);


    process->printRegistry();


    // Create thread using a lambda expression
    std::thread t1([poller](){
       while(executing)
       {
         poller->TryPoll(cTimeoutMs);
       }
    });

    
    // Join the thread with the main thread
    std::this_thread::sleep_for(std::chrono::seconds(30));
   executing = false;
    t1.join();

   delete poller;
   return 0;
}