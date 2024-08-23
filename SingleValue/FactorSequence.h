/**
 * @author MCXCC
 * @date 2024/8/8
*/

#ifndef LAGRANGE_INTERPOLATION_FACTORSEQUENCE_H
#define LAGRANGE_INTERPOLATION_FACTORSEQUENCE_H

#include "LineBase.h"

typedef struct FactorSequence {
    /**
     * @brief Factor sequence contain a pointer to a 2D array in {{nu1,de},{nu2,de},...}
     * @note nu stands for numerator, de stands for denominator
     * @note nu and de comes directly from LineBases
     */
    long long **sequence;
} Factors;

Factors *sequenceTransfer(Factors *factors, LBase *lineBase);

#endif //LAGRANGE_INTERPOLATION_FACTORSEQUENCE_H
