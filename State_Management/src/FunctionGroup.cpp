/*
 * FunctionGroup.cpp
 *
 *  Created on: Nov 23, 2023
 *      Author: georg
 */

#include "../inc/FunctionGroup.h"

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
		return std::variant<FunctionGroup>{FunctionGroup(metaModelIdentifier)};
	}


	/*To prevent problems with resource allocations during copy operation, this class is non-copyable*/
	FunctionGroup::FunctionGroup(std::string_view metaModelIdentifier) noexcept
	    :meta_ModelIdentifier(metaModelIdentifier)
	{}


	/*Move constructor.*/
	FunctionGroup::FunctionGroup(FunctionGroup &&other) noexcept
	    : meta_ModelIdentifier(std::move(other.meta_ModelIdentifier))
	{}

	/*Move assignment operator*/
	FunctionGroup& FunctionGroup::operator=(FunctionGroup&& other) noexcept
	{
		meta_ModelIdentifier = std::move(other.meta_ModelIdentifier);
	    return *this;
	}

	/*Destructor of the FunctionGroup instance*/
	FunctionGroup::~FunctionGroup() noexcept{}


	/*eq operator to compare with other FunctionGroup instance.*/
	bool FunctionGroup::operator==(const FunctionGroup &other) const noexcept{
		return meta_ModelIdentifier == other.meta_ModelIdentifier;
	}

	/*uneq operator to compare with other FunctionGroup instance.*/
	bool FunctionGroup::operator!=(const FunctionGroup &other) const noexcept{
		return meta_ModelIdentifier != other.meta_ModelIdentifier;
	}

	/*returning FunctionGroup name*/
	std::string_view FunctionGroup::GetMetaModelIdentifier() const noexcept
	{
		return meta_ModelIdentifier;
	}

    }

}
