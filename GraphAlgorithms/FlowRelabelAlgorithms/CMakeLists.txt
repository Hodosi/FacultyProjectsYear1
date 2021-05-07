cmake_minimum_required(VERSION 3.17)
project(FlowRelabelAlgorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(FlowRelabelAlgorithms main.cpp domain.h fromFileToAdjacencyList.cpp fromFileToAdjacencyList.h flowRelabel.cpp flowRelabel.h)