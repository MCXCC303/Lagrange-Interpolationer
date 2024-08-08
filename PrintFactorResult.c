/**
 * @author MCXCC
 * @date 2024/8/8
*/

#include "FactorSequence.h"
#include "stdio.h"
#include "math.h"

void printFactorResult(Factors *factors, int order) {
    printf("f(x) = ");
    for (int i = 0; i < order + 1; ++i) {
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
            printf("x^%d*", i);
            if (factors->sequence[i][1] == 1) {
                printf("%lld", factors->sequence[i][0]);
            } else {
                if (factors->sequence[i][0] < 0) {
                    printf("(%lld/%lld)", factors->sequence[i][0], factors->sequence[i][1]);
                } else {
                    printf("%lld/%lld", factors->sequence[i][0], factors->sequence[i][1]);
                }
            }
        }
        if (i != order) {
            printf(" + ");
        }
    }
}