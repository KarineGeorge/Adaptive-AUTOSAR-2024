/*
 * FunctionGroupState.h
 *
 *  Created on: Nov 28, 2023
 *      Author: atef
 */

#ifndef FUNCTIONGROUPSTATE_H_
#define FUNCTIONGROUPSTATE_H_

#include <variant>
#include <vector>
#include "FunctionGroup.h"

namespace ara{
	namespace exec{

		class FunctionGroupState
		{
		private:
			FunctionGroup function_Group;
			std::string_view meta_ModelIdentifier;

			//named constructor -> private as we use it through public functions
			FunctionGroupState(FunctionGroup &&functionGroup,std::string_view metaModelIdentifier);

		public:

			/*this method shall validate/verify meta-model path passed and perform FunctionGroupState object creation*/
			static std::variant<FunctionGroupState> Create(const FunctionGroup &functionGroup,std::string_view metaModelIdentifier) noexcept;

			/*Default constructor is deleted in favour of named constructor (Create)*/
			FunctionGroupState() = delete;

			/*To prevent problems with resource allocations during copy operation, this class is non-copyable*/
            FunctionGroupState(const FunctionGroupState &other) = delete;

            /*Move constructor.*/
            FunctionGroupState (FunctionGroupState &&other) noexcept;

            /*Copy assignment operator To prevent problems with resource allocations during copy operation, this class is non-copyable*/
            FunctionGroupState &operator= (const FunctionGroupState &other)=delete;

            /*Move assignment operator*/
            FunctionGroupState &operator= (FunctionGroupState &&other) noexcept;

            /*Destructor of the FunctionGroupState instance*/
            ~FunctionGroupState() noexcept;

            /*eq operator to compare with other FunctionGroupState instance.*/
            bool operator== (const FunctionGroupState &other) const noexcept;

            /*uneq operator to compare with other FunctionGroupstate instance.*/
            bool operator!= (const FunctionGroupState &other) const noexcept;

            /*returning FunctionGroup name*/
            std::string_view getFunctionGroupName()const;

            /*returning FunctionGroupstate name*/
            std::string_view getMetaModelIdentifier() const;
		};
	}
}


#endif /* FUNCTIONGROUPSTATE_H_ */
