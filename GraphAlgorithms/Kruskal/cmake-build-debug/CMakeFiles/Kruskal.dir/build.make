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
CMAKE_SOURCE_DIR = D:\FacultyProjects\GraphAlgorithms\Kruskal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\FacultyProjects\GraphAlgorithms\Kruskal\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Kruskal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Kruskal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Kruskal.dir/flags.make

CMakeFiles/Kruskal.dir/main.cpp.obj: CMakeFiles/Kruskal.dir/flags.make
CMakeFiles/Kruskal.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\FacultyProjects\GraphAlgorithms\Kruskal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Kruskal.dir/main.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Kruskal.dir\main.cpp.obj -c D:\FacultyProjects\GraphAlgorithms\Kruskal\main.cpp

CMakeFiles/Kruskal.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kruskal.dir/main.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\FacultyProjects\GraphAlgorithms\Kruskal\main.cpp > CMakeFiles\Kruskal.dir\main.cpp.i

CMakeFiles/Kruskal.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kruskal.dir/main.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\FacultyProjects\GraphAlgorithms\Kruskal\main.cpp -o CMakeFiles\Kruskal.dir\main.cpp.s

CMakeFiles/Kruskal.dir/edgeList.cpp.obj: CMakeFiles/Kruskal.dir/flags.make
CMakeFiles/Kruskal.dir/edgeList.cpp.obj: ../edgeList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\FacultyProjects\GraphAlgorithms\Kruskal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Kruskal.dir/edgeList.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Kruskal.dir\edgeList.cpp.obj -c D:\FacultyProjects\GraphAlgorithms\Kruskal\edgeList.cpp

CMakeFiles/Kruskal.dir/edgeList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kruskal.dir/edgeList.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\FacultyProjects\GraphAlgorithms\Kruskal\edgeList.cpp > CMakeFiles\Kruskal.dir\edgeList.cpp.i

CMakeFiles/Kruskal.dir/edgeList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kruskal.dir/edgeList.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\FacultyProjects\GraphAlgorithms\Kruskal\edgeList.cpp -o CMakeFiles\Kruskal.dir\edgeList.cpp.s

CMakeFiles/Kruskal.dir/kruskal.cpp.obj: CMakeFiles/Kruskal.dir/flags.make
CMakeFiles/Kruskal.dir/kruskal.cpp.obj: ../kruskal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\FacultyProjects\GraphAlgorithms\Kruskal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Kruskal.dir/kruskal.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Kruskal.dir\kruskal.cpp.obj -c D:\FacultyProjects\GraphAlgorithms\Kruskal\kruskal.cpp

CMakeFiles/Kruskal.dir/kruskal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kruskal.dir/kruskal.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\FacultyProjects\GraphAlgorithms\Kruskal\kruskal.cpp > CMakeFiles\Kruskal.dir\kruskal.cpp.i

CMakeFiles/Kruskal.dir/kruskal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kruskal.dir/kruskal.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\FacultyProjects\GraphAlgorithms\Kruskal\kruskal.cpp -o CMakeFiles\Kruskal.dir\kruskal.cpp.s

# Object files for target Kruskal
Kruskal_OBJECTS = \
"CMakeFiles/Kruskal.dir/main.cpp.obj" \
"CMakeFiles/Kruskal.dir/edgeList.cpp.obj" \
"CMakeFiles/Kruskal.dir/kruskal.cpp.obj"

# External object files for target Kruskal
Kruskal_EXTERNAL_OBJECTS =

Kruskal.exe: CMakeFiles/Kruskal.dir/main.cpp.obj
Kruskal.exe: CMakeFiles/Kruskal.dir/edgeList.cpp.obj
Kruskal.exe: CMakeFiles/Kruskal.dir/kruskal.cpp.obj
Kruskal.exe: CMakeFiles/Kruskal.dir/build.make
Kruskal.exe: CMakeFiles/Kruskal.dir/linklibs.rsp
Kruskal.exe: CMakeFiles/Kruskal.dir/objects1.rsp
Kruskal.exe: CMakeFiles/Kruskal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\FacultyProjects\GraphAlgorithms\Kruskal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Kruskal.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Kruskal.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Kruskal.dir/build: Kruskal.exe

.PHONY : CMakeFiles/Kruskal.dir/build

CMakeFiles/Kruskal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Kruskal.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Kruskal.dir/clean

CMakeFiles/Kruskal.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\FacultyProjects\GraphAlgorithms\Kruskal D:\FacultyProjects\GraphAlgorithms\Kruskal D:\FacultyProjects\GraphAlgorithms\Kruskal\cmake-build-debug D:\FacultyProjects\GraphAlgorithms\Kruskal\cmake-build-debug D:\FacultyProjects\GraphAlgorithms\Kruskal\cmake-build-debug\CMakeFiles\Kruskal.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Kruskal.dir/depend
