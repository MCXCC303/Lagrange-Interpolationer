cmake_minimum_required(VERSION 3.28)
project(Lagrange_Interpolation)

set(CMAKE_CXX_STANDARD 23)

#link_libraries(libeasyx.a libgdi32.a libole32.a)
add_executable(Lagrange_Interpolation
        SingleValue/AdditionTest.c
        SingleValue/builtin.c
        SingleValue/builtin.h
        SingleValue/FactorSequence.c
        SingleValue/FractionAddition.c
        SingleValue/FractionSimplifier.c
        SingleValue/generateSequenceTest.c
        SingleValue/LinearSequence.c
        SingleValue/LineBase.c
        SingleValue/PolyCalc.c
        SingleValue/PolyTest.c
        SingleValue/SingleValue.c
        Output/PrintFactorResult.c
        Output/PrintFactorResult.h
        Output/LatexStyleOutput.c
        Output/LatexStyleOutput.h
)
