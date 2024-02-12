cmake_minimum_required(VERSION 3.27)
project(HW_Debugging_Input_Validation_and_Integer_Overflow_Starter_Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW_Debugging_Input_Validation_and_Integer_Overflow_Starter_Code
        debugging.cpp
        functions.cpp
        functions.h)
