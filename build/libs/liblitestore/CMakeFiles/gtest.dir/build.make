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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/markku/repos/liblitestorecpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/markku/repos/liblitestorecpp/build

# Include any dependencies generated for this target.
include libs/liblitestore/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include libs/liblitestore/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include libs/liblitestore/CMakeFiles/gtest.dir/flags.make

libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.o: libs/liblitestore/CMakeFiles/gtest.dir/flags.make
libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.o: ../libs/liblitestore/libs/gtest/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/markku/repos/liblitestorecpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.o"
	cd /home/markku/repos/liblitestorecpp/build/libs/liblitestore && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.o -c /home/markku/repos/liblitestorecpp/libs/liblitestore/libs/gtest/googletest/src/gtest-all.cc

libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.i"
	cd /home/markku/repos/liblitestorecpp/build/libs/liblitestore && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/markku/repos/liblitestorecpp/libs/liblitestore/libs/gtest/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.i

libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.s"
	cd /home/markku/repos/liblitestorecpp/build/libs/liblitestore && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/markku/repos/liblitestorecpp/libs/liblitestore/libs/gtest/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.s

libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.o.requires:

.PHONY : libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.o.requires

libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.o.provides: libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.o.requires
	$(MAKE) -f libs/liblitestore/CMakeFiles/gtest.dir/build.make libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.o.provides.build
.PHONY : libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.o.provides

libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.o.provides.build: libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.o


libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.o: libs/liblitestore/CMakeFiles/gtest.dir/flags.make
libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.o: ../libs/liblitestore/libs/gtest/googletest/src/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/markku/repos/liblitestorecpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.o"
	cd /home/markku/repos/liblitestorecpp/build/libs/liblitestore && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.o -c /home/markku/repos/liblitestorecpp/libs/liblitestore/libs/gtest/googletest/src/gtest_main.cc

libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.i"
	cd /home/markku/repos/liblitestorecpp/build/libs/liblitestore && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/markku/repos/liblitestorecpp/libs/liblitestore/libs/gtest/googletest/src/gtest_main.cc > CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.i

libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.s"
	cd /home/markku/repos/liblitestorecpp/build/libs/liblitestore && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/markku/repos/liblitestorecpp/libs/liblitestore/libs/gtest/googletest/src/gtest_main.cc -o CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.s

libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.o.requires:

.PHONY : libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.o.requires

libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.o.provides: libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.o.requires
	$(MAKE) -f libs/liblitestore/CMakeFiles/gtest.dir/build.make libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.o.provides.build
.PHONY : libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.o.provides

libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.o.provides.build: libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.o


# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.o" \
"CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

libs/liblitestore/libgtest.a: libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.o
libs/liblitestore/libgtest.a: libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.o
libs/liblitestore/libgtest.a: libs/liblitestore/CMakeFiles/gtest.dir/build.make
libs/liblitestore/libgtest.a: libs/liblitestore/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/markku/repos/liblitestorecpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libgtest.a"
	cd /home/markku/repos/liblitestorecpp/build/libs/liblitestore && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /home/markku/repos/liblitestorecpp/build/libs/liblitestore && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/liblitestore/CMakeFiles/gtest.dir/build: libs/liblitestore/libgtest.a

.PHONY : libs/liblitestore/CMakeFiles/gtest.dir/build

libs/liblitestore/CMakeFiles/gtest.dir/requires: libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest-all.cc.o.requires
libs/liblitestore/CMakeFiles/gtest.dir/requires: libs/liblitestore/CMakeFiles/gtest.dir/libs/gtest/googletest/src/gtest_main.cc.o.requires

.PHONY : libs/liblitestore/CMakeFiles/gtest.dir/requires

libs/liblitestore/CMakeFiles/gtest.dir/clean:
	cd /home/markku/repos/liblitestorecpp/build/libs/liblitestore && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : libs/liblitestore/CMakeFiles/gtest.dir/clean

libs/liblitestore/CMakeFiles/gtest.dir/depend:
	cd /home/markku/repos/liblitestorecpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/markku/repos/liblitestorecpp /home/markku/repos/liblitestorecpp/libs/liblitestore /home/markku/repos/liblitestorecpp/build /home/markku/repos/liblitestorecpp/build/libs/liblitestore /home/markku/repos/liblitestorecpp/build/libs/liblitestore/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/liblitestore/CMakeFiles/gtest.dir/depend
