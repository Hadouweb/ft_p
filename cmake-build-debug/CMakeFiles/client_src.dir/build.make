# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nle-bret/project/ft_p

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nle-bret/project/ft_p/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/client_src.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client_src.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client_src.dir/flags.make

CMakeFiles/client_src.dir/client_src/srcs/main.c.o: CMakeFiles/client_src.dir/flags.make
CMakeFiles/client_src.dir/client_src/srcs/main.c.o: ../client_src/srcs/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nle-bret/project/ft_p/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/client_src.dir/client_src/srcs/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/client_src.dir/client_src/srcs/main.c.o   -c /Users/nle-bret/project/ft_p/client_src/srcs/main.c

CMakeFiles/client_src.dir/client_src/srcs/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/client_src.dir/client_src/srcs/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nle-bret/project/ft_p/client_src/srcs/main.c > CMakeFiles/client_src.dir/client_src/srcs/main.c.i

CMakeFiles/client_src.dir/client_src/srcs/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/client_src.dir/client_src/srcs/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nle-bret/project/ft_p/client_src/srcs/main.c -o CMakeFiles/client_src.dir/client_src/srcs/main.c.s

CMakeFiles/client_src.dir/client_src/srcs/main.c.o.requires:

.PHONY : CMakeFiles/client_src.dir/client_src/srcs/main.c.o.requires

CMakeFiles/client_src.dir/client_src/srcs/main.c.o.provides: CMakeFiles/client_src.dir/client_src/srcs/main.c.o.requires
	$(MAKE) -f CMakeFiles/client_src.dir/build.make CMakeFiles/client_src.dir/client_src/srcs/main.c.o.provides.build
.PHONY : CMakeFiles/client_src.dir/client_src/srcs/main.c.o.provides

CMakeFiles/client_src.dir/client_src/srcs/main.c.o.provides.build: CMakeFiles/client_src.dir/client_src/srcs/main.c.o


# Object files for target client_src
client_src_OBJECTS = \
"CMakeFiles/client_src.dir/client_src/srcs/main.c.o"

# External object files for target client_src
client_src_EXTERNAL_OBJECTS =

client_src: CMakeFiles/client_src.dir/client_src/srcs/main.c.o
client_src: CMakeFiles/client_src.dir/build.make
client_src: CMakeFiles/client_src.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nle-bret/project/ft_p/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable client_src"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client_src.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client_src.dir/build: client_src

.PHONY : CMakeFiles/client_src.dir/build

CMakeFiles/client_src.dir/requires: CMakeFiles/client_src.dir/client_src/srcs/main.c.o.requires

.PHONY : CMakeFiles/client_src.dir/requires

CMakeFiles/client_src.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client_src.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client_src.dir/clean

CMakeFiles/client_src.dir/depend:
	cd /Users/nle-bret/project/ft_p/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nle-bret/project/ft_p /Users/nle-bret/project/ft_p /Users/nle-bret/project/ft_p/cmake-build-debug /Users/nle-bret/project/ft_p/cmake-build-debug /Users/nle-bret/project/ft_p/cmake-build-debug/CMakeFiles/client_src.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client_src.dir/depend
