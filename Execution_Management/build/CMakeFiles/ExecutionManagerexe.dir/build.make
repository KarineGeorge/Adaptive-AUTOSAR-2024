# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/build"

# Include any dependencies generated for this target.
include CMakeFiles/ExecutionManagerexe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ExecutionManagerexe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ExecutionManagerexe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ExecutionManagerexe.dir/flags.make

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionClient.cpp.o: CMakeFiles/ExecutionManagerexe.dir/flags.make
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionClient.cpp.o: ../ExecutionManager/src/ExecutionClient.cpp
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionClient.cpp.o: CMakeFiles/ExecutionManagerexe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionClient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionClient.cpp.o -MF CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionClient.cpp.o.d -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionClient.cpp.o -c "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/ExecutionClient.cpp"

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/ExecutionClient.cpp" > CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionClient.cpp.i

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/ExecutionClient.cpp" -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionClient.cpp.s

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManager.cpp.o: CMakeFiles/ExecutionManagerexe.dir/flags.make
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManager.cpp.o: ../ExecutionManager/src/ExecutionManager.cpp
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManager.cpp.o: CMakeFiles/ExecutionManagerexe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManager.cpp.o -MF CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManager.cpp.o.d -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManager.cpp.o -c "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/ExecutionManager.cpp"

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/ExecutionManager.cpp" > CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManager.cpp.i

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/ExecutionManager.cpp" -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManager.cpp.s

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManifest.cpp.o: CMakeFiles/ExecutionManagerexe.dir/flags.make
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManifest.cpp.o: ../ExecutionManager/src/ExecutionManifest.cpp
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManifest.cpp.o: CMakeFiles/ExecutionManagerexe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManifest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManifest.cpp.o -MF CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManifest.cpp.o.d -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManifest.cpp.o -c "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/ExecutionManifest.cpp"

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManifest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManifest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/ExecutionManifest.cpp" > CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManifest.cpp.i

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManifest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManifest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/ExecutionManifest.cpp" -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManifest.cpp.s

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroup.cpp.o: CMakeFiles/ExecutionManagerexe.dir/flags.make
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroup.cpp.o: ../ExecutionManager/src/FunctionGroup.cpp
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroup.cpp.o: CMakeFiles/ExecutionManagerexe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroup.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroup.cpp.o -MF CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroup.cpp.o.d -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroup.cpp.o -c "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/FunctionGroup.cpp"

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroup.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroup.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/FunctionGroup.cpp" > CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroup.cpp.i

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroup.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroup.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/FunctionGroup.cpp" -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroup.cpp.s

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroupState.cpp.o: CMakeFiles/ExecutionManagerexe.dir/flags.make
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroupState.cpp.o: ../ExecutionManager/src/FunctionGroupState.cpp
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroupState.cpp.o: CMakeFiles/ExecutionManagerexe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroupState.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroupState.cpp.o -MF CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroupState.cpp.o.d -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroupState.cpp.o -c "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/FunctionGroupState.cpp"

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroupState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroupState.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/FunctionGroupState.cpp" > CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroupState.cpp.i

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroupState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroupState.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/FunctionGroupState.cpp" -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroupState.cpp.s

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/MachineManifest.cpp.o: CMakeFiles/ExecutionManagerexe.dir/flags.make
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/MachineManifest.cpp.o: ../ExecutionManager/src/MachineManifest.cpp
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/MachineManifest.cpp.o: CMakeFiles/ExecutionManagerexe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/MachineManifest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/MachineManifest.cpp.o -MF CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/MachineManifest.cpp.o.d -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/MachineManifest.cpp.o -c "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/MachineManifest.cpp"

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/MachineManifest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/MachineManifest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/MachineManifest.cpp" > CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/MachineManifest.cpp.i

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/MachineManifest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/MachineManifest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/MachineManifest.cpp" -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/MachineManifest.cpp.s

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/main.cpp.o: CMakeFiles/ExecutionManagerexe.dir/flags.make
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/main.cpp.o: ../ExecutionManager/src/main.cpp
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/main.cpp.o: CMakeFiles/ExecutionManagerexe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/main.cpp.o -MF CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/main.cpp.o.d -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/main.cpp.o -c "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/main.cpp"

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/main.cpp" > CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/main.cpp.i

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/main.cpp" -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/main.cpp.s

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/Pipe.cpp.o: CMakeFiles/ExecutionManagerexe.dir/flags.make
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/Pipe.cpp.o: ../ExecutionManager/src/Pipe.cpp
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/Pipe.cpp.o: CMakeFiles/ExecutionManagerexe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/Pipe.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/Pipe.cpp.o -MF CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/Pipe.cpp.o.d -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/Pipe.cpp.o -c "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/Pipe.cpp"

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/Pipe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/Pipe.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/Pipe.cpp" > CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/Pipe.cpp.i

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/Pipe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/Pipe.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/Pipe.cpp" -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/Pipe.cpp.s

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeInput.cpp.o: CMakeFiles/ExecutionManagerexe.dir/flags.make
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeInput.cpp.o: ../ExecutionManager/src/PipeInput.cpp
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeInput.cpp.o: CMakeFiles/ExecutionManagerexe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeInput.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeInput.cpp.o -MF CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeInput.cpp.o.d -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeInput.cpp.o -c "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/PipeInput.cpp"

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeInput.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeInput.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/PipeInput.cpp" > CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeInput.cpp.i

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeInput.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeInput.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/PipeInput.cpp" -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeInput.cpp.s

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeOutput.cpp.o: CMakeFiles/ExecutionManagerexe.dir/flags.make
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeOutput.cpp.o: ../ExecutionManager/src/PipeOutput.cpp
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeOutput.cpp.o: CMakeFiles/ExecutionManagerexe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeOutput.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeOutput.cpp.o -MF CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeOutput.cpp.o.d -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeOutput.cpp.o -c "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/PipeOutput.cpp"

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeOutput.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeOutput.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/PipeOutput.cpp" > CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeOutput.cpp.i

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeOutput.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeOutput.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/PipeOutput.cpp" -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeOutput.cpp.s

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StartupConfiguration.cpp.o: CMakeFiles/ExecutionManagerexe.dir/flags.make
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StartupConfiguration.cpp.o: ../ExecutionManager/src/StartupConfiguration.cpp
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StartupConfiguration.cpp.o: CMakeFiles/ExecutionManagerexe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StartupConfiguration.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StartupConfiguration.cpp.o -MF CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StartupConfiguration.cpp.o.d -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StartupConfiguration.cpp.o -c "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/StartupConfiguration.cpp"

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StartupConfiguration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StartupConfiguration.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/StartupConfiguration.cpp" > CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StartupConfiguration.cpp.i

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StartupConfiguration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StartupConfiguration.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/StartupConfiguration.cpp" -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StartupConfiguration.cpp.s

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClient.cpp.o: CMakeFiles/ExecutionManagerexe.dir/flags.make
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClient.cpp.o: ../ExecutionManager/src/StateClient.cpp
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClient.cpp.o: CMakeFiles/ExecutionManagerexe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClient.cpp.o -MF CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClient.cpp.o.d -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClient.cpp.o -c "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/StateClient.cpp"

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/StateClient.cpp" > CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClient.cpp.i

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/StateClient.cpp" -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClient.cpp.s

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClientImpl.cpp.o: CMakeFiles/ExecutionManagerexe.dir/flags.make
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClientImpl.cpp.o: ../ExecutionManager/src/StateClientImpl.cpp
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClientImpl.cpp.o: CMakeFiles/ExecutionManagerexe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClientImpl.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClientImpl.cpp.o -MF CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClientImpl.cpp.o.d -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClientImpl.cpp.o -c "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/StateClientImpl.cpp"

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClientImpl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClientImpl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/StateClientImpl.cpp" > CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClientImpl.cpp.i

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClientImpl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClientImpl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/StateClientImpl.cpp" -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClientImpl.cpp.s

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateStartupConfiguration.cpp.o: CMakeFiles/ExecutionManagerexe.dir/flags.make
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateStartupConfiguration.cpp.o: ../ExecutionManager/src/StateStartupConfiguration.cpp
CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateStartupConfiguration.cpp.o: CMakeFiles/ExecutionManagerexe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateStartupConfiguration.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateStartupConfiguration.cpp.o -MF CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateStartupConfiguration.cpp.o.d -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateStartupConfiguration.cpp.o -c "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/StateStartupConfiguration.cpp"

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateStartupConfiguration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateStartupConfiguration.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/StateStartupConfiguration.cpp" > CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateStartupConfiguration.cpp.i

CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateStartupConfiguration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateStartupConfiguration.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/ExecutionManager/src/StateStartupConfiguration.cpp" -o CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateStartupConfiguration.cpp.s

# Object files for target ExecutionManagerexe
ExecutionManagerexe_OBJECTS = \
"CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionClient.cpp.o" \
"CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManager.cpp.o" \
"CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManifest.cpp.o" \
"CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroup.cpp.o" \
"CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroupState.cpp.o" \
"CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/MachineManifest.cpp.o" \
"CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/main.cpp.o" \
"CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/Pipe.cpp.o" \
"CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeInput.cpp.o" \
"CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeOutput.cpp.o" \
"CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StartupConfiguration.cpp.o" \
"CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClient.cpp.o" \
"CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClientImpl.cpp.o" \
"CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateStartupConfiguration.cpp.o"

# External object files for target ExecutionManagerexe
ExecutionManagerexe_EXTERNAL_OBJECTS =

ExecutionManagerexe: CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionClient.cpp.o
ExecutionManagerexe: CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManager.cpp.o
ExecutionManagerexe: CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/ExecutionManifest.cpp.o
ExecutionManagerexe: CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroup.cpp.o
ExecutionManagerexe: CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/FunctionGroupState.cpp.o
ExecutionManagerexe: CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/MachineManifest.cpp.o
ExecutionManagerexe: CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/main.cpp.o
ExecutionManagerexe: CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/Pipe.cpp.o
ExecutionManagerexe: CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeInput.cpp.o
ExecutionManagerexe: CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/PipeOutput.cpp.o
ExecutionManagerexe: CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StartupConfiguration.cpp.o
ExecutionManagerexe: CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClient.cpp.o
ExecutionManagerexe: CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateClientImpl.cpp.o
ExecutionManagerexe: CMakeFiles/ExecutionManagerexe.dir/ExecutionManager/src/StateStartupConfiguration.cpp.o
ExecutionManagerexe: CMakeFiles/ExecutionManagerexe.dir/build.make
ExecutionManagerexe: CMakeFiles/ExecutionManagerexe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable ExecutionManagerexe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ExecutionManagerexe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ExecutionManagerexe.dir/build: ExecutionManagerexe
.PHONY : CMakeFiles/ExecutionManagerexe.dir/build

CMakeFiles/ExecutionManagerexe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ExecutionManagerexe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ExecutionManagerexe.dir/clean

CMakeFiles/ExecutionManagerexe.dir/depend:
	cd "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management" "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management" "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/build" "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/build" "/home/tantawy/Desktop/Graduation Project Repository/Adaptive-AUTOSAR-2024/Execution_Management/build/CMakeFiles/ExecutionManagerexe.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ExecutionManagerexe.dir/depend

