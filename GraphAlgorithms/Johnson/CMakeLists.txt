cmake_minimum_required(VERSION 3.17)
project(Johnson)

set(CMAKE_CXX_STANDARD 14)

add_executable(Johnson main.cpp adjacencyList.cpp adjacencyList.h dijkstra.cpp dijkstra.h edgeList.cpp edgeList.h domain.h bellmanFord.cpp bellmanFord.h johnson.cpp johnson.h)