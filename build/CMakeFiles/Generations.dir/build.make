# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.9.6/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.9.6/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Lea/Desktop/Team_5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Lea/Desktop/Team_5/build

# Include any dependencies generated for this target.
include CMakeFiles/Generations.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Generations.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Generations.dir/flags.make

CMakeFiles/Generations.dir/src/Allele.cpp.o: CMakeFiles/Generations.dir/flags.make
CMakeFiles/Generations.dir/src/Allele.cpp.o: ../src/Allele.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Lea/Desktop/Team_5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Generations.dir/src/Allele.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Generations.dir/src/Allele.cpp.o -c /Users/Lea/Desktop/Team_5/src/Allele.cpp

CMakeFiles/Generations.dir/src/Allele.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Generations.dir/src/Allele.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Lea/Desktop/Team_5/src/Allele.cpp > CMakeFiles/Generations.dir/src/Allele.cpp.i

CMakeFiles/Generations.dir/src/Allele.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Generations.dir/src/Allele.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Lea/Desktop/Team_5/src/Allele.cpp -o CMakeFiles/Generations.dir/src/Allele.cpp.s

CMakeFiles/Generations.dir/src/Allele.cpp.o.requires:

.PHONY : CMakeFiles/Generations.dir/src/Allele.cpp.o.requires

CMakeFiles/Generations.dir/src/Allele.cpp.o.provides: CMakeFiles/Generations.dir/src/Allele.cpp.o.requires
	$(MAKE) -f CMakeFiles/Generations.dir/build.make CMakeFiles/Generations.dir/src/Allele.cpp.o.provides.build
.PHONY : CMakeFiles/Generations.dir/src/Allele.cpp.o.provides

CMakeFiles/Generations.dir/src/Allele.cpp.o.provides.build: CMakeFiles/Generations.dir/src/Allele.cpp.o


CMakeFiles/Generations.dir/src/Generation.cpp.o: CMakeFiles/Generations.dir/flags.make
CMakeFiles/Generations.dir/src/Generation.cpp.o: ../src/Generation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Lea/Desktop/Team_5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Generations.dir/src/Generation.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Generations.dir/src/Generation.cpp.o -c /Users/Lea/Desktop/Team_5/src/Generation.cpp

CMakeFiles/Generations.dir/src/Generation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Generations.dir/src/Generation.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Lea/Desktop/Team_5/src/Generation.cpp > CMakeFiles/Generations.dir/src/Generation.cpp.i

CMakeFiles/Generations.dir/src/Generation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Generations.dir/src/Generation.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Lea/Desktop/Team_5/src/Generation.cpp -o CMakeFiles/Generations.dir/src/Generation.cpp.s

CMakeFiles/Generations.dir/src/Generation.cpp.o.requires:

.PHONY : CMakeFiles/Generations.dir/src/Generation.cpp.o.requires

CMakeFiles/Generations.dir/src/Generation.cpp.o.provides: CMakeFiles/Generations.dir/src/Generation.cpp.o.requires
	$(MAKE) -f CMakeFiles/Generations.dir/build.make CMakeFiles/Generations.dir/src/Generation.cpp.o.provides.build
.PHONY : CMakeFiles/Generations.dir/src/Generation.cpp.o.provides

CMakeFiles/Generations.dir/src/Generation.cpp.o.provides.build: CMakeFiles/Generations.dir/src/Generation.cpp.o


CMakeFiles/Generations.dir/src/Simulation.cpp.o: CMakeFiles/Generations.dir/flags.make
CMakeFiles/Generations.dir/src/Simulation.cpp.o: ../src/Simulation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Lea/Desktop/Team_5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Generations.dir/src/Simulation.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Generations.dir/src/Simulation.cpp.o -c /Users/Lea/Desktop/Team_5/src/Simulation.cpp

CMakeFiles/Generations.dir/src/Simulation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Generations.dir/src/Simulation.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Lea/Desktop/Team_5/src/Simulation.cpp > CMakeFiles/Generations.dir/src/Simulation.cpp.i

