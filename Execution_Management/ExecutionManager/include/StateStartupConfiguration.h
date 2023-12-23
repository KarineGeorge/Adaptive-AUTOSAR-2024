/*
 * StateStartupConfiguration.h
 *
 *  Created on: Nov 28, 2023
 *      Author: karine
 */

#ifndef STATESTARTUPCONFIGURATION_H_
#define STATESTARTUPCONFIGURATION_H_

#include "StartupConfiguration.h"
#include "Pipe.h"
#include "PipeInput.h"
#include "StateClientImpl.h"

namespace ara {
	namespace exec {
		namespace internal {

			class StateStartupConfiguration : public StartupConfiguration {
				private:
					Pipe EmInSmOut;
				public:


					PipeInput pipeInput;
					StateStartupConfiguration(Executable executable, ProcessConfig processConfig, bool isFunctionalClusterProcess, bool isStateClientProcess);
					void readRequest(StateRequest &stateRequest);
					virtual ~StateStartupConfiguration();
					bool start();

			};

		} /* namespace internal */
	} /* namespace exec */
} /* namespace ara */

#endif /* STATESTARTUPCONFIGURATION_H_ */
