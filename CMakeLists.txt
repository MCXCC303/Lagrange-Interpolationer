cmake_minimum_required(VERSION 3.28)
project(Lagrange_Interpolation)

set(CMAKE_CXX_STANDARD 23)

link_libraries(libeasyx.a libgdi32.a libole32.a)
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
        Output/PrintFactorResult.c
        Output/PrintFactorResult.h
        Output/LatexStyleOutput.c
        Output/LatexStyleOutput.h
        Graphic/Main.cpp
        Graphic/Configurations.h
)