CMakeFiles/Generations.dir/src/Simulation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Generations.dir/src/Simulation.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Lea/Desktop/Team_5/src/Simulation.cpp -o CMakeFiles/Generations.dir/src/Simulation.cpp.s

CMakeFiles/Generations.dir/src/Simulation.cpp.o.requires:

.PHONY : CMakeFiles/Generations.dir/src/Simulation.cpp.o.requires

CMakeFiles/Generations.dir/src/Simulation.cpp.o.provides: CMakeFiles/Generations.dir/src/Simulation.cpp.o.requires
	$(MAKE) -f CMakeFiles/Generations.dir/build.make CMakeFiles/Generations.dir/src/Simulation.cpp.o.provides.build
.PHONY : CMakeFiles/Generations.dir/src/Simulation.cpp.o.provides

CMakeFiles/Generations.dir/src/Simulation.cpp.o.provides.build: CMakeFiles/Generations.dir/src/Simulation.cpp.o


CMakeFiles/Generations.dir/src/main.cpp.o: CMakeFiles/Generations.dir/flags.make
CMakeFiles/Generations.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Lea/Desktop/Team_5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Generations.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Generations.dir/src/main.cpp.o -c /Users/Lea/Desktop/Team_5/src/main.cpp

CMakeFiles/Generations.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Generations.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Lea/Desktop/Team_5/src/main.cpp > CMakeFiles/Generations.dir/src/main.cpp.i

CMakeFiles/Generations.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Generations.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Lea/Desktop/Team_5/src/main.cpp -o CMakeFiles/Generations.dir/src/main.cpp.s

CMakeFiles/Generations.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/Generations.dir/src/main.cpp.o.requires

CMakeFiles/Generations.dir/src/main.cpp.o.provides: CMakeFiles/Generations.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Generations.dir/build.make CMakeFiles/Generations.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/Generations.dir/src/main.cpp.o.provides

CMakeFiles/Generations.dir/src/main.cpp.o.provides.build: CMakeFiles/Generations.dir/src/main.cpp.o


# Object files for target Generations
Generations_OBJECTS = \
"CMakeFiles/Generations.dir/src/Allele.cpp.o" \
"CMakeFiles/Generations.dir/src/Generation.cpp.o" \
"CMakeFiles/Generations.dir/src/Simulation.cpp.o" \
"CMakeFiles/Generations.dir/src/main.cpp.o"

# External object files for target Generations
Generations_EXTERNAL_OBJECTS =

Generations: CMakeFiles/Generations.dir/src/Allele.cpp.o
Generations: CMakeFiles/Generations.dir/src/Generation.cpp.o
Generations: CMakeFiles/Generations.dir/src/Simulation.cpp.o
Generations: CMakeFiles/Generations.dir/src/main.cpp.o
Generations: CMakeFiles/Generations.dir/build.make
Generations: CMakeFiles/Generations.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Lea/Desktop/Team_5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Generations"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Generations.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Generations.dir/build: Generations

.PHONY : CMakeFiles/Generations.dir/build

CMakeFiles/Generations.dir/requires: CMakeFiles/Generations.dir/src/Allele.cpp.o.requires
CMakeFiles/Generations.dir/requires: CMakeFiles/Generations.dir/src/Generation.cpp.o.requires
CMakeFiles/Generations.dir/requires: CMakeFiles/Generations.dir/src/Simulation.cpp.o.requires
CMakeFiles/Generations.dir/requires: CMakeFiles/Generations.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/Generations.dir/requires

CMakeFiles/Generations.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Generations.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Generations.dir/clean

CMakeFiles/Generations.dir/depend:
	cd /Users/Lea/Desktop/Team_5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Lea/Desktop/Team_5 /Users/Lea/Desktop/Team_5 /Users/Lea/Desktop/Team_5/build /Users/Lea/Desktop/Team_5/build /Users/Lea/Desktop/Team_5/build/CMakeFiles/Generations.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Generations.dir/depend
