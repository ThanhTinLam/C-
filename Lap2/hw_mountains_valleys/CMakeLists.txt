cmake_minimum_required(VERSION 3.27)
project(hw_mountains_valleys)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hw_mountains_valleys
        functions.cpp
        functions.h
        mountains_valleys.cpp)
