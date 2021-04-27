cmake_minimum_required(VERSION 3.17)
project(MooreAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(MooreAlgorithm main.cpp domain.h adjacencyList.cpp adjacencyList.h moore.cpp moore.h)