/**
 * @author MCXCC
 * @date 2024/8/8
*/

#include "LineBase.h"

typedef struct FactorSequence {
    /**
     * Factor sequence contain a pointer to a 2D array in {{nu1,de},{nu2,de},...}
     * @note nu stands for numerator, de stands for denominator
     * @note nu and de comes directly from LineBases
     */
    long long **sequence;
} Factors;

Factors *sequenceTransfer(Factors *factors, LBase *lineBase) {
    long long **factorSequence = (long long **) malloc(sizeof(long long *) * lineBase->order + 1);
    for (int i = 0; i < lineBase->order + 1; ++i) {
        factorSequence[i] = (long long *) malloc(sizeof(long long) * 2);
        factorSequence[i][0] = lineBase->numeratorSequence[i];
        factorSequence[i][1] = lineBase->denominator;
    }
    factors->sequence = factorSequence;
    return factors;
}