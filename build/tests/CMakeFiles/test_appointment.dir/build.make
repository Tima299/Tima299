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
include tests/CMakeFiles/test_appointment.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/test_appointment.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_appointment.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_appointment.dir/flags.make

tests/CMakeFiles/test_appointment.dir/test_appointment.c.o: tests/CMakeFiles/test_appointment.dir/flags.make
tests/CMakeFiles/test_appointment.dir/test_appointment.c.o: /home/temur/doctor_management_project/backend/tests/test_appointment.c
tests/CMakeFiles/test_appointment.dir/test_appointment.c.o: tests/CMakeFiles/test_appointment.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/temur/doctor_management_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/test_appointment.dir/test_appointment.c.o"
	cd /home/temur/doctor_management_project/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/test_appointment.dir/test_appointment.c.o -MF CMakeFiles/test_appointment.dir/test_appointment.c.o.d -o CMakeFiles/test_appointment.dir/test_appointment.c.o -c /home/temur/doctor_management_project/backend/tests/test_appointment.c

tests/CMakeFiles/test_appointment.dir/test_appointment.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_appointment.dir/test_appointment.c.i"
	cd /home/temur/doctor_management_project/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/temur/doctor_management_project/backend/tests/test_appointment.c > CMakeFiles/test_appointment.dir/test_appointment.c.i

tests/CMakeFiles/test_appointment.dir/test_appointment.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_appointment.dir/test_appointment.c.s"
	cd /home/temur/doctor_management_project/build/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/temur/doctor_management_project/backend/tests/test_appointment.c -o CMakeFiles/test_appointment.dir/test_appointment.c.s

# Object files for target test_appointment
test_appointment_OBJECTS = \
"CMakeFiles/test_appointment.dir/test_appointment.c.o"

# External object files for target test_appointment
test_appointment_EXTERNAL_OBJECTS =

tests/test_appointment: tests/CMakeFiles/test_appointment.dir/test_appointment.c.o
tests/test_appointment: tests/CMakeFiles/test_appointment.dir/build.make
tests/test_appointment: libdoctor_management_backend_lib.a
tests/test_appointment: tests/CMakeFiles/test_appointment.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/temur/doctor_management_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test_appointment"
	cd /home/temur/doctor_management_project/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_appointment.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test_appointment.dir/build: tests/test_appointment
.PHONY : tests/CMakeFiles/test_appointment.dir/build

tests/CMakeFiles/test_appointment.dir/clean:
	cd /home/temur/doctor_management_project/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_appointment.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_appointment.dir/clean

tests/CMakeFiles/test_appointment.dir/depend:
	cd /home/temur/doctor_management_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/temur/doctor_management_project/backend /home/temur/doctor_management_project/backend/tests /home/temur/doctor_management_project/build /home/temur/doctor_management_project/build/tests /home/temur/doctor_management_project/build/tests/CMakeFiles/test_appointment.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/test_appointment.dir/depend
