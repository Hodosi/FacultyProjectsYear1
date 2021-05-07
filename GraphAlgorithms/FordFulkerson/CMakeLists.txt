cmake_minimum_required(VERSION 3.17)
project(FordFulkerson)

set(CMAKE_CXX_STANDARD 14)

add_executable(FordFulkerson main.cpp fromFileToAdjacencyPriorityQueue.cpp fromFileToAdjacencyPriorityQueue.h domain.h fromFileToAdjacencyMap.cpp fromFileToAdjacencyMap.h fordFulkerson.cpp fordFulkerson.h fromFileToAdjacencyList.cpp fromFileToAdjacencyList.h)