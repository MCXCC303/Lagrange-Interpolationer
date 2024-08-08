/**
 * @author MCXCC
 * @date 2024/8/8
*/

#include "FactorSequence.h"
#include "stdio.h"

void printFactorResult(Factors *factors, int order) {
    printf("f(x) = ");
    for (int i = 0; i < order + 1; ++i) {
        if (factors->sequence[i][0] == 0) {
            if (i < order && factors->sequence[i + 1][0] != 0) {
                printf(" + ");
            }
            continue;
        }
        if (i == 0) {
            if (factors->sequence[i][1] == 1) {
                printf("%lld", factors->sequence[i][0]);
            } else {
                if (factors->sequence[i][0] < 0) {
                    printf("(%lld/%lld)", factors->sequence[i][0], factors->sequence[i][1]);
                } else {
                    printf("%lld/%lld", factors->sequence[i][0], factors->sequence[i][1]);
                }
            }
        } else {
            if (i == 1) {
                printf("x*");
            } else {
                printf("x^%d*", i);
            }
            if (factors->sequence[i][1] == 1) {
                printf("%lld", factors->sequence[i][0]);
            } else {
                printf("(%lld/%lld)", factors->sequence[i][0], factors->sequence[i][1]);
            }
        }
        if (i != order && (i < order && factors->sequence[i + 1][0] != 0)) {
            printf(" + ");
        }
    }
}