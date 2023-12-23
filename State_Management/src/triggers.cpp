
#include "../inc/triggers.hpp"





    TriggerOutService::TriggerOutService(ara::com::InstanceIdentifier& instance_id): TriggerOutSkeleton(instance_id) {}
    

    void TriggerOutService::InitializeService() {}





    



//////////////////




     TriggerOutSkeleton::TriggerOutSkeleton(ara::com::InstanceIdentifier  instance_id)
   {}

 void TriggerOutSkeleton::Set(std::shared_ptr<TriggerOutSkeleton> self){}

////////////////


   TriggerInOutSkeleton::TriggerInOutSkeleton(ara::com::InstanceIdentifier  instance_id,
   std::shared_ptr<StateRequestBuffer> stateRequestBuffer)
   {}

 void TriggerInOutSkeleton::Set(std::shared_ptr<TriggerInOutSkeleton> self){}

//////////////////


  TriggerInSkeleton::TriggerInSkeleton(ara::com::InstanceIdentifier  instance_id, std::shared_ptr<StateRequestBuffer> stateRequestBuffer) {}

 void TriggerInSkeleton:: Set(std::shared_ptr<TriggerInSkeleton> self) {}


////////////////////////////

  TriggerInOutService:: TriggerInOutService(ara::com::InstanceIdentifier& instance_id, std::shared_ptr<StateRequestBuffer> stateRequestBuffer) 
  :TriggerInOutSkeleton(instance_id, stateRequestBuffer), stateRequestBuffer_{ stateRequestBuffer } {
    }


    void TriggerInOutService::SetTrigger(const std::string& transition)
    
    {

        std::cout << "request is ongoing by trigger in out  service \n";

        // structure of two strings split by"."

        // structure of two strings split by"."
        // assume request is in the form  XFG.transitionState
        std::vector<std::string> processedTransition = splitStateTransitionString(transition);

        constexpr std::size_t kExpectedLength = 2;  // FunctionGroup and FunctionGroupState

        if (processedTransition.size() == kExpectedLength) {
            constexpr std::size_t kFgNameIndex = 0;
            constexpr std::size_t kFgStateIndex = 1;


            // Create a StateRequest structure with parsed FG_Name and FG_State
            StateRequest stateRequest{
                processedTransition[kFgNameIndex],
                processedTransition[kFgStateIndex],
                false, // sets the requestedByTriggerinOut field of the stateRequest structure to false
               3 //sets the maxNumberOfAttempts field of the stateRequest structure
            };
            // Store the parsed FG_Name and FG_State in the StateRequestBuffer to be processed later


            stateRequestBuffer_->Insert(stateRequest);



        }
        else {
            std::cout << "Invalid parameter for state transition.";
            ////ara::core::promise<std::string> promise;
             //  promise.set_value(transition);
               //return promise.get_future();
        }
        
    }

    void TriggerInOutService:: InitializeService() {


        std::cout << "TriggerinService is initializing...\n";
        //  any other initialization logic if there's


    }


    std::vector<std::string> TriggerInOutService:: splitStateTransitionString(const std::string& state_transition_string) {
        std::vector<std::string> split_string;
        std::stringstream ss(state_transition_string);
        std::string token;
        while (std::getline(ss, token, '.')) {
            split_string.push_back(token);
        }
        return split_string;
    }

    //handler function
     // Using std::bind to bind the member function to an object
    //auto boundFunction = std::bind(&MyClass::PrintMessage, &myObject, std::placeholders::_1);



/////////////////////////////////////////////////

   TriggerInService:: TriggerInService(ara::com::InstanceIdentifier& instance_id, std::shared_ptr<StateRequestBuffer> stateRequestBuffer) :TriggerInSkeleton(instance_id, stateRequestBuffer), stateRequestBuffer_{ stateRequestBuffer } {
    }

    std::vector<std::string> TriggerInService ::splitStateTransitionString(const std::string& transition)
    {
        std::vector<std::string> split_string;
        std::stringstream ss(transition);
        std::string token;
        while (std::getline(ss, token, '.')) {
            split_string.push_back(token);
        }
        return split_string;
    }

    void TriggerInService:: setTrigger(const std::string& transition)
    {

        std::cout << "request is ongoing by trigger in service \n";

        // structure of two strings split by"."
        // assume request is in the form  XFG.transitionState
        std::vector<std::string> processedTransition = splitStateTransitionString(transition);

        constexpr std::size_t kExpectedLength = 2;  // FunctionGroup and FunctionGroupState

        if (processedTransition.size() == kExpectedLength) {
            constexpr std::size_t kFgNameIndex = 0;
            constexpr std::size_t kFgStateIndex = 1;


            // Create a StateRequest structure with parsed FG_Name and FG_State
            StateRequest stateRequest{
                processedTransition[kFgNameIndex],
                processedTransition[kFgStateIndex],
                false, // sets the requestedByTriggerinOut field of the stateRequest structure to false
                3 //sets the maxNumberOfAttempts field of the stateRequest structure
            };
            // Store the parsed FG_Name and FG_State in the StateRequestBuffer to be processed later

            TriggerInService::stateRequestBuffer_->Insert(stateRequest);





        }
        else {
            std::cout << "Invalid parameter for state transition.";
            ////ara::core::promise<std::string> promise;
             //  promise.set_value(transition);
               //return promise.get_future();
        }
    }

    void TriggerInService:: InitializeService()
    {


        std::cout << "TriggerinService is initializing...\n";
        //  any other initialization logic if there's


    }

