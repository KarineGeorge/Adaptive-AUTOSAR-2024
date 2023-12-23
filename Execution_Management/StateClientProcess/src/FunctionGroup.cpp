/*
 * FunctionGroup.cpp
 *
 *  Created on: Nov 23, 2023
 *      Author: georg
 */

#include "../include/FunctionGroup.h"

namespace ara
{
    namespace exec
    {

	/*this method shall validate/verify meta-model path passed and perform FunctionGroup object creation*/
    std::variant<FunctionGroup>FunctionGroup::Create(std::string_view metaModelIdentifier) noexcept
	{
		if(!metaModelIdentifier.empty())
		{
			return std::variant<FunctionGroup>{FunctionGroup(metaModelIdentifier)};
		}
		//else part is error (to be done)
	}


	/*To prevent problems with resource allocations during copy operation, this class is non-copyable*/
	FunctionGroup::FunctionGroup(std::string_view metaModelIdentifier) noexcept
	    :name(metaModelIdentifier)
	{}


	/*Move constructor.*/
	FunctionGroup::FunctionGroup(FunctionGroup &&other) noexcept
	    : name(std::move(other.name))
	{}

	/*Move assignment operator*/
	FunctionGroup& FunctionGroup::operator=(FunctionGroup&& other) noexcept
	{
		name = std::move(other.name);
	    return *this;
	}

	/*Destructor of the FunctionGroup instance*/
	FunctionGroup::~FunctionGroup() noexcept{}


	/*eq operator to compare with other FunctionGroup instance.*/
	bool FunctionGroup::operator==(const FunctionGroup &other) const noexcept{
		return name == other.name;
	}

	/*uneq operator to compare with other FunctionGroup instance.*/
	bool FunctionGroup::operator!=(const FunctionGroup &other) const noexcept{
		return name != other.name;
	}

	/*returning FunctionGroup name*/
	std::string_view FunctionGroup::GetMetaModelIdentifier() const noexcept
	{
		return name;
	}

    }

}
