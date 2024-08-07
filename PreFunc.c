/**
 * @author MCXCC
 * @date 2024/8/7
*/

#include "stdlib.h"

typedef struct linearSequence {
    /**
     * Line: Included a sequence of x and a value as y and a order of which point will this line go for
     *
     * @remark l_i = y0(x-a0)(x-a1)...(x-a_(i-1))(x-a_(i+1))...(x-an)/(ai-a0)(ai-a1)...(ai_(i-1))(ai_(i+1))...(ai-an)
     * @remark sequence = [a0,a1,...,a(i-1),a(i+1),...an]
     * @remark line_order = i
     *
     * @remark In simple, the x of every value will be set into (1,2,3...n)
     * @remark the sequence will trans into:
     * @remark sequence = [1,2,...i-1,i+1,...n]
     *
     * @note Use generateLinearSequence() to generate this sequence
     *
     */
    int *sequence;
    int value;
    int line_order;
} Line;

typedef struct lineBase {
    /**
     * LBase included a sequence of numerator and a denominator
     * the numerator directly comes from the polyCalc()
     * the denominator comes from factorial()
     *
     * @example Line: sequence = [-1,-3,-4,-5]\n
     *                value = 4
     *
     * @note After polyCalc there get [60,-107,59,-13,1] as numeratorSequence
     * @note (Means (x-1)(x-3)(x-4)(x-5)=60-107x+59x^2-13x^3+x^4)
     * @note Variable order is the same as the polyCalc()
     * @note In doing factorial first get the order of current line
     * @note l_i's denominator could trans into (i-1)!(n-i)!(-1)^i
     * @note there line_order = i, value_size = n
     *
     * @var numeratorSequence: The numerator of the line
     * @var order: The order of the line
     * @var denominator: The denominator of the line
     */
    int *numeratorSequence;
    int order;
    int denominator;
} LBase;

int factorial(int n) {
    /**
     * Do factorial
     * @param n
     * @return n!
     *
     */
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int gcd(int a1, int a2) {
    /**
     * Pre-set to calculate full-division algorithm.
     * @param a1
     * @param a2
     * @return gcd
     *
     * @var tmp: Temporary in swpArr
     * @var res: Remainder
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

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void clrArr(int *arr, int size) {
    /**
     * Clear an array or set the array into default value.
     * @param arr
     * @param size
     * @return
     */
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}

void swpArr(int *arr1, int *arr2, int size) {
    /**
     * Swap two arrays (MEM changed).
     * @param arr1
     * @param arr2
     * @param size
     * @return
     *
     */
    int tmp[size];
    for (int i = 0; i < size; ++i) {
        tmp[i] = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = tmp[i];
    }
}

Line *initLinearSequence(Line *linearSequence, int line_order, int value) {
    /**
     * Initialize a Line.
     * @param linearSequence
     * @param line_order
     * @param value
     * @return Line(Initialized)
     *
     * @note Line->sequence will not be initialized, this directly set by generateLinearSequence()
     *
     * @example Line *line1 = initLinearSequence(line1,line_order,value);
     */
    linearSequence = (Line *) malloc(sizeof(Line));
    linearSequence->sequence = NULL;
    linearSequence->line_order = line_order;
    linearSequence->value = value;
    return linearSequence;
}

Line *generateLinearSequence(Line *linearSequence, int size) {

}

LBase *initLineBase(LBase *lineBase, int order) {
    /**
     * Initialize a LineBase.
     * @param lineBase
     * @param order
     * @return LBase(Initialized)
     *
     * @note LBase->denominator will not be initialized, this directly set by factorial()
     *
     * @example
     * LBase *lineBase1 = initLineBase(*lineBase1, order);
     */
    lineBase = (LBase *) malloc(sizeof(LBase));
    lineBase->numeratorSequence = NULL;
    lineBase->order = order;
    return lineBase;
}