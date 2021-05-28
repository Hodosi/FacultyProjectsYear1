cmake_minimum_required(VERSION 3.17)
project(EdmondsKarp)

set(CMAKE_CXX_STANDARD 14)

add_executable(EdmondsKarp main.cpp fromFileToAdjacencyList.cpp fromFileToAdjacencyList.h domain.h edmondsKarp.cpp edmondsKarp.h)