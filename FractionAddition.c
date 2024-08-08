//
// Created by MCXCC on 2024/8/7.
//

#include "PreFunc.h"
#include "LineBase.h"

LBase *doFractionAddition(LBase *lineBase1, LBase *lineBase2) {
    /**
     * Calculate the result of two fraction list
     * @param lineBase1
     * @param lineBase2
     * @return lineBaseResult
     */
    // Initialize
    long long numeratorSequence1;
    long long numeratorSequence2;
    int order = lineBase1->order;
    LBase *lineBaseResult = initLineBase(lineBaseResult, order);
    lineBaseResult->numeratorSequence = (long long *) malloc(sizeof(long long) * (order + 1));
    lineBaseResult->order = order;

    // Calculate
    int denominatorResult = lcm(lineBase1->denominator, lineBase2->denominator);
    for (int i = 0; i < order + 1; ++i) {
        numeratorSequence1 = lineBase1->numeratorSequence[i] * denominatorResult / lineBase1->denominator;
        numeratorSequence2 = lineBase2->numeratorSequence[i] * denominatorResult / lineBase2->denominator;
        lineBaseResult->numeratorSequence[i] = numeratorSequence1 + numeratorSequence2;
    }

    lineBaseResult->denominator = denominatorResult;
    return lineBaseResult;
}