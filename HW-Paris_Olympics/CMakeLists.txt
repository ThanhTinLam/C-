cmake_minimum_required(VERSION 3.27)
project(HW_Paris_Olympics)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW_Paris_Olympics
        main.cpp
        parallel_tracks.cpp
        parallel_tracks.h)
