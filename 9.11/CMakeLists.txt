cmake_minimum_required(VERSION 3.26)
project(9_11)

set(CMAKE_CXX_STANDARD 20)

add_executable(9_11 소스.cpp
        save.cpp
        save.h
        bigint.h
        bigint.cpp)
