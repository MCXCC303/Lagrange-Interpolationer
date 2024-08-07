/**
 * @author MCXCC
 * @date 2024/8/7
*/

#include "PreFunc.h"
#include "stdio.h"

int main_0() {
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
        initLinearSequence(lineList[i], i + 1, value_sequence[i]);
    }

    LBase *lBaseList[size];
    for (int i = 0; i < size; ++i) {
        initLineBase(lBaseList[i], size - 1);
    }

    return 0;
}