# Minimum CMake version
cmake_minimum_required(VERSION 4.0)

# Project name
project(test)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Header files
set(HEADERS
    library_fwd.hpp
    library.hpp
    visitor.hpp
    books.hpp
    magazine.hpp
    concrete_visitors.hpp
)

# Source files
set(SOURCES
    main.cpp
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})