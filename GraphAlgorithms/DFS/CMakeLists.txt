cmake_minimum_required(VERSION 3.17)
project(DFS)

set(CMAKE_CXX_STANDARD 14)

add_executable(DFS main.cpp DFS.cpp DFS.h adjacencyList.cpp adjacencyList.h domain.h recursivelyDFS.cpp recursivelyDFS.h)