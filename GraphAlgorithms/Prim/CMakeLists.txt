cmake_minimum_required(VERSION 3.17)
project(Prim)

set(CMAKE_CXX_STANDARD 14)

add_executable(Prim main.cpp adjacencyList.cpp adjacencyList.h domain.h prim.cpp prim.h)