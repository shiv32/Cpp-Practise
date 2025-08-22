#version
cmake_minimum_required(VERSION 4.0)

#project name
project(test)

#set c++
set(CMAKE_CXX_STANDARD 17)

#set source
set(SOURCES main.cpp)

#add exe
add_executable(test ${SOURCES})