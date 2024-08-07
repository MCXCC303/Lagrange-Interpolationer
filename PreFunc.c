/**
 * @author MCXCC
 * @date 2024/8/7
*/

#include "stdlib.h"

typedef struct linearSequence {
    /*
     * Line: Included a sequence of x and a value as y and a order of which point will this line go for
     * l_i = y0(x-a0)(x-a1)...(x-a_(i-1))(x-a_(i+1))...(x-an)/(ai-a0)(ai-a1)...(ai_(i-1))(ai_(i+1))...(ai-an)
     * sequence = [a0,a1,...,a(i-1),a(i+1),...an]
     * line_order = i
     *
     * In simple, the x of every value will be set into (1,2,3...n)
     * the sequence will trans into:
     * sequence = [1,2,...i-1,i+1,...n]
     *
     * Use generateLinearSequence() to generate this sequence
     *
     */
    int *sequence;
    int value;
    int line_order;
} Line;

typedef struct lineBase {
    /*
     * LBase included a sequence of numerator and a denominator
     * the numerator directly comes from the polyCalc()
     * the denominator comes from factorial()
     *
     * Example:
     * Line: sequence = [-1,-3,-4,-5]
     *       value = 4
     * After polyCalc there get [60,-107,59,-13,1] as numeratorSequence
     * (Means (x-1)(x-3)(x-4)(x-5)=60-107x+59x^2-13x^3+x^4)
     *
     * In doing factorial first get the order of current line
     * l_i's denominator could trans into (i-1)!(n-i)!(-1)^i
     * there line_order = i, size = n
     *
     */
    int *numeratorSequence;
    int denominator;
} LBase;

int factorial(int n) {
    /*
     * Do factorial
     *
     */
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
    /*
     *
     */
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