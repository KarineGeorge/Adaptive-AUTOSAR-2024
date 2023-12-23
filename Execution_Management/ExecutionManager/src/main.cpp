
#include "../include/ExecutionManager.h"
#include <thread>
using namespace std;
using namespace ara::exec::internal;

int main(int argc, char* argv[])
{
	// if (argc != 2)
	// {
	// 	std::cout << "Error passing arguments to execution managment process" << std::endl;
	// 	return 0;
	// }

	// std::string rootPath = (std::string)argv[1];
	
	
	ara::exec::internal::ExecutionManager EM;
	EM.extractMachineManifest();
	EM.extractSWPackages();
	EM.extractExecutionManifests();
	EM.initialMachineTransition();

	std::vector<std::pair<StateRequest,std::reference_wrapper<std::thread>>> requests;
	std::vector<std::reference_wrapper<bool>> threadIsRunning;
	std::vector<std::reference_wrapper<std::mutex>> threadIsRunningLock;
	std::vector<std::reference_wrapper<bool>> threadIsCancelled;
	std::vector<std::reference_wrapper<std::mutex>> threadIsCancelledLock;

	while (1)
	{

		StateRequest request;
		EM.stateManagementProcess.readRequest(request);

		if (request.functionGroupName == "MachineFG" && request.newStateName == "shutdown")
		{
			bool flag = false;
			for (size_t i = 0; i < requests.size(); i++)
			{
				threadIsRunningLock[i].get().lock();
				if (threadIsRunning[i])
				{
					threadIsRunningLock[i].get().unlock();

					flag = true;
					break;
				}
				else
				{
					threadIsRunningLock[i].get().unlock();
				}
			}

			if (flag)
			{
				cout << "There is a running thread" << endl;
				ara::exec::internal::StateResponse stateResponse = {request.requestId, ara::exec::internal::StateResponse::Status::kFailed};
				EM.stateManagementProcess.pipeInput.write((char *)&stateResponse, sizeof(stateResponse));
			}
			else
			{

				ara::exec::internal::StateResponse stateResponse = {request.requestId, ara::exec::internal::StateResponse::Status::kSuccess};
				EM.stateManagementProcess.pipeInput.write((char *)&stateResponse, sizeof(stateResponse));

				if (!EM.stateManagementProcess.isTerminated())
				{
					EM.stateManagementProcess.term();
				}
				while (!EM.stateManagementProcess.isTerminated())
				{
					std::cout << "From EM Main: Terminating Child SM" << std::endl;
					sleep(1);

					if (EM.stateManagementProcess.exitTimeoutExpired())
					{

						std::cout << "From EM Main: Terminating Child Timeout" << std::endl;

						std::cout << "From EM Main: Killing Child" << std::endl;

						EM.stateManagementProcess.kill();

						std::cout << "From EM Main: Child Killed" << std::endl;

						sleep(1);
						std::cout << "From EM Main: timeout" << std::endl;
					}
				}

				std::cout << "From EM Main: SM Terminated" << std::endl;
				return 0;
			}
		}
		else
		{
			bool isvalid = true;
			ara::exec::internal::StateResponse::Status temp = EM.validate(isvalid, request.functionGroupName, request.newStateName);

			if (!isvalid)
			{
				ara::exec::internal::StateResponse stateResponse = {request.requestId, temp};
				EM.stateManagementProcess.pipeInput.write((char *)&stateResponse, sizeof(stateResponse));
			}
			else
			{

				for (size_t i = 0; i < requests.size(); i++)
				{

					if (requests[i].first.functionGroupName == request.functionGroupName)
					{

						threadIsRunningLock[i].get().lock();
						if (threadIsRunning[i])
						{

							threadIsRunningLock[i].get().unlock();

							threadIsCancelledLock[i].get().lock();
							threadIsCancelled[i].get() = true;
							threadIsCancelledLock[i].get().unlock();

							threadIsRunningLock[i].get().lock();
							while (threadIsRunning[i]){}
							threadIsRunningLock[i].get().unlock();

							ara::exec::internal::StateResponse stateResponse = {requests[i].first.requestId, ara::exec::internal::StateResponse::Status::kCancelled};
							EM.stateManagementProcess.pipeInput.write((char *)&stateResponse, sizeof(stateResponse));
						}
						else
						{
							threadIsRunningLock[i].get().unlock();
						}

						requests.erase(requests.begin() + i);
						threadIsRunning.erase(threadIsRunning.begin() + i);
						threadIsRunningLock.erase(threadIsRunningLock.begin() + i);
						threadIsCancelled.erase(threadIsCancelled.begin() + i);
						threadIsCancelledLock.erase(threadIsCancelledLock.begin() + i);
						break;
					}
				}

				bool isRunning = true;
				threadIsRunning.push_back(std::ref(isRunning));
				std::mutex isRunningLock;
				threadIsRunningLock.push_back(std::ref(isRunningLock));
				bool isCancelled = false;
				threadIsCancelled.push_back(std::ref(isCancelled));
				std::mutex isCancelledLock;
				threadIsCancelledLock.push_back(std::ref(isCancelledLock));

				std::packaged_task<void(StateRequest)> task([&](StateRequest myRequest)
															{ EM.transition(myRequest, threadIsRunning.back().get(), threadIsRunningLock.back().get(), threadIsCancelled.back().get(), threadIsCancelledLock.back().get()); });
				std::thread  thread(std::move(task), request);
				thread.detach();
				requests.push_back(std::make_pair(request, std::ref(thread)));
			}
		}
	}

}
