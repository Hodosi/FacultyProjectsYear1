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
CMAKE_SOURCE_DIR = D:\FacultyProjects\GraphAlgorithms\BFS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\FacultyProjects\GraphAlgorithms\BFS\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BFS.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BFS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BFS.dir/flags.make

CMakeFiles/BFS.dir/main.cpp.obj: CMakeFiles/BFS.dir/flags.make
CMakeFiles/BFS.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\FacultyProjects\GraphAlgorithms\BFS\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BFS.dir/main.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BFS.dir\main.cpp.obj -c D:\FacultyProjects\GraphAlgorithms\BFS\main.cpp

CMakeFiles/BFS.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BFS.dir/main.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\FacultyProjects\GraphAlgorithms\BFS\main.cpp > CMakeFiles\BFS.dir\main.cpp.i

CMakeFiles/BFS.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BFS.dir/main.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\FacultyProjects\GraphAlgorithms\BFS\main.cpp -o CMakeFiles\BFS.dir\main.cpp.s

CMakeFiles/BFS.dir/adjacencyList.cpp.obj: CMakeFiles/BFS.dir/flags.make
CMakeFiles/BFS.dir/adjacencyList.cpp.obj: ../adjacencyList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\FacultyProjects\GraphAlgorithms\BFS\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BFS.dir/adjacencyList.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BFS.dir\adjacencyList.cpp.obj -c D:\FacultyProjects\GraphAlgorithms\BFS\adjacencyList.cpp

CMakeFiles/BFS.dir/adjacencyList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BFS.dir/adjacencyList.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\FacultyProjects\GraphAlgorithms\BFS\adjacencyList.cpp > CMakeFiles\BFS.dir\adjacencyList.cpp.i

CMakeFiles/BFS.dir/adjacencyList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BFS.dir/adjacencyList.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\FacultyProjects\GraphAlgorithms\BFS\adjacencyList.cpp -o CMakeFiles\BFS.dir\adjacencyList.cpp.s

CMakeFiles/BFS.dir/BFS.cpp.obj: CMakeFiles/BFS.dir/flags.make
CMakeFiles/BFS.dir/BFS.cpp.obj: ../BFS.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\FacultyProjects\GraphAlgorithms\BFS\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/BFS.dir/BFS.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BFS.dir\BFS.cpp.obj -c D:\FacultyProjects\GraphAlgorithms\BFS\BFS.cpp

CMakeFiles/BFS.dir/BFS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BFS.dir/BFS.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\FacultyProjects\GraphAlgorithms\BFS\BFS.cpp > CMakeFiles\BFS.dir\BFS.cpp.i

CMakeFiles/BFS.dir/BFS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BFS.dir/BFS.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\FacultyProjects\GraphAlgorithms\BFS\BFS.cpp -o CMakeFiles\BFS.dir\BFS.cpp.s

# Object files for target BFS
BFS_OBJECTS = \
"CMakeFiles/BFS.dir/main.cpp.obj" \
"CMakeFiles/BFS.dir/adjacencyList.cpp.obj" \
"CMakeFiles/BFS.dir/BFS.cpp.obj"

# External object files for target BFS
BFS_EXTERNAL_OBJECTS =

BFS.exe: CMakeFiles/BFS.dir/main.cpp.obj
BFS.exe: CMakeFiles/BFS.dir/adjacencyList.cpp.obj
BFS.exe: CMakeFiles/BFS.dir/BFS.cpp.obj
BFS.exe: CMakeFiles/BFS.dir/build.make
BFS.exe: CMakeFiles/BFS.dir/linklibs.rsp
BFS.exe: CMakeFiles/BFS.dir/objects1.rsp
BFS.exe: CMakeFiles/BFS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\FacultyProjects\GraphAlgorithms\BFS\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable BFS.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BFS.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BFS.dir/build: BFS.exe

.PHONY : CMakeFiles/BFS.dir/build

CMakeFiles/BFS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BFS.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BFS.dir/clean

CMakeFiles/BFS.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\FacultyProjects\GraphAlgorithms\BFS D:\FacultyProjects\GraphAlgorithms\BFS D:\FacultyProjects\GraphAlgorithms\BFS\cmake-build-debug D:\FacultyProjects\GraphAlgorithms\BFS\cmake-build-debug D:\FacultyProjects\GraphAlgorithms\BFS\cmake-build-debug\CMakeFiles\BFS.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BFS.dir/depend
