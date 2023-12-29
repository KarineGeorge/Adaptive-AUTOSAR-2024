cmake_minimum_required(VERSION 3.14)
project(COMSM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/com)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/SM)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Execution_Management)

add_executable(main_proxy main_proxy.cpp)
add_executable(main_skeleton main_skeleton.cpp)
add_executable(main_process main_process.cpp)

target_link_libraries(main_process araCom)
#target_link_libraries(main_process SM_LIB)
target_link_libraries(main_process EM_LIB)
target_link_libraries(main_skeleton SM_LIB)
target_link_libraries(main_skeleton araCom)
target_link_libraries(main_skeleton EM_LIB)
target_link_libraries(main_proxy  araCom)
target_link_libraries(main_proxy SM_LIB)
target_link_libraries(main_proxy EM_LIB)


