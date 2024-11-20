cmake_minimum_required(VERSION 3.31)

# Project name
project(pong)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories for raylib headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Specify library search path for raylib
link_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.cpp")

# Add the executable target for the pong project
add_executable(pong ${SOURCES})

# Link the raylib static library and system libraries
target_link_libraries(pong raylib m)

