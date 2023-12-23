
#include"../inc/GroupsAndStates.hpp" 
#include"../inc/CalibirationData.hpp"

//author : shimaa rashad


namespace adp {
    namespace sm {
        namespace internal {
           
            
            
                void  GroupsAndStates:: SetGroupName(std::string Name) noexcept
                {
                    this->group_.Name = Name;
                }
                void  GroupsAndStates::SetGroupStaes(std::vector<std::string> states) noexcept
                {
                    this->group_.states = states;
                }
                void  GroupsAndStates::SetGroupStaesElement(std::string state) noexcept
                {
                    this->group_.states.push_back(state);
                }
                std::string  GroupsAndStates::GetGroupName() const noexcept
                {
                    return this->group_.Name;
                }
                std::vector<std::string>  GroupsAndStates:: GetGroupStates() const noexcept
                {
                    return this->group_.states;

                }

                void  GroupsAndStates::Deactive()
                {

                    group_.isDeactivated = true;

                }

                bool  GroupsAndStates::IsDeactivated()
                {
                    return group_.isDeactivated;
                }
            
        }
    }
}
