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
#include "../Output/PrintFactorResult.h"

char *singleValueCalc(char *org) {
    // Data Collection
    int *value_sequence;
    FILE *stream;
    stream = fopen("org.in", "w");
    fprintf(stream, "%s", org);
    fclose(stream);
    freopen("org.in", "r", stdin);
    int size = 1;
    value_sequence = (int *) malloc(size * sizeof(int));
    while (scanf("%d", &value_sequence[size - 1]) != EOF) {
        size++;
    }
    size--;

    /*
     * order = size - 1, length of linear sequence = size
     *
     * Example:
     * value_sequence = {1, 7, 3, 12};
     * order = 3, length = 4;
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
    char *result = returnFactorResult(factors, size - 1);
//    latexStyleOutput(factors, size - 1);

    // Free Memory
    free(factors);
    free(lBaseResult->numeratorSequence);
    free(lBaseResult);
    free(value_sequence);
    for (int i = 0; i < size; ++i) {
        free(lineList[i]->sequence);
        free(lineList[i]);
        free(lBaseList[i]->numeratorSequence);
        free(lBaseList[i]);
    }
    fclose(stdin);
    return result;
}