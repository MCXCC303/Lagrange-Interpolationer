cmake_minimum_required(VERSION 3.28)
project(Lagrange_Interpolation C)

set(CMAKE_C_STANDARD 11)

add_executable(Lagrange_Interpolation main.c
        PolyCalc.c
        PreFunc.c
        PreFunc.h)
