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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/skloe/Documents/Coding/网络/tcpip/iterative_server/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/skloe/Documents/Coding/网络/tcpip/iterative_server/test/build

# Include any dependencies generated for this target.
include CMakeFiles/testtcpserver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testtcpserver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testtcpserver.dir/flags.make

CMakeFiles/testtcpserver.dir/testtcpserver.cc.o: CMakeFiles/testtcpserver.dir/flags.make
CMakeFiles/testtcpserver.dir/testtcpserver.cc.o: ../testtcpserver.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/skloe/Documents/Coding/网络/tcpip/iterative_server/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testtcpserver.dir/testtcpserver.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testtcpserver.dir/testtcpserver.cc.o -c /home/skloe/Documents/Coding/网络/tcpip/iterative_server/test/testtcpserver.cc

CMakeFiles/testtcpserver.dir/testtcpserver.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testtcpserver.dir/testtcpserver.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/skloe/Documents/Coding/网络/tcpip/iterative_server/test/testtcpserver.cc > CMakeFiles/testtcpserver.dir/testtcpserver.cc.i

CMakeFiles/testtcpserver.dir/testtcpserver.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testtcpserver.dir/testtcpserver.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/skloe/Documents/Coding/网络/tcpip/iterative_server/test/testtcpserver.cc -o CMakeFiles/testtcpserver.dir/testtcpserver.cc.s

# Object files for target testtcpserver
testtcpserver_OBJECTS = \
"CMakeFiles/testtcpserver.dir/testtcpserver.cc.o"

# External object files for target testtcpserver
testtcpserver_EXTERNAL_OBJECTS =

testtcpserver: CMakeFiles/testtcpserver.dir/testtcpserver.cc.o
testtcpserver: CMakeFiles/testtcpserver.dir/build.make
testtcpserver: CMakeFiles/testtcpserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/skloe/Documents/Coding/网络/tcpip/iterative_server/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testtcpserver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testtcpserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testtcpserver.dir/build: testtcpserver

.PHONY : CMakeFiles/testtcpserver.dir/build

CMakeFiles/testtcpserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testtcpserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testtcpserver.dir/clean

CMakeFiles/testtcpserver.dir/depend:
	cd /home/skloe/Documents/Coding/网络/tcpip/iterative_server/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/skloe/Documents/Coding/网络/tcpip/iterative_server/test /home/skloe/Documents/Coding/网络/tcpip/iterative_server/test /home/skloe/Documents/Coding/网络/tcpip/iterative_server/test/build /home/skloe/Documents/Coding/网络/tcpip/iterative_server/test/build /home/skloe/Documents/Coding/网络/tcpip/iterative_server/test/build/CMakeFiles/testtcpserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testtcpserver.dir/depend

