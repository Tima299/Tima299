# Root CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(DoctorManagementSystem VERSION 1.0)

# Set C++ and C standards
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

# Specify where to find header files for the whole project
include_directories(
    backend/include
    frontend/include
    network/include
)

# Add the subdirectories for backend, frontend, and network
add_subdirectory(backend)
add_subdirectory(frontend)
add_subdirectory(network)

# Build the tests
add_subdirectory(tests)

# Define the build output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Optionally, you can add other configurations like for building documentation
# add_subdirectory(docs)

