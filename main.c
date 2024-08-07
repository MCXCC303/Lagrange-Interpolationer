/**
 * @author MCXCC
 * @date 2024/8/7
*/

#include "PreFunc.h"
#include "stdio.h"

int main() {
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

    Line *lineList[size];
    for (int i = 0; i < size; ++i) {
        initLinearSequence(lineList[i]);
    }
    for (int i = 0; i < size; ++i) {
        lineList[i]->value = value_sequence[i];
        lineList[i]->line_order = i + 1;
    }

    LBase *lBaseList[size];
    for (int i = 0; i < size; ++i) {
        initLineBase(lBaseList[i]);
    }

    return 0;
}