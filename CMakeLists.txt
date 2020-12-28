cmake_minimum_required(VERSION 3.15)
project(Graphs)

set(CMAKE_CXX_STANDARD 20)

add_executable(Graphs main.cpp Graph.h GraphInterface.h Tests.h)
target_include_directories(Graphs PUBLIC .)