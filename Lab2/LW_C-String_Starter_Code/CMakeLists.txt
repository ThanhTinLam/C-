cmake_minimum_required(VERSION 3.27)
project(LW_C_String_Starter_Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LW_C_String_Starter_Code
        cstring.cpp
        cstring.h
        main.cpp)
