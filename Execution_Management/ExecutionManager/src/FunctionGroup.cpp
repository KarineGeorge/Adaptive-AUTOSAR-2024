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

		//		/this method shall validate/verify meta-model path passed and perform FunctionGroup object creation/
		std::variant<FunctionGroup>FunctionGroup::Create(std::string_view metaModelIdentifier) noexcept
		{
			if(!metaModelIdentifier.empty())
			{
				return std::variant<FunctionGroup>{FunctionGroup(metaModelIdentifier)};
			}
			//else part is error (to be done)
		}


		//		/To prevent problems with resource allocations during copy operation, this class is non-copyable/
		FunctionGroup::FunctionGroup(std::string_view metaModelIdentifier) noexcept
		:meta_ModelIdentifier(metaModelIdentifier)
		{}


		//		/Move constructor./
		FunctionGroup::FunctionGroup(FunctionGroup &&other) noexcept
		: meta_ModelIdentifier(std::move(other.meta_ModelIdentifier))
		{}

		//		/Move assignment operator/
		FunctionGroup& FunctionGroup::operator=(FunctionGroup&& other) noexcept
		{
			meta_ModelIdentifier = std::move(other.meta_ModelIdentifier);
			return *this;
		}

		//		/Destructor of the FunctionGroup instance/
		FunctionGroup::~FunctionGroup() noexcept{}


		//		/eq operator to cmpare with other FunctionGroup instance./
		bool FunctionGroup::operator==(const FunctionGroup &other) const noexcept{
			return meta_ModelIdentifier == other.meta_ModelIdentifier;
		}

		//		/uneq operator to compare with other FunctionGroup instance./
		bool FunctionGroup::operator!=(const FunctionGroup &other) const noexcept{
			return meta_ModelIdentifier != other.meta_ModelIdentifier;
		}

		//		/returning FunctionGroup name/
		std::string_view FunctionGroup::GetMetaModelIdentifier() const noexcept
		{
			return meta_ModelIdentifier;
		}

		namespace internal{
			const std::string FunctionGroup::kOffState("Off");

			FunctionGroup::FunctionGroup(const std::string& name, const std::vector<std::string>& states) {
				this->name = name;
				this->allStates = states;
				this->currentState = kOffState;
				this->isMachineFG = false;
			}

			const std::string& FunctionGroup::GetName() const {
				return name;
			}

			const std::vector<std::string>& FunctionGroup::GetAllStates() const {
				return allStates;
			}

			const std::string& FunctionGroup::GetCurrentStateName() const {
				return currentState;
			}


			bool FunctionGroup::StateExist(const std::string& statename)
			{
				return (statename==kOffState) || (find(allStates.begin(), allStates.end(), statename) != allStates.end());
			}


			void FunctionGroup::SetCurrentState(const std::string& statename)
			{
				if (!StateExist(statename)) {
					assert(false);
					return;
				}
				this->currentState = statename;
			}

			void FunctionGroup::AddStartupConfiguration(const std::string& statename,StartupConfiguration& StartupConfiguration)
			{
				if (!this->StateExist(statename)) {
					assert(false);
				}
				//			    	allStartupConfigurations.push_back(StartupConfiguration);
				stateStartupConfigurations[statename].push_back(StartupConfiguration); // @suppress("Method cannot be resolved")
			}

			std::vector<StartupConfiguration*> FunctionGroup::GetStartupConfigurations(const std::string& statename)
			    				{
				std::vector<StartupConfiguration*> StartupConfigurations;
				if (!StateExist(statename)) {
					assert(false);
				}
				else{
					auto it = stateStartupConfigurations.find(statename); // @suppress("Method cannot be resolved")
					if(it == stateStartupConfigurations.end()) // @suppress("Method cannot be resolved")
						std::cout <<statename << " does not have any Startup Configurations"<<std::endl ;
					else{
						for(auto& config:it->second){
							StartupConfigurations.push_back(&config);
						}

						//StartupConfigurations = it->second; // @suppress("Field cannot be resolved")
					}
				}
				return StartupConfigurations;
			    				}

			bool FunctionGroup::CheckForStartupConfiguration(StartupConfiguration& StartupConfiguration){
				//function used to know which processes to continue execution and which processes to terminate used by execution manager
				std::string currentStateName = GetCurrentStateName();
				if(currentStateName == kOffState){
					return false;
				}
				else{
					if(find(StartupConfiguration.functionGroupState.begin(),StartupConfiguration.functionGroupState.end(),currentStateName)!=StartupConfiguration.functionGroupState.end()){
						return true;
					}
					//get all startup configuration for current state search if StartupConfiguration exists then return true
					//else StartupConfiguration does not exist so return false
				}
				return false;
			}
		}
	}

}
