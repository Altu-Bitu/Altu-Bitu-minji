# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Kang Minji\OneDrive\Github\Altu-Bitu-minji\[Two-Pointer] 1012"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Kang Minji\OneDrive\Github\Altu-Bitu-minji\[Two-Pointer] 1012\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/_Two_Pointer__1012.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/_Two_Pointer__1012.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/_Two_Pointer__1012.dir/flags.make

CMakeFiles/_Two_Pointer__1012.dir/assignments/2607.cpp.obj: CMakeFiles/_Two_Pointer__1012.dir/flags.make
CMakeFiles/_Two_Pointer__1012.dir/assignments/2607.cpp.obj: ../assignments/2607.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Kang Minji\OneDrive\Github\Altu-Bitu-minji\[Two-Pointer] 1012\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/_Two_Pointer__1012.dir/assignments/2607.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\_Two_Pointer__1012.dir\assignments\2607.cpp.obj -c "C:\Users\Kang Minji\OneDrive\Github\Altu-Bitu-minji\[Two-Pointer] 1012\assignments\2607.cpp"

CMakeFiles/_Two_Pointer__1012.dir/assignments/2607.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/_Two_Pointer__1012.dir/assignments/2607.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Kang Minji\OneDrive\Github\Altu-Bitu-minji\[Two-Pointer] 1012\assignments\2607.cpp" > CMakeFiles\_Two_Pointer__1012.dir\assignments\2607.cpp.i

CMakeFiles/_Two_Pointer__1012.dir/assignments/2607.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/_Two_Pointer__1012.dir/assignments/2607.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Kang Minji\OneDrive\Github\Altu-Bitu-minji\[Two-Pointer] 1012\assignments\2607.cpp" -o CMakeFiles\_Two_Pointer__1012.dir\assignments\2607.cpp.s

# Object files for target _Two_Pointer__1012
_Two_Pointer__1012_OBJECTS = \
"CMakeFiles/_Two_Pointer__1012.dir/assignments/2607.cpp.obj"

# External object files for target _Two_Pointer__1012
_Two_Pointer__1012_EXTERNAL_OBJECTS =

_Two_Pointer__1012.exe: CMakeFiles/_Two_Pointer__1012.dir/assignments/2607.cpp.obj
_Two_Pointer__1012.exe: CMakeFiles/_Two_Pointer__1012.dir/build.make
_Two_Pointer__1012.exe: CMakeFiles/_Two_Pointer__1012.dir/linklibs.rsp
_Two_Pointer__1012.exe: CMakeFiles/_Two_Pointer__1012.dir/objects1.rsp
_Two_Pointer__1012.exe: CMakeFiles/_Two_Pointer__1012.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Kang Minji\OneDrive\Github\Altu-Bitu-minji\[Two-Pointer] 1012\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable _Two_Pointer__1012.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\_Two_Pointer__1012.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/_Two_Pointer__1012.dir/build: _Two_Pointer__1012.exe
.PHONY : CMakeFiles/_Two_Pointer__1012.dir/build

CMakeFiles/_Two_Pointer__1012.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\_Two_Pointer__1012.dir\cmake_clean.cmake
.PHONY : CMakeFiles/_Two_Pointer__1012.dir/clean

CMakeFiles/_Two_Pointer__1012.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Kang Minji\OneDrive\Github\Altu-Bitu-minji\[Two-Pointer] 1012" "C:\Users\Kang Minji\OneDrive\Github\Altu-Bitu-minji\[Two-Pointer] 1012" "C:\Users\Kang Minji\OneDrive\Github\Altu-Bitu-minji\[Two-Pointer] 1012\cmake-build-debug" "C:\Users\Kang Minji\OneDrive\Github\Altu-Bitu-minji\[Two-Pointer] 1012\cmake-build-debug" "C:\Users\Kang Minji\OneDrive\Github\Altu-Bitu-minji\[Two-Pointer] 1012\cmake-build-debug\CMakeFiles\_Two_Pointer__1012.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/_Two_Pointer__1012.dir/depend

