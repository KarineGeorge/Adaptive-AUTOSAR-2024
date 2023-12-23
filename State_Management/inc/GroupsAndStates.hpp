#pragma once
#include <vector>
#include <string>
#include <stdlib.h>

namespace adp {
    namespace sm {
        namespace internal {
            struct FunctionGroup {
                std::string Name;
                std::vector<std::string> states;
                bool isDeactivated = false;
            };
		
	    class GroupsAndStates {
            private:


                FunctionGroup group_;
            public:
                void SetGroupName(std::string Name) noexcept;
                
                void SetGroupStaes(std::vector<std::string> states) noexcept;
                
                void SetGroupStaesElement(std::string state) noexcept;
                
                std::string GetGroupName() const noexcept;
                
                std::vector<std::string> GetGroupStates() const noexcept;
                

                void Deactive();
                

                bool IsDeactivated();
                
            };
           
            


		}
	}
}
