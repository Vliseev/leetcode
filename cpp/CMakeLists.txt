cmake_minimum_required(VERSION 3.9)
project(task)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -O1 -O1 -fsanitize=undefined -lasan")
add_executable(task main.cpp)