cmake_minimum_required(VERSION 3.17)
project(FleuryAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(FleuryAlgorithm main.cpp adjacencyList.cpp adjacencyList.h domain.h fleury.cpp fleury.h)