# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Mr\CLion-Projects-workspace\COMP_3511_PA2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Mr\CLion-Projects-workspace\COMP_3511_PA2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/COMP_3511_PA2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/COMP_3511_PA2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/COMP_3511_PA2.dir/flags.make

CMakeFiles/COMP_3511_PA2.dir/banker_safety.c.obj: CMakeFiles/COMP_3511_PA2.dir/flags.make
CMakeFiles/COMP_3511_PA2.dir/banker_safety.c.obj: ../banker_safety.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Mr\CLion-Projects-workspace\COMP_3511_PA2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/COMP_3511_PA2.dir/banker_safety.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\COMP_3511_PA2.dir\banker_safety.c.obj   -c C:\Users\Mr\CLion-Projects-workspace\COMP_3511_PA2\banker_safety.c

CMakeFiles/COMP_3511_PA2.dir/banker_safety.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/COMP_3511_PA2.dir/banker_safety.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Mr\CLion-Projects-workspace\COMP_3511_PA2\banker_safety.c > CMakeFiles\COMP_3511_PA2.dir\banker_safety.c.i

CMakeFiles/COMP_3511_PA2.dir/banker_safety.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/COMP_3511_PA2.dir/banker_safety.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Mr\CLion-Projects-workspace\COMP_3511_PA2\banker_safety.c -o CMakeFiles\COMP_3511_PA2.dir\banker_safety.c.s

# Object files for target COMP_3511_PA2
COMP_3511_PA2_OBJECTS = \
"CMakeFiles/COMP_3511_PA2.dir/banker_safety.c.obj"

# External object files for target COMP_3511_PA2
COMP_3511_PA2_EXTERNAL_OBJECTS =

COMP_3511_PA2.exe: CMakeFiles/COMP_3511_PA2.dir/banker_safety.c.obj
COMP_3511_PA2.exe: CMakeFiles/COMP_3511_PA2.dir/build.make
COMP_3511_PA2.exe: CMakeFiles/COMP_3511_PA2.dir/linklibs.rsp
COMP_3511_PA2.exe: CMakeFiles/COMP_3511_PA2.dir/objects1.rsp
COMP_3511_PA2.exe: CMakeFiles/COMP_3511_PA2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Mr\CLion-Projects-workspace\COMP_3511_PA2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable COMP_3511_PA2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\COMP_3511_PA2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/COMP_3511_PA2.dir/build: COMP_3511_PA2.exe

.PHONY : CMakeFiles/COMP_3511_PA2.dir/build

CMakeFiles/COMP_3511_PA2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\COMP_3511_PA2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/COMP_3511_PA2.dir/clean

CMakeFiles/COMP_3511_PA2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Mr\CLion-Projects-workspace\COMP_3511_PA2 C:\Users\Mr\CLion-Projects-workspace\COMP_3511_PA2 C:\Users\Mr\CLion-Projects-workspace\COMP_3511_PA2\cmake-build-debug C:\Users\Mr\CLion-Projects-workspace\COMP_3511_PA2\cmake-build-debug C:\Users\Mr\CLion-Projects-workspace\COMP_3511_PA2\cmake-build-debug\CMakeFiles\COMP_3511_PA2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/COMP_3511_PA2.dir/depend
