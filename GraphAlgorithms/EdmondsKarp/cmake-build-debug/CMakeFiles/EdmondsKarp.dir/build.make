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
CMAKE_SOURCE_DIR = D:\FacultyProjects\GraphAlgorithms\EdmondsKarp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\FacultyProjects\GraphAlgorithms\EdmondsKarp\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/EdmondsKarp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/EdmondsKarp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EdmondsKarp.dir/flags.make

CMakeFiles/EdmondsKarp.dir/main.cpp.obj: CMakeFiles/EdmondsKarp.dir/flags.make
CMakeFiles/EdmondsKarp.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\FacultyProjects\GraphAlgorithms\EdmondsKarp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/EdmondsKarp.dir/main.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\EdmondsKarp.dir\main.cpp.obj -c D:\FacultyProjects\GraphAlgorithms\EdmondsKarp\main.cpp

CMakeFiles/EdmondsKarp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EdmondsKarp.dir/main.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\FacultyProjects\GraphAlgorithms\EdmondsKarp\main.cpp > CMakeFiles\EdmondsKarp.dir\main.cpp.i

CMakeFiles/EdmondsKarp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EdmondsKarp.dir/main.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\FacultyProjects\GraphAlgorithms\EdmondsKarp\main.cpp -o CMakeFiles\EdmondsKarp.dir\main.cpp.s

CMakeFiles/EdmondsKarp.dir/fromFileToAdjacencyList.cpp.obj: CMakeFiles/EdmondsKarp.dir/flags.make
CMakeFiles/EdmondsKarp.dir/fromFileToAdjacencyList.cpp.obj: ../fromFileToAdjacencyList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\FacultyProjects\GraphAlgorithms\EdmondsKarp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/EdmondsKarp.dir/fromFileToAdjacencyList.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\EdmondsKarp.dir\fromFileToAdjacencyList.cpp.obj -c D:\FacultyProjects\GraphAlgorithms\EdmondsKarp\fromFileToAdjacencyList.cpp

CMakeFiles/EdmondsKarp.dir/fromFileToAdjacencyList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EdmondsKarp.dir/fromFileToAdjacencyList.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\FacultyProjects\GraphAlgorithms\EdmondsKarp\fromFileToAdjacencyList.cpp > CMakeFiles\EdmondsKarp.dir\fromFileToAdjacencyList.cpp.i

CMakeFiles/EdmondsKarp.dir/fromFileToAdjacencyList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EdmondsKarp.dir/fromFileToAdjacencyList.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\FacultyProjects\GraphAlgorithms\EdmondsKarp\fromFileToAdjacencyList.cpp -o CMakeFiles\EdmondsKarp.dir\fromFileToAdjacencyList.cpp.s

CMakeFiles/EdmondsKarp.dir/edmondsKarp.cpp.obj: CMakeFiles/EdmondsKarp.dir/flags.make
CMakeFiles/EdmondsKarp.dir/edmondsKarp.cpp.obj: ../edmondsKarp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\FacultyProjects\GraphAlgorithms\EdmondsKarp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/EdmondsKarp.dir/edmondsKarp.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\EdmondsKarp.dir\edmondsKarp.cpp.obj -c D:\FacultyProjects\GraphAlgorithms\EdmondsKarp\edmondsKarp.cpp

CMakeFiles/EdmondsKarp.dir/edmondsKarp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EdmondsKarp.dir/edmondsKarp.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\FacultyProjects\GraphAlgorithms\EdmondsKarp\edmondsKarp.cpp > CMakeFiles\EdmondsKarp.dir\edmondsKarp.cpp.i

CMakeFiles/EdmondsKarp.dir/edmondsKarp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EdmondsKarp.dir/edmondsKarp.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\FacultyProjects\GraphAlgorithms\EdmondsKarp\edmondsKarp.cpp -o CMakeFiles\EdmondsKarp.dir\edmondsKarp.cpp.s

# Object files for target EdmondsKarp
EdmondsKarp_OBJECTS = \
"CMakeFiles/EdmondsKarp.dir/main.cpp.obj" \
"CMakeFiles/EdmondsKarp.dir/fromFileToAdjacencyList.cpp.obj" \
"CMakeFiles/EdmondsKarp.dir/edmondsKarp.cpp.obj"

# External object files for target EdmondsKarp
EdmondsKarp_EXTERNAL_OBJECTS =

EdmondsKarp.exe: CMakeFiles/EdmondsKarp.dir/main.cpp.obj
EdmondsKarp.exe: CMakeFiles/EdmondsKarp.dir/fromFileToAdjacencyList.cpp.obj
EdmondsKarp.exe: CMakeFiles/EdmondsKarp.dir/edmondsKarp.cpp.obj
EdmondsKarp.exe: CMakeFiles/EdmondsKarp.dir/build.make
EdmondsKarp.exe: CMakeFiles/EdmondsKarp.dir/linklibs.rsp
EdmondsKarp.exe: CMakeFiles/EdmondsKarp.dir/objects1.rsp
EdmondsKarp.exe: CMakeFiles/EdmondsKarp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\FacultyProjects\GraphAlgorithms\EdmondsKarp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable EdmondsKarp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\EdmondsKarp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EdmondsKarp.dir/build: EdmondsKarp.exe

.PHONY : CMakeFiles/EdmondsKarp.dir/build

CMakeFiles/EdmondsKarp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\EdmondsKarp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/EdmondsKarp.dir/clean

CMakeFiles/EdmondsKarp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\FacultyProjects\GraphAlgorithms\EdmondsKarp D:\FacultyProjects\GraphAlgorithms\EdmondsKarp D:\FacultyProjects\GraphAlgorithms\EdmondsKarp\cmake-build-debug D:\FacultyProjects\GraphAlgorithms\EdmondsKarp\cmake-build-debug D:\FacultyProjects\GraphAlgorithms\EdmondsKarp\cmake-build-debug\CMakeFiles\EdmondsKarp.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EdmondsKarp.dir/depend
