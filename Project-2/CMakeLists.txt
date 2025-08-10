#cmake version
cmake_minimum_required(VERSION 4.0)

#project name
project(test)

#set cpp compiler
set(CMAKE_CXX_STANDARD 17)

#set sources
set(SOURCES main.cpp)

#add executable
add_executable(test ${SOURCES})