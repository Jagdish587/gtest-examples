# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jagdish/gtest-setup

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jagdish/gtest-setup

# Utility rule file for launch-coverage-report.

# Include the progress variables for this target.
include test/CMakeFiles/launch-coverage-report.dir/progress.make

test/CMakeFiles/launch-coverage-report:
	firefox /home/jagdish/gtest-setup/coverage/res/index.html

launch-coverage-report: test/CMakeFiles/launch-coverage-report
launch-coverage-report: test/CMakeFiles/launch-coverage-report.dir/build.make

.PHONY : launch-coverage-report

# Rule to build all files generated by this target.
test/CMakeFiles/launch-coverage-report.dir/build: launch-coverage-report

.PHONY : test/CMakeFiles/launch-coverage-report.dir/build

test/CMakeFiles/launch-coverage-report.dir/clean:
	cd /home/jagdish/gtest-setup/test && $(CMAKE_COMMAND) -P CMakeFiles/launch-coverage-report.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/launch-coverage-report.dir/clean

test/CMakeFiles/launch-coverage-report.dir/depend:
	cd /home/jagdish/gtest-setup && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jagdish/gtest-setup /home/jagdish/gtest-setup/test /home/jagdish/gtest-setup /home/jagdish/gtest-setup/test /home/jagdish/gtest-setup/test/CMakeFiles/launch-coverage-report.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/launch-coverage-report.dir/depend

