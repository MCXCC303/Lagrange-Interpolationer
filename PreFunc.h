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

Line *initLinearSequence(Line *linearSequence, int line_order, int value);

Line *generateLinearSequence(Line *linearSequence, int size);

typedef struct lineBase {
    int *numeratorSequence;
    int order;
    int denominator;
} LBase;

LBase *initLineBase(LBase *lineBase, int order);

int factorial(int n);

int gcd(int a1, int a2);

int lcm(int a1, int a2);

void clrArr(int *arr, int size);

void swpArr(int *arr1, int *arr2, int size);

#endif //LAGRANGE_INTERPOLATION_PREFUNC_H