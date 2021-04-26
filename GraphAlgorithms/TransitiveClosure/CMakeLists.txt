cmake_minimum_required(VERSION 3.17)
project(TransitiveClosure)

set(CMAKE_CXX_STANDARD 14)

add_executable(TransitiveClosure main.cpp transitiveClosureMatrix.cpp transitiveClosureMatrix.h)