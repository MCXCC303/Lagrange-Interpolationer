/**
 * @author MCXCC
 * @date 2024/8/7
*/

#include "stdlib.h"

typedef struct linearSequence {
    int *sequence;
    int value;
} Line;

typedef struct lineBase {
    int *numeratorSequence;
    int denominator;
} LBase;

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int gcd(int a1, int a2) {
    /*
     * Pre-set to calculate full-division algorithm.
     *
     * Variables:
     * tmp: Temporary in swpArr
     * res: Remainder
     *
     */
    int n = a1, m = a2;
    int tmp, res;
    if (m < n) {
        tmp = m;
        m = n;
        n = tmp;
    }
    while ((m % n) != 0) {
        res = m % n;
        m = n;
        n = res;
    }
    return n;
}

void clrArr(int *arr, int size) {
    /*
     * Clear an array or set the array into default value.
     *
     */
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}

void swpArr(int *arr1, int *arr2, int size) {
    /*
     * Swap two arrays (MEM changed).
     *
     */
    int tmp[size];
    for (int i = 0; i < size; ++i) {
        tmp[i] = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = tmp[i];
    }
}

Line *initLinearSequence(Line *linearSequence) {
    linearSequence = (Line *) malloc(sizeof(Line));
    linearSequence->sequence = NULL;
    return linearSequence;
}

Line *generateLinearSequence(int size) {
    Line *linearSequence = (Line *) malloc(sizeof(Line));
}

LBase *initLineBase(LBase *lineBase) {
    lineBase = (LBase *) malloc(sizeof(LBase));
    lineBase->numeratorSequence = NULL;
    return lineBase;
}