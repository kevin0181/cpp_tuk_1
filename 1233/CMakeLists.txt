cmake_minimum_required(VERSION 3.26)
project(2)

set(CMAKE_CXX_STANDARD 23)

add_executable(2 main.cpp
        ShapeManager.cpp
        Triangle.cpp
        Point.cpp
        Rectangle.cpp
        Pentagon.cpp
        Circle.cpp
        Menu.cpp
        FileManager.h
        FileManager.cpp
        Line.h
        Line.cpp)
