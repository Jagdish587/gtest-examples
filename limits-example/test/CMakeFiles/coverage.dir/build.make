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

# Utility rule file for coverage.

# Include the progress variables for this target.
include test/CMakeFiles/coverage.dir/progress.make

test/CMakeFiles/coverage:
	lcov -c -d . -o main_coverage.info --no-external
	genhtml -o res main_coverage.info
	rm -rf /home/jagdish/gtest-setup/coverage
	mkdir -p /home/jagdish/gtest-setup/coverage
	mv main_coverage.info /home/jagdish/gtest-setup/coverage
	mv res /home/jagdish/gtest-setup/coverage

coverage: test/CMakeFiles/coverage
coverage: test/CMakeFiles/coverage.dir/build.make

.PHONY : coverage

# Rule to build all files generated by this target.
test/CMakeFiles/coverage.dir/build: coverage

.PHONY : test/CMakeFiles/coverage.dir/build

test/CMakeFiles/coverage.dir/clean:
	cd /home/jagdish/gtest-setup/test && $(CMAKE_COMMAND) -P CMakeFiles/coverage.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/coverage.dir/clean

test/CMakeFiles/coverage.dir/depend:
	cd /home/jagdish/gtest-setup && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jagdish/gtest-setup /home/jagdish/gtest-setup/test /home/jagdish/gtest-setup /home/jagdish/gtest-setup/test /home/jagdish/gtest-setup/test/CMakeFiles/coverage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/coverage.dir/depend
