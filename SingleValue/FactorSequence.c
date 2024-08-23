/**
 * @author MCXCC
 * @date 2024/8/8
*/

#include "LineBase.h"
#include "FactorSequence.h"


Factors *sequenceTransfer(Factors *factors, LBase *lineBase) {
    /**
     * @brief Move the result of LineBaseResult to a FactorSequence
     * @note The result of LineBaseResult is a 1D array and a denominator, this function transfer it to a 2D array
     *
     * @param factors
     * @param lineBase
     * @return Factors*
     */
    long long **factorSequence = (long long **) malloc(sizeof(long long *) * lineBase->order + 1);
    for (int i = 0; i < lineBase->order + 1; ++i) {
        factorSequence[i] = (long long *) malloc(sizeof(long long) * 2);
        factorSequence[i][0] = lineBase->numeratorSequence[i];
        factorSequence[i][1] = lineBase->denominator;
    }
    factors->sequence = factorSequence;
    return factors;
}