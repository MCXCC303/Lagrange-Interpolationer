/**
 * @author MCXCC
 * @date 2024/8/7
*/

#include "LinearSequence.h"
#include "LineBase.h"
#include "stdio.h"
#include "FractionAddition.h"
#include "FactorSequence.h"
#include "FractionSimplifier.h"
#include "Output/PrintFactorResult.h"
#include "Output/LatexStyleOutput.h"

int main() {
    // Data Collection
    freopen("input.txt", "r", stdin);
    int *value_sequence;
    int size = 1;
    value_sequence = (int *) malloc(size * sizeof(int));
    while (scanf("%d", &value_sequence[size - 1]) != EOF) {
        size++;
        value_sequence = (int *) realloc(value_sequence, size * sizeof(int));
    }
    size--;

    /*
     * order = size - 1, length of linear sequence = size
     *
     * Example:
     * value_sequence = {1, 7, 3, 12};
     * order = 3, length = 4;
     *
     */

    // Initialize Linear Sequence and Line Base
    Line *lineList[size];
    for (int i = 0; i < size; ++i) {
        lineList[i] = initLinearSequence(lineList[i], i + 1, value_sequence[i]);
        lineList[i] = generateLinearSequence(lineList[i], size - 1);
    }

    LBase *lBaseList[size];
    for (int i = 0; i < size; ++i) {
        lBaseList[i] = initLineBase(lBaseList[i], size - 1);
        lBaseList[i] = generateNumerator(lineList[i], lBaseList[i]);
        lBaseList[i] = generateDenominator(lineList[i], lBaseList[i]);
    }
    LBase *lBaseResult = doFractionAddition(lBaseList[0], lBaseList[1]);
    for (int i = 2; i < size; ++i) {
        lBaseResult = doFractionAddition(lBaseResult, lBaseList[i]);
    }

    // Transfer Result
    Factors *factors = (Factors *) malloc(sizeof(Factors));
    factors = sequenceTransfer(factors, lBaseResult);
    for (int i = 0; i < size; ++i) {
        factors->sequence[i] = Simplifier(factors->sequence[i]);
    } // Simplify Fraction

    // Print Result
    printFactorResult(factors, size - 1);
    latexStyleOutput(factors, size - 1);

    free(value_sequence);
    return 0;
}