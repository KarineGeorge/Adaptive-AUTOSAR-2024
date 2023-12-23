cmake_minimum_required(VERSION 3.14)

project(demoSM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SM_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set(RAPID_JSON ${CMAKE_CURRENT_SOURCE_DIR}/rapidjson)

set(SM_SRC_FILES
    src/main.cpp
    src/EmFacade.cpp
    src/error_code.cpp
    src/ExecutionClient.cpp
    src/FunctionGroup.cpp
    src/FunctionGroupState.cpp
    src/instance_id.cpp
    src/instance_specifier.cpp
    src/other.cpp
    src/PipeInput.cpp
    src/PipeOutput.cpp
    src/RequestResultEvaluation.cpp
    src/ShutdownHandler.cpp
    src/state_client.cpp
    src/StateClientImpl.cpp
    src/StateManager.cpp
    src/StateRequestBuffer.cpp
    src/StateRequestProcessor.cpp
    src/triggers.cpp
    src/MachineManifest.cpp
    src/CalibrationData.cpp
    src/GroupsAndStates.cpp
    
    
)


set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "../../SW_packages/SMProcess")

add_executable(state_manager ${SM_SRC_FILES})

target_include_directories(state_manager PUBLIC  ${SM_INC_DIR} ${RAPID_JSON})


