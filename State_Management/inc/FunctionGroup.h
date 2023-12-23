/*
 * FunctionGroup.h
 *
 *  Created on: Nov 23, 2023
 *      Author: georg
 */

#ifndef FUNCTIONGROUP_H_
#define FUNCTIONGROUP_H_

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <variant>


namespace ara
{
namespace exec
{

class FunctionGroup final
{

public:
	/////////////////////////////sws/////////////////////////

	std::string_view GetMetaModelIdentifier() const noexcept;

	/*this method shall validate/verify meta-model path passed and perform FunctionGroup object creation*/
	static std::variant<FunctionGroup> Create(std::string_view metaModelIdentifier) noexcept;

	/*Default constructor is deleted in favour of named constructor (Create)*/
	FunctionGroup ()=delete;

	/*To prevent problems with resource allocations during copy operation, this class is non-copyable*/
	FunctionGroup(const FunctionGroup &other) = delete;

	/*Move constructor.*/
	FunctionGroup (FunctionGroup &&other) noexcept;

	/*Copy assignment operator To prevent problems with resource allocations during copy operation, this class is non-copyable*/
	FunctionGroup &operator= (const FunctionGroup &other)=delete;

	/*Move assignment operator*/
	FunctionGroup &operator= (FunctionGroup &&other) noexcept;

	/*Destructor of the FunctionGroup instance*/
	~FunctionGroup() noexcept;



	/*eq operator to compare with other FunctionGroup instance.*/
	bool operator== (const FunctionGroup &other) const noexcept;

	/*uneq operator to compare with other FunctionGroup instance.*/
	bool operator != (const FunctionGroup &other) const noexcept;


//////////////////////////////////////////////////////////////

private:


	//named constructor -> private as we use it through public functions
	FunctionGroup(std::string_view metaModelIdentifier) noexcept;
	std::string_view meta_ModelIdentifier;


};


}
}


#endif /* FUNCTIONGROUP_H_ */
