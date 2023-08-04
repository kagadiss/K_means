cmake_minimum_required(VERSION 3.25)
project(Kmeans)

set(CMAKE_CXX_STANDARD 17)

add_executable(Kmeans main.cpp Calculation.cpp Calculation.h Point.cpp Point.h CalculationFactory.h)
