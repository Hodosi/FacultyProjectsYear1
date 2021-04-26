cmake_minimum_required(VERSION 3.17)
project(RepresentationOfGraphs)

set(CMAKE_CXX_STANDARD 14)

add_executable(RepresentationOfGraphs main.cpp adjacencyMatrix.cpp adjacencyMatrix.h adjacencyList.cpp adjacencyList.h incidenceMatrix.cpp incidenceMatrix.h)