
#ifndef TRIGGERS_HPP_
#define TRIGGERS_HPP_

#include <memory>
#include <vector>

#include <mutex>

#include <string>
#include <iostream>

#include <sstream>

#include "instance_id.h"



#include <variant>
#include "StateRequestBuffer.hpp"

using namespace std;



//////////////////

class TriggerOutSkeleton {
public:
    TriggerOutSkeleton(ara::com::InstanceIdentifier  instance_id);

    void Set(std::shared_ptr<TriggerOutSkeleton> self);
};


/////////////////

class TriggerOutService : public TriggerOutSkeleton {
private:


public:
    TriggerOutService(ara::com::InstanceIdentifier& instance_id);
    

    void InitializeService();


};


////////////////////////////////




class TriggerInOutSkeleton {
public:
    TriggerInOutSkeleton(ara::com::InstanceIdentifier  instance_id,
        std::shared_ptr<StateRequestBuffer> stateRequestBuffer);
    

    void Set(std::shared_ptr<TriggerInOutSkeleton> self);
};
class TriggerInSkeleton {
public:
    TriggerInSkeleton(ara::com::InstanceIdentifier  instance_id, std::shared_ptr<StateRequestBuffer> stateRequestBuffer);

    void Set(std::shared_ptr<TriggerInSkeleton> self);
};

/////////////////////// 

//htt3ddddddddddddddl l in out hna w hnak
class TriggerInOutService : public TriggerInOutSkeleton {///, public ara::com::skelton::TriggerOutSkelton {
private:
    std::shared_ptr<StateRequestBuffer> stateRequestBuffer_;


public:
    TriggerInOutService(ara::com::InstanceIdentifier& instance_id, std::shared_ptr<StateRequestBuffer> stateRequestBuffer);

    void SetTrigger(const std::string& transition);
    
    void InitializeService();


    std::vector<std::string> splitStateTransitionString(const std::string& state_transition_string); 
    //handler function
     // Using std::bind to bind the member function to an object
    //auto boundFunction = std::bind(&MyClass::PrintMessage, &myObject, std::placeholders::_1);


};

////////////////////////////////////////////

class TriggerInService : public TriggerInSkeleton {
private:
    std::shared_ptr<StateRequestBuffer> stateRequestBuffer_;
    //std::future<apd::sm::FGStateTransition> fg_state_transition_future;

public:
    TriggerInService(ara::com::InstanceIdentifier& instance_id, std::shared_ptr<StateRequestBuffer> stateRequestBuffer) ;
    
    

    std::vector<std::string> splitStateTransitionString(const std::string& transition);
    
    void setTrigger(const std::string& transition);
    void InitializeService();
    


};
#endif
