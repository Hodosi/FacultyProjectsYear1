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
CMAKE_SOURCE_DIR = D:\FacultyProjects\GraphAlgorithms\Prim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\FacultyProjects\GraphAlgorithms\Prim\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Prim.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Prim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Prim.dir/flags.make

CMakeFiles/Prim.dir/main.cpp.obj: CMakeFiles/Prim.dir/flags.make
CMakeFiles/Prim.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\FacultyProjects\GraphAlgorithms\Prim\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Prim.dir/main.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Prim.dir\main.cpp.obj -c D:\FacultyProjects\GraphAlgorithms\Prim\main.cpp

CMakeFiles/Prim.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Prim.dir/main.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\FacultyProjects\GraphAlgorithms\Prim\main.cpp > CMakeFiles\Prim.dir\main.cpp.i

CMakeFiles/Prim.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Prim.dir/main.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\FacultyProjects\GraphAlgorithms\Prim\main.cpp -o CMakeFiles\Prim.dir\main.cpp.s

CMakeFiles/Prim.dir/adjacencyList.cpp.obj: CMakeFiles/Prim.dir/flags.make
CMakeFiles/Prim.dir/adjacencyList.cpp.obj: ../adjacencyList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\FacultyProjects\GraphAlgorithms\Prim\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Prim.dir/adjacencyList.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Prim.dir\adjacencyList.cpp.obj -c D:\FacultyProjects\GraphAlgorithms\Prim\adjacencyList.cpp

CMakeFiles/Prim.dir/adjacencyList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Prim.dir/adjacencyList.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\FacultyProjects\GraphAlgorithms\Prim\adjacencyList.cpp > CMakeFiles\Prim.dir\adjacencyList.cpp.i

CMakeFiles/Prim.dir/adjacencyList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Prim.dir/adjacencyList.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\FacultyProjects\GraphAlgorithms\Prim\adjacencyList.cpp -o CMakeFiles\Prim.dir\adjacencyList.cpp.s

CMakeFiles/Prim.dir/prim.cpp.obj: CMakeFiles/Prim.dir/flags.make
CMakeFiles/Prim.dir/prim.cpp.obj: ../prim.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\FacultyProjects\GraphAlgorithms\Prim\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Prim.dir/prim.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Prim.dir\prim.cpp.obj -c D:\FacultyProjects\GraphAlgorithms\Prim\prim.cpp

CMakeFiles/Prim.dir/prim.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Prim.dir/prim.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\FacultyProjects\GraphAlgorithms\Prim\prim.cpp > CMakeFiles\Prim.dir\prim.cpp.i

CMakeFiles/Prim.dir/prim.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Prim.dir/prim.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\FacultyProjects\GraphAlgorithms\Prim\prim.cpp -o CMakeFiles\Prim.dir\prim.cpp.s

# Object files for target Prim
Prim_OBJECTS = \
"CMakeFiles/Prim.dir/main.cpp.obj" \
"CMakeFiles/Prim.dir/adjacencyList.cpp.obj" \
"CMakeFiles/Prim.dir/prim.cpp.obj"

# External object files for target Prim
Prim_EXTERNAL_OBJECTS =

Prim.exe: CMakeFiles/Prim.dir/main.cpp.obj
Prim.exe: CMakeFiles/Prim.dir/adjacencyList.cpp.obj
Prim.exe: CMakeFiles/Prim.dir/prim.cpp.obj
Prim.exe: CMakeFiles/Prim.dir/build.make
Prim.exe: CMakeFiles/Prim.dir/linklibs.rsp
Prim.exe: CMakeFiles/Prim.dir/objects1.rsp
Prim.exe: CMakeFiles/Prim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\FacultyProjects\GraphAlgorithms\Prim\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Prim.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Prim.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Prim.dir/build: Prim.exe

.PHONY : CMakeFiles/Prim.dir/build

CMakeFiles/Prim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Prim.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Prim.dir/clean

CMakeFiles/Prim.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\FacultyProjects\GraphAlgorithms\Prim D:\FacultyProjects\GraphAlgorithms\Prim D:\FacultyProjects\GraphAlgorithms\Prim\cmake-build-debug D:\FacultyProjects\GraphAlgorithms\Prim\cmake-build-debug D:\FacultyProjects\GraphAlgorithms\Prim\cmake-build-debug\CMakeFiles\Prim.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Prim.dir/depend

