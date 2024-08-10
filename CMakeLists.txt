cmake_minimum_required(VERSION 3.28)
project(Lagrange_Interpolation)

set(CMAKE_CXX_STANDARD 23)

link_libraries(libeasyx.a libgdi32.a libole32.a)
add_executable(Lagrange_Interpolation
        SingleValue/main.c
        SingleValue/PolyCalc.c
        SingleValue/PreFunc.c
        SingleValue/PreFunc.h
        SingleValue/PolyTest.c
        SingleValue/PolyCalc.h
        SingleValue/FractionAddition.c
        SingleValue/AdditionTest.c
        SingleValue/FractionAddition.h
        SingleValue/LinearSequence.c
        SingleValue/LinearSequence.h
        SingleValue/LineBase.c
        SingleValue/LineBase.h
        SingleValue/generateSequenceTest.c
        SingleValue/FractionSimplifier.c
        SingleValue/FractionSimplifier.h
        SingleValue/FactorSequence.c
        SingleValue/FactorSequence.h
        Output/PrintFactorResult.c
        Output/PrintFactorResult.h
        Output/LatexStyleOutput.c
        Output/LatexStyleOutput.h
        Graphic/Main.cpp
        Graphic/Configurations.h
)
