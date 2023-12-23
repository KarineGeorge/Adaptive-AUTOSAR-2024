// StateRequestBuffer.cpp
#include "../inc/StateRequestBuffer.hpp"



StateRequestBuffer::StateRequestBuffer()
    {

    }
    void StateRequestBuffer::Insert(StateRequest stateRequest) {
        std::lock_guard<std::mutex> lock(stateRequestsMutex_);
        stateRequests_.push_back(stateRequest);
    }

    void StateRequestBuffer::Insert(StateRequest stateRequest, std::uint8_t priority) {
        std::lock_guard<std::mutex> lock(priorityStateRequestsMutex_);
        priorityStateRequests_.push_back({ stateRequest, priority });
        std::sort(priorityStateRequests_.begin(), priorityStateRequests_.end(), [](const auto& a, const auto& b) {
            return a.priority > b.priority;
            });
    }

   /* std::optional<StateRequest> StateRequestBuffer::Extract() {
        std::lock_guard<std::mutex> lock(priorityStateRequestsMutex_);
        std::lock_guard<std::mutex> lock2(stateRequestsMutex_);

        if (!priorityStateRequests_.empty()) {
            StateRequest extractedRequest = priorityStateRequests_.front().stateRequest;
            priorityStateRequests_.erase(priorityStateRequests_.begin());
            return extractedRequest;
        }

        if (!stateRequests_.empty()) {
            StateRequest extractedRequest = stateRequests_.front();
            stateRequests_.erase(stateRequests_.begin());
            return extractedRequest;
        }

        return std::optional<StateRequest>{};
    }
*/
   /* std::optional<StateRequest> StateRequestBuffer::ExtractPriorities() {
        std::lock_guard<std::mutex> lock(priorityStateRequestsMutex_);

        if (!priorityStateRequests_.empty()) {
            StateRequest extractedRequest = priorityStateRequests_.front().stateRequest;
            priorityStateRequests_.erase(priorityStateRequests_.begin());
            return extractedRequest;
        }

        return std::optional<StateRequest>{};
    }
*/
    ara::core::Optional<StateRequest> StateRequestBuffer::Extract() {
        std::lock_guard<std::mutex> lock(stateRequestsMutex_);

        if (!stateRequests_.empty()) {
            StateRequest extractedRequest = stateRequests_.front();
            stateRequests_.erase(stateRequests_.begin());
            return extractedRequest;
        }

        return ara::core::Optional<StateRequest>{};
    }





