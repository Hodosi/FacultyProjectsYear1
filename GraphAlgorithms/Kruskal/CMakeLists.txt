cmake_minimum_required(VERSION 3.17)
project(Kruskal)

set(CMAKE_CXX_STANDARD 14)

add_executable(Kruskal main.cpp edgeList.cpp edgeList.h domain.h kruskal.cpp kruskal.h)