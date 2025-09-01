# Minimum CMake version
cmake_minimum_required(VERSION 4.0)

# Project name
project(test)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Source files
set(SOURCES main.cpp)

# Add executable
add_executable(test ${SOURCES})