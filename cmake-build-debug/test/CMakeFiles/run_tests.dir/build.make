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

# Utility rule file for run_tests.

# Include any custom commands dependencies for this target.
include test/CMakeFiles/run_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/run_tests.dir/progress.make

test/CMakeFiles/run_tests:
	cd /Users/frederikke/Documents/GitHub/fitness/cmake-build-debug/test && ./test_load_user test_save_user test_returning_user test_update_user_files test_calculate_id test_display_recommendation test_adjust_recommendation

run_tests: test/CMakeFiles/run_tests
run_tests: test/CMakeFiles/run_tests.dir/build.make
.PHONY : run_tests

# Rule to build all files generated by this target.
test/CMakeFiles/run_tests.dir/build: run_tests
.PHONY : test/CMakeFiles/run_tests.dir/build

test/CMakeFiles/run_tests.dir/clean:
	cd /Users/frederikke/Documents/GitHub/fitness/cmake-build-debug/test && $(CMAKE_COMMAND) -P CMakeFiles/run_tests.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/run_tests.dir/clean

test/CMakeFiles/run_tests.dir/depend:
	cd /Users/frederikke/Documents/GitHub/fitness/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/frederikke/Documents/GitHub/fitness /Users/frederikke/Documents/GitHub/fitness/test /Users/frederikke/Documents/GitHub/fitness/cmake-build-debug /Users/frederikke/Documents/GitHub/fitness/cmake-build-debug/test /Users/frederikke/Documents/GitHub/fitness/cmake-build-debug/test/CMakeFiles/run_tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/CMakeFiles/run_tests.dir/depend
