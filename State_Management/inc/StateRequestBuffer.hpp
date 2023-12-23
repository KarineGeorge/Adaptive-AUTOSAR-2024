// StateRequestBuffer.hpp
#ifndef STATE_REQUEST_BUFFER_HPP
#define STATE_REQUEST_BUFFER_HPP

#include <vector>
#include <mutex>
#include "optional.h"
#include <memory>
#include <algorithm>

using namespace std;

    // Forward declaration of StateRequest struct
     struct StateRequest {
        std::string functionGroup;
        std::string newState;
        bool requestedByTriggerinOut;
        int maxNumberOfAttempts;
    };

    struct PriorityStateRequest {
        StateRequest stateRequest;
        std::uint8_t priority;

        // Add the comparison operator for sorting
        bool operator>(const PriorityStateRequest& other) const {
            return priority > other.priority;
        }
    };


    class StateRequestBuffer {
    public:
        StateRequestBuffer();
    

        void Insert(StateRequest stateRequest);
        void Insert(StateRequest stateRequest, std::uint8_t priority);
        ara::core::Optional<StateRequest> Extract();
       // std::optional<StateRequest> ExtractPriorities();
       // std::optional<StateRequest> ExtractDefault();

    private:
        std::vector<StateRequest> stateRequests_;
        std::vector<PriorityStateRequest> priorityStateRequests_;
        std::mutex stateRequestsMutex_;
        std::mutex priorityStateRequestsMutex_;
    };


#endif // STATE_REQUEST_BUFFER_HPP
