/*
 * FunctionGroup.h
 *
 *  Created on: Nov 23, 2023
 *      Author: georg
 */

#ifndef FUNCTIONGROUP_H_
#define FUNCTIONGROUP_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <variant>
#include "StartupConfiguration.h"
#include "StateStartupConfiguration.h"

namespace ara
{
	namespace exec
	{
		namespace internal{

			class FunctionGroup{
				public:
			    	//constructor
			    	FunctionGroup(const std::string& name, const std::vector<std::string>& states);
			    	FunctionGroup();
			    	// Member functions
			    	void Create();

			    	// Getter functions
			    	const std::string& GetName() const;
			    	const std::string& GetCurrentStateName() const;
			    	const std::vector<std::string>& GetAllStates() const;
			    	std::vector<StartupConfiguration*> GetStartupConfigurations(const std::string& statename);
			    	ara::exec::internal::StateStartupConfiguration GetStateStartupConfigurations(const std::string& statename);
			    	void AddStartupConfiguration(const std::string& statename,StartupConfiguration& StartupConfiguration);
			    	bool CheckForStartupConfiguration(StartupConfiguration& StartupConfiguration);
			    	bool IsMachineFG() const;
			    	bool StateExist(const std::string& statename);
			    	void SetCurrentState(const std::string& statename);

				private:
			    	// Member variables
			    	std::string name;
			    	std::vector<std::string> allStates;
			    	std::string currentState;
			//    	std::vector<FunctionGroupState> functionGroupStates;
			//    	FunctionGroupState currentState;
			    	std::map<std::string, std::vector<StartupConfiguration>> stateStartupConfigurations; // @suppress("Invalid template argument")
//			    	std::vector<StartupConfiguration> allStartupConfigurations;
			    	bool isMachineFG;
			    	static const std::string kOffState;
			};
		}

		class FunctionGroup final
		{

			public:
				/////////////////////////////sws/////////////////////////

				std::string_view GetMetaModelIdentifier() const noexcept;

//				/this method shall validate/verify meta-model path passed and perform FunctionGroup object creation/
				static std::variant<FunctionGroup> Create(std::string_view metaModelIdentifier) noexcept;

//				/Default constru/ctor is deleted in favour of named constructor (Create)/
				FunctionGroup ()=delete;

//				/To prevent problems with resource allocations during copy operation, this class is non-copyable/
				FunctionGroup(const FunctionGroup &other) = delete;

//				/Move constructor./
				FunctionGroup (FunctionGroup &&other) noexcept;

//				/Copy assignment operator To prevent problems with resource allocations during copy operation, this class is non-copyable/
				FunctionGroup &operator= (const FunctionGroup &other)=delete;

//				/Move assignment operator/
				FunctionGroup &operator= (FunctionGroup &&other) noexcept;

//				/Destructor of the FunctionGroup instance/
				~FunctionGroup() noexcept;



//				/eq operator to compare with other FunctionGroup instance./
				bool operator== (const FunctionGroup &other) const noexcept;

//				/uneq operator to compare with other FunctionGroup instance./
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

