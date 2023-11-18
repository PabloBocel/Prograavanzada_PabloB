cmake_minimum_required(VERSION 3.26)
project(untitled1)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled1 main.cpp
        cmake-build-debug/Readtxt.cpp
        cmake-build-debug/Readtxt.h
        AddData.cpp
        AddData.h
        SearchByKey.cpp
        SearchByKey.h
        SearchByValue.cpp
        SearchByValue.h)
