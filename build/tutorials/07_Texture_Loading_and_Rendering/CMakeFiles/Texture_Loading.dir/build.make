# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build

# Include any dependencies generated for this target.
include tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/compiler_depend.make

# Include the progress variables for this target.
include tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/progress.make

# Include the compile flags for this target's objects.
include tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/flags.make

tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/main.cpp.o: tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/flags.make
tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/main.cpp.o: ../tutorials/07_Texture_Loading_and_Rendering/main.cpp
tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/main.cpp.o: tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/main.cpp.o"
	cd /home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/07_Texture_Loading_and_Rendering && /bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/main.cpp.o -MF CMakeFiles/Texture_Loading.dir/main.cpp.o.d -o CMakeFiles/Texture_Loading.dir/main.cpp.o -c /home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/tutorials/07_Texture_Loading_and_Rendering/main.cpp

tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Texture_Loading.dir/main.cpp.i"
	cd /home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/07_Texture_Loading_and_Rendering && /bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/tutorials/07_Texture_Loading_and_Rendering/main.cpp > CMakeFiles/Texture_Loading.dir/main.cpp.i

tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Texture_Loading.dir/main.cpp.s"
	cd /home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/07_Texture_Loading_and_Rendering && /bin/clang++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/tutorials/07_Texture_Loading_and_Rendering/main.cpp -o CMakeFiles/Texture_Loading.dir/main.cpp.s

# Object files for target Texture_Loading
Texture_Loading_OBJECTS = \
"CMakeFiles/Texture_Loading.dir/main.cpp.o"

# External object files for target Texture_Loading
Texture_Loading_EXTERNAL_OBJECTS =

tutorials/07_Texture_Loading_and_Rendering/Texture_Loading: tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/main.cpp.o
tutorials/07_Texture_Loading_and_Rendering/Texture_Loading: tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/build.make
tutorials/07_Texture_Loading_and_Rendering/Texture_Loading: tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Texture_Loading"
	cd /home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/07_Texture_Loading_and_Rendering && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Texture_Loading.dir/link.txt --verbose=$(VERBOSE)
	cd /home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/07_Texture_Loading_and_Rendering && /usr/local/bin/cmake -E copy /home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/tutorials/07_Texture_Loading_and_Rendering/5.jpg /home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/07_Texture_Loading_and_Rendering

# Rule to build all files generated by this target.
tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/build: tutorials/07_Texture_Loading_and_Rendering/Texture_Loading
.PHONY : tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/build

tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/clean:
	cd /home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/07_Texture_Loading_and_Rendering && $(CMAKE_COMMAND) -P CMakeFiles/Texture_Loading.dir/cmake_clean.cmake
.PHONY : tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/clean

tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/depend:
	cd /home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo /home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/tutorials/07_Texture_Loading_and_Rendering /home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build /home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/07_Texture_Loading_and_Rendering /home/marklaurente/Documents/Programming/C++/GitHubRepositories/SDL2_Lazy_Foo/build/tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tutorials/07_Texture_Loading_and_Rendering/CMakeFiles/Texture_Loading.dir/depend

