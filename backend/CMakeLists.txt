# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(DoctorManagementBackend VERSION 1.0)

# Set C standard
set(CMAKE_C_STANDARD 99)

# Include directories for header files
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/models
    ${PROJECT_SOURCE_DIR}/src/utils
)
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/models
)

# Define source files for the library
file(GLOB LIB_SOURCES
    ${PROJECT_SOURCE_DIR}/src/controllers/*.c
    ${PROJECT_SOURCE_DIR}/src/repositories/*.c
    ${PROJECT_SOURCE_DIR}/src/services/*.c
    ${PROJECT_SOURCE_DIR}/src/utils/*.c
)

# Create a static library
add_library(doctor_management_backend_lib STATIC ${LIB_SOURCES})

# Define the executable
add_executable(doctor_management_backend ${PROJECT_SOURCE_DIR}/src/main.c)

# Link the library to the executable
target_link_libraries(doctor_management_backend doctor_management_backend_lib pthread)

# Enable testing
enable_testing()

# Add the tests directory
add_subdirectory(tests)

