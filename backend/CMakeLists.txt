# backend/CMakeLists.txt

# Collect all the C source files for the backend (only .c files, not .h)
file(GLOB BACKEND_SRC
    "src/**/*.c"  # C source files in the src folder
)

# Create the backend executable
add_executable(backend ${BACKEND_SRC})

# Include directories for header files
target_include_directories(backend PUBLIC 
    "${CMAKE_SOURCE_DIR}/backend/include"  # Include header files from the include directory
)

# If you need to link any libraries (like pthread, MySQL, etc.), do it here
# target_link_libraries(backend pthread) 
# target_link_libraries(backend mysql)

