# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\cmake\cmake-3.21.3-windows-x86_64\bin\cmake.exe

# The command to remove a file.
RM = C:\cmake\cmake-3.21.3-windows-x86_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\user\C++Projects\Application-Development-with-C++\Hello_SDL2_World

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\user\C++Projects\Application-Development-with-C++\Hello_SDL2_World\build

# Include any dependencies generated for this target.
include CMakeFiles/hello_sdl2_world.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hello_sdl2_world.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hello_sdl2_world.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello_sdl2_world.dir/flags.make

CMakeFiles/hello_sdl2_world.dir/main.cpp.obj: CMakeFiles/hello_sdl2_world.dir/flags.make
CMakeFiles/hello_sdl2_world.dir/main.cpp.obj: CMakeFiles/hello_sdl2_world.dir/includes_CXX.rsp
CMakeFiles/hello_sdl2_world.dir/main.cpp.obj: ../main.cpp
CMakeFiles/hello_sdl2_world.dir/main.cpp.obj: CMakeFiles/hello_sdl2_world.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\user\C++Projects\Application-Development-with-C++\Hello_SDL2_World\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hello_sdl2_world.dir/main.cpp.obj"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hello_sdl2_world.dir/main.cpp.obj -MF CMakeFiles\hello_sdl2_world.dir\main.cpp.obj.d -o CMakeFiles\hello_sdl2_world.dir\main.cpp.obj -c C:\Users\user\C++Projects\Application-Development-with-C++\Hello_SDL2_World\main.cpp

CMakeFiles/hello_sdl2_world.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello_sdl2_world.dir/main.cpp.i"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\user\C++Projects\Application-Development-with-C++\Hello_SDL2_World\main.cpp > CMakeFiles\hello_sdl2_world.dir\main.cpp.i

CMakeFiles/hello_sdl2_world.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello_sdl2_world.dir/main.cpp.s"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\user\C++Projects\Application-Development-with-C++\Hello_SDL2_World\main.cpp -o CMakeFiles\hello_sdl2_world.dir\main.cpp.s

# Object files for target hello_sdl2_world
hello_sdl2_world_OBJECTS = \
"CMakeFiles/hello_sdl2_world.dir/main.cpp.obj"

# External object files for target hello_sdl2_world
hello_sdl2_world_EXTERNAL_OBJECTS =

hello_sdl2_world.exe: CMakeFiles/hello_sdl2_world.dir/main.cpp.obj
hello_sdl2_world.exe: CMakeFiles/hello_sdl2_world.dir/build.make
hello_sdl2_world.exe: C:/mingw_dev_libs/lib/libSDL2main.a
hello_sdl2_world.exe: C:/mingw_dev_libs/lib/libSDL2.dll.a
hello_sdl2_world.exe: C:/mingw_dev_libs/lib/libSDL2_image.dll.a
hello_sdl2_world.exe: C:/mingw_dev_libs/lib/libSDL2_ttf.dll.a
hello_sdl2_world.exe: C:/mingw_dev_libs/lib/libSDL2_mixer.dll.a
hello_sdl2_world.exe: CMakeFiles/hello_sdl2_world.dir/linklibs.rsp
hello_sdl2_world.exe: CMakeFiles/hello_sdl2_world.dir/objects1.rsp
hello_sdl2_world.exe: CMakeFiles/hello_sdl2_world.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\user\C++Projects\Application-Development-with-C++\Hello_SDL2_World\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hello_sdl2_world.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\hello_sdl2_world.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello_sdl2_world.dir/build: hello_sdl2_world.exe
.PHONY : CMakeFiles/hello_sdl2_world.dir/build

CMakeFiles/hello_sdl2_world.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\hello_sdl2_world.dir\cmake_clean.cmake
.PHONY : CMakeFiles/hello_sdl2_world.dir/clean

CMakeFiles/hello_sdl2_world.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\user\C++Projects\Application-Development-with-C++\Hello_SDL2_World C:\Users\user\C++Projects\Application-Development-with-C++\Hello_SDL2_World C:\Users\user\C++Projects\Application-Development-with-C++\Hello_SDL2_World\build C:\Users\user\C++Projects\Application-Development-with-C++\Hello_SDL2_World\build C:\Users\user\C++Projects\Application-Development-with-C++\Hello_SDL2_World\build\CMakeFiles\hello_sdl2_world.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello_sdl2_world.dir/depend
