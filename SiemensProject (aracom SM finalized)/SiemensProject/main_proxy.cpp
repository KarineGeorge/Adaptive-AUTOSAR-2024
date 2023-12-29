// headers
#include <iostream>
#include "SM/inc/StateManager.hpp"
#include <thread>
#include <chrono> // for delay
//#include "SM/inc/ExecutionClient.h"

#include "Execution_Management/ExecutionManager/include/ExecutionClient.h"
// namespaces
using namespace ara::com::someip::sd;
using namespace ara::com::helper;
using namespace AsyncBsdSocketLib;
using namespace ara::com;
using namespace ara::com::proxy;


// global variables
bool executing = true;
Poller* poller;
const int cTimeoutMs = 100;


int main()


{   


    
  	std::cout << "From Child Process Main: I'm Running" << std::endl;

	ara::exec::ExecutionClient ExecutionClient;

	std::cout << "From Child Process Main: Reporting kRunning" << std::endl;

	ExecutionClient.ReportExecutionState(ara::exec::ExecutionState::kRunning); 

  
    
    std::cout << "-----------------------------------------------------------\n";
    std::cout << "before finding \n";
    std::cout << "-----------------------------------------------------------\n";

    InstanceIdentifier id("3");
    auto handles = TriggerInProxy::findSerivce(id);
    
    std::cout << "-----------------------------------------------------------\n";
    std::cout << "after finding \n";
    std::cout << "-----------------------------------------------------------\n\n\n";

    if(!handles.empty())
    {
        TriggerInProxy myProxy(handles[0]);

        // Create thread using a lambda expression
        poller = handles[0].getRequester()->getPoller();
        std::thread t1([](){
            while(executing)
            {
            poller->TryPoll(cTimeoutMs);
            }
        });

        
        std::cout << "---------- subscription state before requesting subscribe ---------\n";
        myProxy.printSubscriptionState();
        // Introduce a delay of 7 seconds
        std::this_thread::sleep_for(std::chrono::seconds(10));
        
        
        std::cout << "\n\n\n----------------------- requesting subscribe ----------------------\n";
        myProxy.subscribe(256);
        while(myProxy.GetSubscriptionState() != helper::SubscriptionState::kSubscribed)
        {
            std::cout << "not subscribed yet ...\n";
        }
        
        std::cout << "subscribed\n";

        std::cout << "\n\n\n------------------------------- getter ----------------------------\n";
        std::vector<uint8_t> data;
        std::future<bool> futureObj = myProxy.getter(data);
        if(futureObj.get())
        {
            std::cout << "data received\n";
            for (int i = 0; i < data.size(); i++) {
                std::cout << static_cast<int>(data[i])  << " ";
            }
            std::cout << "\n";
        }

        std::cout << "\n\n------------------------------------\n";
        std::cout << "sleep for 10 seconds\n";
        std::cout << "---------------------------------------\n\n\n";
        // Introduce a delay of 7 seconds
        std::this_thread::sleep_for(std::chrono::seconds(10));


        std::cout << "\n\n\n------------------------------- setter ----------------------------\n";
         std::vector<uint8_t> data3 = {102, 110, 50, 46, 116, 117, 114, 110, 79, 110};
       // std::vector<uint8_t> data3 = {44,44,44};

        std::future<bool>futureObj3 = myProxy.setter(data3);
        if(futureObj3.get()) //block till request is satisfied 
        {
            std::cout << "setter function is executed\n";
        }


        std::cout << "\n\n\ntest is done\n";

        std::this_thread::sleep_for(std::chrono::seconds(30));
        executing = false;
        t1.join();
    }
    else
    {
        std::cout << "handles are empty\n";
    }

    return 0;   
}