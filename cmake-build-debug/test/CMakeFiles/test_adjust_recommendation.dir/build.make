# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/frederikke/Documents/GitHub/fitness

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/frederikke/Documents/GitHub/fitness/cmake-build-debug

# Include any dependencies generated for this target.
include test/CMakeFiles/test_adjust_recommendation.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/test_adjust_recommendation.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_adjust_recommendation.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_adjust_recommendation.dir/flags.make

test/CMakeFiles/test_adjust_recommendation.dir/test_adjust_recommendation.c.o: test/CMakeFiles/test_adjust_recommendation.dir/flags.make
test/CMakeFiles/test_adjust_recommendation.dir/test_adjust_recommendation.c.o: /Users/frederikke/Documents/GitHub/fitness/test/test_adjust_recommendation.c
test/CMakeFiles/test_adjust_recommendation.dir/test_adjust_recommendation.c.o: test/CMakeFiles/test_adjust_recommendation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/frederikke/Documents/GitHub/fitness/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object test/CMakeFiles/test_adjust_recommendation.dir/test_adjust_recommendation.c.o"
	cd /Users/frederikke/Documents/GitHub/fitness/cmake-build-debug/test && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT test/CMakeFiles/test_adjust_recommendation.dir/test_adjust_recommendation.c.o -MF CMakeFiles/test_adjust_recommendation.dir/test_adjust_recommendation.c.o.d -o CMakeFiles/test_adjust_recommendation.dir/test_adjust_recommendation.c.o -c /Users/frederikke/Documents/GitHub/fitness/test/test_adjust_recommendation.c

test/CMakeFiles/test_adjust_recommendation.dir/test_adjust_recommendation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_adjust_recommendation.dir/test_adjust_recommendation.c.i"
	cd /Users/frederikke/Documents/GitHub/fitness/cmake-build-debug/test && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/frederikke/Documents/GitHub/fitness/test/test_adjust_recommendation.c > CMakeFiles/test_adjust_recommendation.dir/test_adjust_recommendation.c.i

test/CMakeFiles/test_adjust_recommendation.dir/test_adjust_recommendation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_adjust_recommendation.dir/test_adjust_recommendation.c.s"
	cd /Users/frederikke/Documents/GitHub/fitness/cmake-build-debug/test && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/frederikke/Documents/GitHub/fitness/test/test_adjust_recommendation.c -o CMakeFiles/test_adjust_recommendation.dir/test_adjust_recommendation.c.s

# Object files for target test_adjust_recommendation
test_adjust_recommendation_OBJECTS = \
"CMakeFiles/test_adjust_recommendation.dir/test_adjust_recommendation.c.o"

# External object files for target test_adjust_recommendation
test_adjust_recommendation_EXTERNAL_OBJECTS =

test/test_adjust_recommendation: test/CMakeFiles/test_adjust_recommendation.dir/test_adjust_recommendation.c.o
test/test_adjust_recommendation: test/CMakeFiles/test_adjust_recommendation.dir/build.make
test/test_adjust_recommendation: src/librecommendation.a
test/test_adjust_recommendation: test/CMakeFiles/test_adjust_recommendation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/frederikke/Documents/GitHub/fitness/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test_adjust_recommendation"
	cd /Users/frederikke/Documents/GitHub/fitness/cmake-build-debug/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_adjust_recommendation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test_adjust_recommendation.dir/build: test/test_adjust_recommendation
.PHONY : test/CMakeFiles/test_adjust_recommendation.dir/build

test/CMakeFiles/test_adjust_recommendation.dir/clean:
	cd /Users/frederikke/Documents/GitHub/fitness/cmake-build-debug/test && $(CMAKE_COMMAND) -P CMakeFiles/test_adjust_recommendation.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test_adjust_recommendation.dir/clean

test/CMakeFiles/test_adjust_recommendation.dir/depend:
	cd /Users/frederikke/Documents/GitHub/fitness/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/frederikke/Documents/GitHub/fitness /Users/frederikke/Documents/GitHub/fitness/test /Users/frederikke/Documents/GitHub/fitness/cmake-build-debug /Users/frederikke/Documents/GitHub/fitness/cmake-build-debug/test /Users/frederikke/Documents/GitHub/fitness/cmake-build-debug/test/CMakeFiles/test_adjust_recommendation.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/CMakeFiles/test_adjust_recommendation.dir/depend

