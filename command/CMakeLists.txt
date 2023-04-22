cmake_minimum_required(VERSION 3.24)
project(command)

set(CMAKE_CXX_STANDARD 17)

add_executable(command main.cpp Types.h Types.cpp)
