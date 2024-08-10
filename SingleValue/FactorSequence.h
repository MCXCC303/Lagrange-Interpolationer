/**
 * @author MCXCC
 * @date 2024/8/8
*/

#ifndef LAGRANGE_INTERPOLATION_FACTORSEQUENCE_H
#define LAGRANGE_INTERPOLATION_FACTORSEQUENCE_H

#include "LineBase.h"

typedef struct FactorSequence {
    long long **sequence;
} Factors;

Factors *sequenceTransfer(Factors *factors, LBase *lineBase);

#endif //LAGRANGE_INTERPOLATION_FACTORSEQUENCE_H
