# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\FacultyProjects\GraphAlgorithms\FlowRelabelAlgorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\FacultyProjects\GraphAlgorithms\FlowRelabelAlgorithms\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FlowRelabelAlgorithms.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FlowRelabelAlgorithms.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FlowRelabelAlgorithms.dir/flags.make

CMakeFiles/FlowRelabelAlgorithms.dir/main.cpp.obj: CMakeFiles/FlowRelabelAlgorithms.dir/flags.make
CMakeFiles/FlowRelabelAlgorithms.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\FacultyProjects\GraphAlgorithms\FlowRelabelAlgorithms\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FlowRelabelAlgorithms.dir/main.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\FlowRelabelAlgorithms.dir\main.cpp.obj -c D:\FacultyProjects\GraphAlgorithms\FlowRelabelAlgorithms\main.cpp

CMakeFiles/FlowRelabelAlgorithms.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FlowRelabelAlgorithms.dir/main.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\FacultyProjects\GraphAlgorithms\FlowRelabelAlgorithms\main.cpp > CMakeFiles\FlowRelabelAlgorithms.dir\main.cpp.i

CMakeFiles/FlowRelabelAlgorithms.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FlowRelabelAlgorithms.dir/main.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\FacultyProjects\GraphAlgorithms\FlowRelabelAlgorithms\main.cpp -o CMakeFiles\FlowRelabelAlgorithms.dir\main.cpp.s

CMakeFiles/FlowRelabelAlgorithms.dir/fromFileToAdjacencyList.cpp.obj: CMakeFiles/FlowRelabelAlgorithms.dir/flags.make
CMakeFiles/FlowRelabelAlgorithms.dir/fromFileToAdjacencyList.cpp.obj: ../fromFileToAdjacencyList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\FacultyProjects\GraphAlgorithms\FlowRelabelAlgorithms\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FlowRelabelAlgorithms.dir/fromFileToAdjacencyList.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\FlowRelabelAlgorithms.dir\fromFileToAdjacencyList.cpp.obj -c D:\FacultyProjects\GraphAlgorithms\FlowRelabelAlgorithms\fromFileToAdjacencyList.cpp

CMakeFiles/FlowRelabelAlgorithms.dir/fromFileToAdjacencyList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FlowRelabelAlgorithms.dir/fromFileToAdjacencyList.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\FacultyProjects\GraphAlgorithms\FlowRelabelAlgorithms\fromFileToAdjacencyList.cpp > CMakeFiles\FlowRelabelAlgorithms.dir\fromFileToAdjacencyList.cpp.i

CMakeFiles/FlowRelabelAlgorithms.dir/fromFileToAdjacencyList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FlowRelabelAlgorithms.dir/fromFileToAdjacencyList.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\FacultyProjects\GraphAlgorithms\FlowRelabelAlgorithms\fromFileToAdjacencyList.cpp -o CMakeFiles\FlowRelabelAlgorithms.dir\fromFileToAdjacencyList.cpp.s

CMakeFiles/FlowRelabelAlgorithms.dir/flowRelabel.cpp.obj: CMakeFiles/FlowRelabelAlgorithms.dir/flags.make
CMakeFiles/FlowRelabelAlgorithms.dir/flowRelabel.cpp.obj: ../flowRelabel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\FacultyProjects\GraphAlgorithms\FlowRelabelAlgorithms\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/FlowRelabelAlgorithms.dir/flowRelabel.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\FlowRelabelAlgorithms.dir\flowRelabel.cpp.obj -c D:\FacultyProjects\GraphAlgorithms\FlowRelabelAlgorithms\flowRelabel.cpp

CMakeFiles/FlowRelabelAlgorithms.dir/flowRelabel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FlowRelabelAlgorithms.dir/flowRelabel.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\FacultyProjects\GraphAlgorithms\FlowRelabelAlgorithms\flowRelabel.cpp > CMakeFiles\FlowRelabelAlgorithms.dir\flowRelabel.cpp.i

CMakeFiles/FlowRelabelAlgorithms.dir/flowRelabel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FlowRelabelAlgorithms.dir/flowRelabel.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\FacultyProjects\GraphAlgorithms\FlowRelabelAlgorithms\flowRelabel.cpp -o CMakeFiles\FlowRelabelAlgorithms.dir\flowRelabel.cpp.s

# Object files for target FlowRelabelAlgorithms
FlowRelabelAlgorithms_OBJECTS = \
"CMakeFiles/FlowRelabelAlgorithms.dir/main.cpp.obj" \
"CMakeFiles/FlowRelabelAlgorithms.dir/fromFileToAdjacencyList.cpp.obj" \
"CMakeFiles/FlowRelabelAlgorithms.dir/flowRelabel.cpp.obj"

# External object files for target FlowRelabelAlgorithms
FlowRelabelAlgorithms_EXTERNAL_OBJECTS =

FlowRelabelAlgorithms.exe: CMakeFiles/FlowRelabelAlgorithms.dir/main.cpp.obj
FlowRelabelAlgorithms.exe: CMakeFiles/FlowRelabelAlgorithms.dir/fromFileToAdjacencyList.cpp.obj
FlowRelabelAlgorithms.exe: CMakeFiles/FlowRelabelAlgorithms.dir/flowRelabel.cpp.obj
FlowRelabelAlgorithms.exe: CMakeFiles/FlowRelabelAlgorithms.dir/build.make
FlowRelabelAlgorithms.exe: CMakeFiles/FlowRelabelAlgorithms.dir/linklibs.rsp
FlowRelabelAlgorithms.exe: CMakeFiles/FlowRelabelAlgorithms.dir/objects1.rsp
FlowRelabelAlgorithms.exe: CMakeFiles/FlowRelabelAlgorithms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\FacultyProjects\GraphAlgorithms\FlowRelabelAlgorithms\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable FlowRelabelAlgorithms.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\FlowRelabelAlgorithms.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FlowRelabelAlgorithms.dir/build: FlowRelabelAlgorithms.exe

.PHONY : CMakeFiles/FlowRelabelAlgorithms.dir/build

CMakeFiles/FlowRelabelAlgorithms.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\FlowRelabelAlgorithms.dir\cmake_clean.cmake
.PHONY : CMakeFiles/FlowRelabelAlgorithms.dir/clean

CMakeFiles/FlowRelabelAlgorithms.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\FacultyProjects\GraphAlgorithms\FlowRelabelAlgorithms D:\FacultyProjects\GraphAlgorithms\FlowRelabelAlgorithms D:\FacultyProjects\GraphAlgorithms\FlowRelabelAlgorithms\cmake-build-debug D:\FacultyProjects\GraphAlgorithms\FlowRelabelAlgorithms\cmake-build-debug D:\FacultyProjects\GraphAlgorithms\FlowRelabelAlgorithms\cmake-build-debug\CMakeFiles\FlowRelabelAlgorithms.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FlowRelabelAlgorithms.dir/depend

