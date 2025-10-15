cmake_minimum_required(VERSION 4.0)
project(EvilDog)

set(CMAKE_CXX_STANDARD 23)

add_executable(EvilDog main.cpp
        Board.cpp
        Dog.cpp)
