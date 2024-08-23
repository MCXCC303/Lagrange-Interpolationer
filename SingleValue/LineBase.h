/**
 * @author MCXCC
 * @date 2024/8/8
*/

#ifndef LAGRANGE_INTERPOLATION_LINEBASE_H
#define LAGRANGE_INTERPOLATION_LINEBASE_H

#include "stdlib.h"
#include "LinearSequence.h"

typedef struct lineBase {
    /**
     * @brief LBase included a sequence of numerator and a denominator
     *
     * @example Line: sequence = [-1,-3,-4,-5]
     * @example value = 4
     * @note The numerator directly comes from the polyCalc()
     * @note The denominator comes from factorial()
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
    long long *numeratorSequence;
    int order;
    int denominator;
} LBase;

LBase *initLineBase(LBase *lineBase, int order);

LBase *generateNumerator(Line *linearSequence, LBase *lineBase);

LBase *generateDenominator(Line *linearSequence, LBase *lineBase);

#endif //LAGRANGE_INTERPOLATION_LINEBASE_H
