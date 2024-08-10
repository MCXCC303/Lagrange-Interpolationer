/**
 * @author MCXCC
 * @date 2024/8/8
*/

#ifndef LAGRANGE_INTERPOLATION_LINEBASE_H
#define LAGRANGE_INTERPOLATION_LINEBASE_H

#include "stdlib.h"
#include "LinearSequence.h"

typedef struct lineBase {
    long long *numeratorSequence;
    int order;
    int denominator;
} LBase;

LBase *initLineBase(LBase *lineBase, int order);

LBase *generateNumerator(Line *linearSequence, LBase *lineBase);

LBase *generateDenominator(Line *linearSequence, LBase *lineBase);

#endif //LAGRANGE_INTERPOLATION_LINEBASE_H
