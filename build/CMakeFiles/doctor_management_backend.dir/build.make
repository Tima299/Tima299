# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/temur/doctor_management_project/backend

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/temur/doctor_management_project/build

# Include any dependencies generated for this target.
include CMakeFiles/doctor_management_backend.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/doctor_management_backend.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/doctor_management_backend.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/doctor_management_backend.dir/flags.make

CMakeFiles/doctor_management_backend.dir/src/main.c.o: CMakeFiles/doctor_management_backend.dir/flags.make
CMakeFiles/doctor_management_backend.dir/src/main.c.o: /home/temur/doctor_management_project/backend/src/main.c
CMakeFiles/doctor_management_backend.dir/src/main.c.o: CMakeFiles/doctor_management_backend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/temur/doctor_management_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/doctor_management_backend.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/doctor_management_backend.dir/src/main.c.o -MF CMakeFiles/doctor_management_backend.dir/src/main.c.o.d -o CMakeFiles/doctor_management_backend.dir/src/main.c.o -c /home/temur/doctor_management_project/backend/src/main.c

CMakeFiles/doctor_management_backend.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/doctor_management_backend.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/temur/doctor_management_project/backend/src/main.c > CMakeFiles/doctor_management_backend.dir/src/main.c.i

CMakeFiles/doctor_management_backend.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/doctor_management_backend.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/temur/doctor_management_project/backend/src/main.c -o CMakeFiles/doctor_management_backend.dir/src/main.c.s

# Object files for target doctor_management_backend
doctor_management_backend_OBJECTS = \
"CMakeFiles/doctor_management_backend.dir/src/main.c.o"

# External object files for target doctor_management_backend
doctor_management_backend_EXTERNAL_OBJECTS =

doctor_management_backend: CMakeFiles/doctor_management_backend.dir/src/main.c.o
doctor_management_backend: CMakeFiles/doctor_management_backend.dir/build.make
doctor_management_backend: libdoctor_management_backend_lib.a
doctor_management_backend: CMakeFiles/doctor_management_backend.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/temur/doctor_management_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable doctor_management_backend"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/doctor_management_backend.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/doctor_management_backend.dir/build: doctor_management_backend
.PHONY : CMakeFiles/doctor_management_backend.dir/build

CMakeFiles/doctor_management_backend.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/doctor_management_backend.dir/cmake_clean.cmake
.PHONY : CMakeFiles/doctor_management_backend.dir/clean

CMakeFiles/doctor_management_backend.dir/depend:
	cd /home/temur/doctor_management_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/temur/doctor_management_project/backend /home/temur/doctor_management_project/backend /home/temur/doctor_management_project/build /home/temur/doctor_management_project/build /home/temur/doctor_management_project/build/CMakeFiles/doctor_management_backend.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/doctor_management_backend.dir/depend

