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
CMAKE_SOURCE_DIR = D:\FacultyProjects\GraphAlgorithms\Dijkstra

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\FacultyProjects\GraphAlgorithms\Dijkstra\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Dijkstra.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Dijkstra.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Dijkstra.dir/flags.make

CMakeFiles/Dijkstra.dir/main.cpp.obj: CMakeFiles/Dijkstra.dir/flags.make
CMakeFiles/Dijkstra.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\FacultyProjects\GraphAlgorithms\Dijkstra\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Dijkstra.dir/main.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Dijkstra.dir\main.cpp.obj -c D:\FacultyProjects\GraphAlgorithms\Dijkstra\main.cpp

CMakeFiles/Dijkstra.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dijkstra.dir/main.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\FacultyProjects\GraphAlgorithms\Dijkstra\main.cpp > CMakeFiles\Dijkstra.dir\main.cpp.i

CMakeFiles/Dijkstra.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dijkstra.dir/main.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\FacultyProjects\GraphAlgorithms\Dijkstra\main.cpp -o CMakeFiles\Dijkstra.dir\main.cpp.s

CMakeFiles/Dijkstra.dir/edgeList.cpp.obj: CMakeFiles/Dijkstra.dir/flags.make
CMakeFiles/Dijkstra.dir/edgeList.cpp.obj: ../edgeList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\FacultyProjects\GraphAlgorithms\Dijkstra\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Dijkstra.dir/edgeList.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Dijkstra.dir\edgeList.cpp.obj -c D:\FacultyProjects\GraphAlgorithms\Dijkstra\edgeList.cpp

CMakeFiles/Dijkstra.dir/edgeList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dijkstra.dir/edgeList.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\FacultyProjects\GraphAlgorithms\Dijkstra\edgeList.cpp > CMakeFiles\Dijkstra.dir\edgeList.cpp.i

CMakeFiles/Dijkstra.dir/edgeList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dijkstra.dir/edgeList.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\FacultyProjects\GraphAlgorithms\Dijkstra\edgeList.cpp -o CMakeFiles\Dijkstra.dir\edgeList.cpp.s

CMakeFiles/Dijkstra.dir/dijkstra.cpp.obj: CMakeFiles/Dijkstra.dir/flags.make
CMakeFiles/Dijkstra.dir/dijkstra.cpp.obj: ../dijkstra.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\FacultyProjects\GraphAlgorithms\Dijkstra\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Dijkstra.dir/dijkstra.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Dijkstra.dir\dijkstra.cpp.obj -c D:\FacultyProjects\GraphAlgorithms\Dijkstra\dijkstra.cpp

CMakeFiles/Dijkstra.dir/dijkstra.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dijkstra.dir/dijkstra.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\FacultyProjects\GraphAlgorithms\Dijkstra\dijkstra.cpp > CMakeFiles\Dijkstra.dir\dijkstra.cpp.i

CMakeFiles/Dijkstra.dir/dijkstra.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dijkstra.dir/dijkstra.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\FacultyProjects\GraphAlgorithms\Dijkstra\dijkstra.cpp -o CMakeFiles\Dijkstra.dir\dijkstra.cpp.s

CMakeFiles/Dijkstra.dir/adjacencyList.cpp.obj: CMakeFiles/Dijkstra.dir/flags.make
CMakeFiles/Dijkstra.dir/adjacencyList.cpp.obj: ../adjacencyList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\FacultyProjects\GraphAlgorithms\Dijkstra\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Dijkstra.dir/adjacencyList.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Dijkstra.dir\adjacencyList.cpp.obj -c D:\FacultyProjects\GraphAlgorithms\Dijkstra\adjacencyList.cpp

CMakeFiles/Dijkstra.dir/adjacencyList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dijkstra.dir/adjacencyList.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\FacultyProjects\GraphAlgorithms\Dijkstra\adjacencyList.cpp > CMakeFiles\Dijkstra.dir\adjacencyList.cpp.i

CMakeFiles/Dijkstra.dir/adjacencyList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dijkstra.dir/adjacencyList.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\FacultyProjects\GraphAlgorithms\Dijkstra\adjacencyList.cpp -o CMakeFiles\Dijkstra.dir\adjacencyList.cpp.s

# Object files for target Dijkstra
Dijkstra_OBJECTS = \
"CMakeFiles/Dijkstra.dir/main.cpp.obj" \
"CMakeFiles/Dijkstra.dir/edgeList.cpp.obj" \
"CMakeFiles/Dijkstra.dir/dijkstra.cpp.obj" \
"CMakeFiles/Dijkstra.dir/adjacencyList.cpp.obj"

# External object files for target Dijkstra
Dijkstra_EXTERNAL_OBJECTS =

Dijkstra.exe: CMakeFiles/Dijkstra.dir/main.cpp.obj
Dijkstra.exe: CMakeFiles/Dijkstra.dir/edgeList.cpp.obj
Dijkstra.exe: CMakeFiles/Dijkstra.dir/dijkstra.cpp.obj
Dijkstra.exe: CMakeFiles/Dijkstra.dir/adjacencyList.cpp.obj
Dijkstra.exe: CMakeFiles/Dijkstra.dir/build.make
Dijkstra.exe: CMakeFiles/Dijkstra.dir/linklibs.rsp
Dijkstra.exe: CMakeFiles/Dijkstra.dir/objects1.rsp
Dijkstra.exe: CMakeFiles/Dijkstra.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\FacultyProjects\GraphAlgorithms\Dijkstra\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Dijkstra.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Dijkstra.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Dijkstra.dir/build: Dijkstra.exe

.PHONY : CMakeFiles/Dijkstra.dir/build

CMakeFiles/Dijkstra.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Dijkstra.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Dijkstra.dir/clean

CMakeFiles/Dijkstra.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\FacultyProjects\GraphAlgorithms\Dijkstra D:\FacultyProjects\GraphAlgorithms\Dijkstra D:\FacultyProjects\GraphAlgorithms\Dijkstra\cmake-build-debug D:\FacultyProjects\GraphAlgorithms\Dijkstra\cmake-build-debug D:\FacultyProjects\GraphAlgorithms\Dijkstra\cmake-build-debug\CMakeFiles\Dijkstra.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Dijkstra.dir/depend
