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
CMAKE_SOURCE_DIR = /Users/celina/Documents/GitHub/fitness

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/celina/Documents/GitHub/fitness/cmake-build-debug

# Include any dependencies generated for this target.
include test/CMakeFiles/test_returning_user.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/test_returning_user.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_returning_user.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_returning_user.dir/flags.make

test/CMakeFiles/test_returning_user.dir/test_returning_user.c.o: test/CMakeFiles/test_returning_user.dir/flags.make
test/CMakeFiles/test_returning_user.dir/test_returning_user.c.o: /Users/celina/Documents/GitHub/fitness/test/test_returning_user.c
test/CMakeFiles/test_returning_user.dir/test_returning_user.c.o: test/CMakeFiles/test_returning_user.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/celina/Documents/GitHub/fitness/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object test/CMakeFiles/test_returning_user.dir/test_returning_user.c.o"
	cd /Users/celina/Documents/GitHub/fitness/cmake-build-debug/test && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT test/CMakeFiles/test_returning_user.dir/test_returning_user.c.o -MF CMakeFiles/test_returning_user.dir/test_returning_user.c.o.d -o CMakeFiles/test_returning_user.dir/test_returning_user.c.o -c /Users/celina/Documents/GitHub/fitness/test/test_returning_user.c

test/CMakeFiles/test_returning_user.dir/test_returning_user.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_returning_user.dir/test_returning_user.c.i"
	cd /Users/celina/Documents/GitHub/fitness/cmake-build-debug/test && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/celina/Documents/GitHub/fitness/test/test_returning_user.c > CMakeFiles/test_returning_user.dir/test_returning_user.c.i

test/CMakeFiles/test_returning_user.dir/test_returning_user.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_returning_user.dir/test_returning_user.c.s"
	cd /Users/celina/Documents/GitHub/fitness/cmake-build-debug/test && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/celina/Documents/GitHub/fitness/test/test_returning_user.c -o CMakeFiles/test_returning_user.dir/test_returning_user.c.s

# Object files for target test_returning_user
test_returning_user_OBJECTS = \
"CMakeFiles/test_returning_user.dir/test_returning_user.c.o"

# External object files for target test_returning_user
test_returning_user_EXTERNAL_OBJECTS =

test/test_returning_user: test/CMakeFiles/test_returning_user.dir/test_returning_user.c.o
test/test_returning_user: test/CMakeFiles/test_returning_user.dir/build.make
test/test_returning_user: src/librecommendation.a
test/test_returning_user: test/CMakeFiles/test_returning_user.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/celina/Documents/GitHub/fitness/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test_returning_user"
	cd /Users/celina/Documents/GitHub/fitness/cmake-build-debug/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_returning_user.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test_returning_user.dir/build: test/test_returning_user
.PHONY : test/CMakeFiles/test_returning_user.dir/build

test/CMakeFiles/test_returning_user.dir/clean:
	cd /Users/celina/Documents/GitHub/fitness/cmake-build-debug/test && $(CMAKE_COMMAND) -P CMakeFiles/test_returning_user.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test_returning_user.dir/clean

test/CMakeFiles/test_returning_user.dir/depend:
	cd /Users/celina/Documents/GitHub/fitness/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/celina/Documents/GitHub/fitness /Users/celina/Documents/GitHub/fitness/test /Users/celina/Documents/GitHub/fitness/cmake-build-debug /Users/celina/Documents/GitHub/fitness/cmake-build-debug/test /Users/celina/Documents/GitHub/fitness/cmake-build-debug/test/CMakeFiles/test_returning_user.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/CMakeFiles/test_returning_user.dir/depend

