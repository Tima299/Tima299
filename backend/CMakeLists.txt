# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(DoctorManagementBackend VERSION 1.0)

# Set C standard
set(CMAKE_C_STANDARD 99)

# Option to enable debug mode
set(CMAKE_BUILD_TYPE Debug)

# Include directories for header files
include_directories(
    ${PROJECT_SOURCE_DIR}/backend/include
    ${PROJECT_SOURCE_DIR}/backend/models
    ${PROJECT_SOURCE_DIR}/backend/src/utils
)

# Define source files
file(GLOB BACKEND_SOURCES
    ${PROJECT_SOURCE_DIR}/backend/src/controllers/*.c
    ${PROJECT_SOURCE_DIR}/backend/src/repositories/*.c
    ${PROJECT_SOURCE_DIR}/backend/src/services/*.c
    ${PROJECT_SOURCE_DIR}/backend/src/utils/*.c
    ${PROJECT_SOURCE_DIR}/backend/src/main.c
)

# Add the executable for the backend
add_executable(doctor_management_backend ${BACKEND_SOURCES})

# Link libraries
# Example of linking pthread and mysql client libraries (if needed)
# find_package(MySQL REQUIRED)
# target_link_libraries(doctor_management_backend pthread ${MYSQL_LIBRARIES})

# Set include directories for MySQL or other external libraries if necessary
# include_directories(${MYSQL_INCLUDE_DIR})

# Specify where the executable will be built
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/backend/build)

# Install rules (optional)
# install(TARGETS doctor_management_backend DESTINATION /usr/local/bin)

# If tests are in separate files, link them to the backend executable (optional)
enable_testing()

# Add testing functionality if any (You can add the test executables or libraries here)
add_subdirectory(backend/tests)

# For debugging, add the necessary compiler flags (optional)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall")
endif()

# Ensure proper installation structure
# install(DIRECTORY backend/include DESTINATION /usr/local/include)
# install(DIRECTORY backend/src DESTINATION /usr/local/lib)

