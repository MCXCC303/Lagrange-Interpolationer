/**
 * @author MCXCC
 * @date 2024/8/7
*/

#ifndef LAGRANGE_INTERPOLATION_PREFUNC_H
#define LAGRANGE_INTERPOLATION_PREFUNC_H

#include "stdlib.h"

typedef struct linearSequence {
    int *sequence;
    int value;
    int line_order;
} Line;

Line *initLinearSequence(Line *linearSequence);

typedef struct lineBase {
    int *numeratorSequence;
    int denominator;
} LBase;

LBase *initLineBase(LBase *lineBase);

int factorial(int n);

int gcd(int a1, int a2);

void clrArr(int *arr, int size);

void swpArr(int *arr1, int *arr2, int size);

Line *generateLinearSequence(int size);

#endif //LAGRANGE_INTERPOLATION_PREFUNC_H