cmake_minimum_required(VERSION 3.17)
project(GraphColoring)

set(CMAKE_CXX_STANDARD 14)

add_executable(GraphColoring main.cpp "chromaticNumber.cpp" "chromaticNumber.h" graphColoring.cpp graphColoring.h fromFileToAdjacencySet.cpp fromFileToAdjacencySet.h domain.h fromFileToAdjacencyList.cpp fromFileToAdjacencyList.h)