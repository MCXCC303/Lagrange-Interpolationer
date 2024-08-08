cmake_minimum_required(VERSION 3.28)
project(Lagrange_Interpolation C)

set(CMAKE_C_STANDARD 11)

add_executable(Lagrange_Interpolation main.c
        PolyCalc.c
        PreFunc.c
        PreFunc.h
        PolyTest.c
        PolyCalc.h
        FractionAddition.c
        AdditionTest.c
        FractionAddition.h
        LinearSequence.c
        LinearSequence.h
        LineBase.c
        LineBase.h
        generateSequenceTest.c
        FractionSimplifier.c
        FractionSimplifier.h
        FactorSequence.c
        FactorSequence.h
        PrintFactorResult.c
        PrintFactorResult.h
)
