cmake_minimum_required(VERSION 3.28)
project(FullSailAssignmentFW)

set(CMAKE_CXX_STANDARD 20)

add_executable(FullSailAssignmentFW main.cpp
        Lib/Headers/Console.h
        Lib/Console/Console.cpp
        Lib/Console/Console.cpp
        Lib/Headers/Input.h
        Lib/Input/Input.cpp
        Lib/Input/Input.cpp)
