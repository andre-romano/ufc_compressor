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

# Find all .cpp files recursively in the src/ directory
file(GLOB_RECURSE SRC_CPP "src/*.cpp")
file(GLOB_RECURSE SRC_CC "src/*.cc")
file(GLOB_RECURSE SRC_C "src/*.c")

# Add executable with all .cpp files
add_executable(ufc_compressor ${SRC_CPP} ${SRC_CC} ${SRC_C})

# Include directories for the main executable
target_include_directories(ufc_compressor PRIVATE src include)

# Include libraries
target_include_directories(ufc_compressor PUBLIC external/argparse/include)

# # Find all .cpp files recursively in the library directory
# file(GLOB_RECURSE LIB_CPP "external/*.cpp")
# file(GLOB_RECURSE LIB_CC "external/*.cc")
# file(GLOB_RECURSE LIB_C "external/*.c")

# # Add a library for external dependencies
# add_library(external_lib ${LIB_CPP} ${LIB_CC} ${LIB_C})
# target_include_directories(external_lib PUBLIC external)

# # Link the external library to your executable
# target_link_libraries(ufc_compressor PRIVATE external_lib)
