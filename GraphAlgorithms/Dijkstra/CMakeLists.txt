cmake_minimum_required(VERSION 3.17)
project(Dijkstra)

set(CMAKE_CXX_STANDARD 14)

add_executable(Dijkstra main.cpp edgeList.cpp edgeList.h domain.h dijkstra.cpp dijkstra.h adjacencyList.cpp adjacencyList.h)