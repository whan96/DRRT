# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.5.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.5.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/corinsandford/ARPG/DRRT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/corinsandford/ARPG/DRRT

# Include any dependencies generated for this target.
include CMakeFiles/listtest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/listtest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/listtest.dir/flags.make

CMakeFiles/listtest.dir/src/list.cpp.o: CMakeFiles/listtest.dir/flags.make
CMakeFiles/listtest.dir/src/list.cpp.o: src/list.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/corinsandford/ARPG/DRRT/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/listtest.dir/src/list.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/listtest.dir/src/list.cpp.o -c /Users/corinsandford/ARPG/DRRT/src/list.cpp

CMakeFiles/listtest.dir/src/list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/listtest.dir/src/list.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/corinsandford/ARPG/DRRT/src/list.cpp > CMakeFiles/listtest.dir/src/list.cpp.i

CMakeFiles/listtest.dir/src/list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/listtest.dir/src/list.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/corinsandford/ARPG/DRRT/src/list.cpp -o CMakeFiles/listtest.dir/src/list.cpp.s

CMakeFiles/listtest.dir/src/list.cpp.o.requires:

.PHONY : CMakeFiles/listtest.dir/src/list.cpp.o.requires

CMakeFiles/listtest.dir/src/list.cpp.o.provides: CMakeFiles/listtest.dir/src/list.cpp.o.requires
	$(MAKE) -f CMakeFiles/listtest.dir/build.make CMakeFiles/listtest.dir/src/list.cpp.o.provides.build
.PHONY : CMakeFiles/listtest.dir/src/list.cpp.o.provides

CMakeFiles/listtest.dir/src/list.cpp.o.provides.build: CMakeFiles/listtest.dir/src/list.cpp.o


# Object files for target listtest
listtest_OBJECTS = \
"CMakeFiles/listtest.dir/src/list.cpp.o"

# External object files for target listtest
listtest_EXTERNAL_OBJECTS =

listtest: CMakeFiles/listtest.dir/src/list.cpp.o
listtest: CMakeFiles/listtest.dir/build.make
listtest: libdrrt.a
listtest: CMakeFiles/listtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/corinsandford/ARPG/DRRT/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable listtest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/listtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/listtest.dir/build: listtest

.PHONY : CMakeFiles/listtest.dir/build

CMakeFiles/listtest.dir/requires: CMakeFiles/listtest.dir/src/list.cpp.o.requires

.PHONY : CMakeFiles/listtest.dir/requires

CMakeFiles/listtest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/listtest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/listtest.dir/clean

CMakeFiles/listtest.dir/depend:
	cd /Users/corinsandford/ARPG/DRRT && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/corinsandford/ARPG/DRRT /Users/corinsandford/ARPG/DRRT /Users/corinsandford/ARPG/DRRT /Users/corinsandford/ARPG/DRRT /Users/corinsandford/ARPG/DRRT/CMakeFiles/listtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/listtest.dir/depend

