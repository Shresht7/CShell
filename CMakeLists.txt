cmake_minimum_required(VERSION 3.10.0)
project(CShell VERSION 0.1.0 LANGUAGES C)

# Set C standard to C11 (or later)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include directories for public headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Recursively add source files
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.c)

# Define the executable
add_executable(CShell ${SRC_FILES})

