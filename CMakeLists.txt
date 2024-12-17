cmake_minimum_required(VERSION 3.30)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 23)

add_executable(AdventOfCode main.cpp
        days/DayRunner.cpp
        days/DayRunner.h
        days/DayOne.cpp
        days/DayOne.h
        days/DayTwo.cpp
        days/DayTwo.h
        days/DayThree.cpp
        days/DayThree.h)
