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
include tests/CMakeFiles/test_litestorecpp.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_litestorecpp.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_litestorecpp.dir/flags.make

tests/CMakeFiles/test_litestorecpp.dir/main.cpp.o: tests/CMakeFiles/test_litestorecpp.dir/flags.make
tests/CMakeFiles/test_litestorecpp.dir/main.cpp.o: ../tests/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/markku/repos/liblitestorecpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/test_litestorecpp.dir/main.cpp.o"
	cd /home/markku/repos/liblitestorecpp/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_litestorecpp.dir/main.cpp.o -c /home/markku/repos/liblitestorecpp/tests/main.cpp

tests/CMakeFiles/test_litestorecpp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_litestorecpp.dir/main.cpp.i"
	cd /home/markku/repos/liblitestorecpp/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/markku/repos/liblitestorecpp/tests/main.cpp > CMakeFiles/test_litestorecpp.dir/main.cpp.i

tests/CMakeFiles/test_litestorecpp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_litestorecpp.dir/main.cpp.s"
	cd /home/markku/repos/liblitestorecpp/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/markku/repos/liblitestorecpp/tests/main.cpp -o CMakeFiles/test_litestorecpp.dir/main.cpp.s

tests/CMakeFiles/test_litestorecpp.dir/main.cpp.o.requires:

.PHONY : tests/CMakeFiles/test_litestorecpp.dir/main.cpp.o.requires

tests/CMakeFiles/test_litestorecpp.dir/main.cpp.o.provides: tests/CMakeFiles/test_litestorecpp.dir/main.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/test_litestorecpp.dir/build.make tests/CMakeFiles/test_litestorecpp.dir/main.cpp.o.provides.build
.PHONY : tests/CMakeFiles/test_litestorecpp.dir/main.cpp.o.provides

tests/CMakeFiles/test_litestorecpp.dir/main.cpp.o.provides.build: tests/CMakeFiles/test_litestorecpp.dir/main.cpp.o


tests/CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.o: tests/CMakeFiles/test_litestorecpp.dir/flags.make
tests/CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.o: ../tests/litestorecpp_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/markku/repos/liblitestorecpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.o"
	cd /home/markku/repos/liblitestorecpp/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.o -c /home/markku/repos/liblitestorecpp/tests/litestorecpp_test.cpp

tests/CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.i"
	cd /home/markku/repos/liblitestorecpp/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/markku/repos/liblitestorecpp/tests/litestorecpp_test.cpp > CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.i

tests/CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.s"
	cd /home/markku/repos/liblitestorecpp/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/markku/repos/liblitestorecpp/tests/litestorecpp_test.cpp -o CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.s

tests/CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.o.requires:

.PHONY : tests/CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.o.requires

tests/CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.o.provides: tests/CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/test_litestorecpp.dir/build.make tests/CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.o.provides.build
.PHONY : tests/CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.o.provides

tests/CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.o.provides.build: tests/CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.o


# Object files for target test_litestorecpp
test_litestorecpp_OBJECTS = \
"CMakeFiles/test_litestorecpp.dir/main.cpp.o" \
"CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.o"

# External object files for target test_litestorecpp
test_litestorecpp_EXTERNAL_OBJECTS =

tests/test_litestorecpp: tests/CMakeFiles/test_litestorecpp.dir/main.cpp.o
tests/test_litestorecpp: tests/CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.o
tests/test_litestorecpp: tests/CMakeFiles/test_litestorecpp.dir/build.make
tests/test_litestorecpp: liblitestorecpp.so
tests/test_litestorecpp: libs/liblitestore/liblitestore.so
tests/test_litestorecpp: tests/CMakeFiles/test_litestorecpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/markku/repos/liblitestorecpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable test_litestorecpp"
	cd /home/markku/repos/liblitestorecpp/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_litestorecpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test_litestorecpp.dir/build: tests/test_litestorecpp

.PHONY : tests/CMakeFiles/test_litestorecpp.dir/build

tests/CMakeFiles/test_litestorecpp.dir/requires: tests/CMakeFiles/test_litestorecpp.dir/main.cpp.o.requires
tests/CMakeFiles/test_litestorecpp.dir/requires: tests/CMakeFiles/test_litestorecpp.dir/litestorecpp_test.cpp.o.requires

.PHONY : tests/CMakeFiles/test_litestorecpp.dir/requires

tests/CMakeFiles/test_litestorecpp.dir/clean:
	cd /home/markku/repos/liblitestorecpp/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_litestorecpp.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_litestorecpp.dir/clean

tests/CMakeFiles/test_litestorecpp.dir/depend:
	cd /home/markku/repos/liblitestorecpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/markku/repos/liblitestorecpp /home/markku/repos/liblitestorecpp/tests /home/markku/repos/liblitestorecpp/build /home/markku/repos/liblitestorecpp/build/tests /home/markku/repos/liblitestorecpp/build/tests/CMakeFiles/test_litestorecpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/test_litestorecpp.dir/depend
