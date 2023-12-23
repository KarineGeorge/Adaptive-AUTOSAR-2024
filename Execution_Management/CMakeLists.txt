cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
# Set the project name
project(ExecutionManagerexe)

# Set common path
set(ExecutionManager ./ExecutionManager)
set(ExecutionClientProcess ./ExecutionClientProcess)
set(StateClientProcess ./StateClientProcess)





# List header files
set(HEADER_FILES
    ${ExecutionManager}/include/execution_error_event.h
    ${ExecutionManager}/include/ExecutionClient.h
    ${ExecutionManager}/include/ExecutionManager.h
    ${ExecutionManager}/include/ExecutionManifest.h
    ${ExecutionManager}/include/FunctionGroup.h
    ${ExecutionManager}/include/FunctionGroupState.h
    ${ExecutionManager}/include/MachineManifest.h
    ${ExecutionManager}/include/Pipe.h
    ${ExecutionManager}/include/PipeInput.h
    ${ExecutionManager}/include/PipeOutput.h
    ${ExecutionManager}/include/StartupConfiguration.h
    ${ExecutionManager}/include/StateClient.h
    ${ExecutionManager}/include/StateClientImpl.h
    ${ExecutionManager}/include/StateRequest.h
    ${ExecutionManager}/include/StateResponse.h
    ${ExecutionManager}/include/StateStartupConfiguration.h

    # ${ExecutionClientProcess}/include/ExecutionClient.h
    # ${ExecutionClientProcess}/include/PipeInput.h

    # ${StateClientProcess}/include/execution_error_event.h 
    # ${StateClientProcess}/include/ExecutionClient.h  
    # ${StateClientProcess}/include/state_client.h  
    # ${StateClientProcess}/include/StateClientImpl.h
    # ${StateClientProcess}/include/PipeOutput.h
    # ${StateClientProcess}/include/PipeInput.h
    # ${StateClientProcess}/include/FunctionGroup.h
    # ${StateClientProcess}/include/FunctionGroupState.h
    # ${StateClientProcess}/include/StateRequest.h
    # ${StateClientProcess}/include/StateResponse.h
    # ${StateClientProcess}/include/GetStateResponse.h
)

# List source files
set(SOURCE_FILES
    ${ExecutionManager}/src/ExecutionClient.cpp
    ${ExecutionManager}/src/ExecutionManager.cpp
    ${ExecutionManager}/src/ExecutionManifest.cpp
    ${ExecutionManager}/src/FunctionGroup.cpp
    ${ExecutionManager}/src/FunctionGroupState.cpp
    ${ExecutionManager}/src/MachineManifest.cpp
    ${ExecutionManager}/src/main.cpp
    ${ExecutionManager}/src/Pipe.cpp
    ${ExecutionManager}/src/PipeInput.cpp
    ${ExecutionManager}/src/PipeOutput.cpp
    ${ExecutionManager}/src/StartupConfiguration.cpp
    ${ExecutionManager}/src/StateClient.cpp
    ${ExecutionManager}/src/StateClientImpl.cpp
    ${ExecutionManager}/src/StateStartupConfiguration.cpp


    # ${ExecutionClientProcess}/src/ExecutionClient.cpp
    # ${ExecutionClientProcess}/src/ExecutionClientProcess.cpp
    # ${ExecutionClientProcess}/src/PipeInput.cpp

    # ${StateClientProcess}/src/state_client.cpp  
    # ${StateClientProcess}/src/StateClientImpl.cpp
    # ${StateClientProcess}/src/StateClientProcess.cpp
    # ${StateClientProcess}/src/PipeOutput.cpp
    # ${StateClientProcess}/src/PipeInput.cpp
    # ${StateClientProcess}/src/FunctionGroup.cpp
    # ${StateClientProcess}/src/FunctionGroupState.cpp
    # ${StateClientProcess}/src/ExecutionClient.cpp
)
    
# set(CMAKE_CXX_STANDARD 17)

# Add the executable target
add_executable(ExecutionManagerexe ${SOURCE_FILES} ${HEADER_FILES})

# Specify the path to OpenSSL include directory
include_directories("rapidjson-master/include")

# Specify the path to OpenSSL library directory
link_directories("rapidjson-master/bin")

# Add custom target to run the executable
add_custom_target(run
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/ExecutionManagerexe
    DEPENDS ExecutionManagerexe
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Running ExecutionManagerexe project"
)

# Disable all warnings for the target
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")  # Check if using Microsoft Visual C++
    target_compile_options(ExecutionManagerexe PRIVATE /w)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(ExecutionManagerexe PRIVATE -w)
endif()