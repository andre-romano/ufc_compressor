# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(ufc_compressor VERSION 1.0 LANGUAGES CXX)

# Set C++ standard (C++17 is required for <filesystem>)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Use libc++ instead of libstdc++
add_compile_options(-stdlib=libc++)
add_link_options(-stdlib=libc++)

# Add src/ to the include path
include_directories(src)

# Find all .cpp files recursively in the src/ directory
file(GLOB_RECURSE SRC_FILES "src/*.cpp")

# Add executable with all .cpp files
add_executable(ufc_compressor ${SRC_FILES})