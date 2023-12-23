/*
 * FunctionGroupState.cpp
 *
 *  Created on: Nov 28, 2023
 *      Author: atef
 */
#include "../inc/FunctionGroupState.h"
#include "../inc/FunctionGroup.h"
#include <variant>

namespace ara
{
	namespace exec
	{

	/*this method shall validate/verify meta-model path passed and perform FunctionGroup object creation*/
	std::variant<FunctionGroupState> FunctionGroupState::Create(const FunctionGroup &functionGroup,std::string_view metaModelIdentifier) noexcept
	{
		if(!metaModelIdentifier.empty())
		{
			std::variant<FunctionGroup> groupResult = FunctionGroup::Create(functionGroup.GetMetaModelIdentifier());
			return std::variant<FunctionGroupState>{FunctionGroupState(std::move(std::get<FunctionGroup>(groupResult)),metaModelIdentifier)};
		}
		//else part is error (to be done)
		std::variant<FunctionGroup> groupResult = FunctionGroup::Create(functionGroup.GetMetaModelIdentifier());
		return std::variant<FunctionGroupState>{FunctionGroupState(std::move(std::get<FunctionGroup>(groupResult)),metaModelIdentifier)};
	}

	/*To prevent problems with resource allocations during copy operation, this class is non-copyable*/
    FunctionGroupState::FunctionGroupState(FunctionGroup &&functionGroup,std::string_view metaModelIdentifier):
		function_Group(std::move(functionGroup)),
		meta_ModelIdentifier(metaModelIdentifier)
    {}

    /*Move constructor.*/
    FunctionGroupState::FunctionGroupState (FunctionGroupState &&other) noexcept
    :function_Group(std::move(other.function_Group)),
	 meta_ModelIdentifier(std::move(other.meta_ModelIdentifier))
    {}

    /*Move assignment operator*/
	FunctionGroupState &FunctionGroupState::operator=(FunctionGroupState &&other) noexcept
	{
		function_Group = std::move(other.function_Group);
		meta_ModelIdentifier = std::move(other.meta_ModelIdentifier);
		return *this;
	}

	/*Destructor of the FunctionGroupState instance*/
	FunctionGroupState::~FunctionGroupState() noexcept
	{}

	/*eq operator to compare with other FunctionGroupState instance.*/
	bool FunctionGroupState::operator ==(const FunctionGroupState &other) const noexcept{
		return ((function_Group == other.function_Group) && (meta_ModelIdentifier == other.meta_ModelIdentifier));
	}

	/*uneq operator to compare with other FunctionGroupstate instance.*/
	bool FunctionGroupState::operator!= (const FunctionGroupState &other) const noexcept{
		return ((function_Group != other.function_Group) || (meta_ModelIdentifier != other.meta_ModelIdentifier));
	}

	/*returning FunctionGroup name*/
	std::string_view FunctionGroupState::getFunctionGroupName() const {
		return function_Group.GetMetaModelIdentifier();
	}

	/*returning FunctionGroupstate name*/
	std::string_view FunctionGroupState::getMetaModelIdentifier() const {
		return meta_ModelIdentifier;
	}

	}
}



