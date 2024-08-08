/**
 * @author MCXCC
 * @date 2024/8/7
*/

#include "LinearSequence.h"
#include "PreFunc.h"

long long *polyCalc(int order, const int *org) {
    /**
     * Calculate the polynomial.
     * @param order
     * @param org
     * @return *res
     *
     * @example order = 7;
     * @example (x-1)(x-3)(x-4)(x-5)(x-6)(x-7)(x-8)=x^7-34x^6+478x^5-3580x^4+15289x^3-36706x^2+44712x^1-20160
     * @example res = [-20160, 44712, -36706, 15289, -3580, 478, -34, 1];
     * @example length of result = order + 1 (included a constant term)
     *
     */

    long long tmp[2] = {0, 1}, swp[order + 1];

    static long long *res;
    res = malloc(sizeof(long long) * (order + 1));

    /**
     * @var org: Original Coefficients
     * @var tmp: Current formula like (x-1)\n
     *      tmp[1] is always 1 for coefficient of x is 1
     * @var swp: Temporary Coefficients like (x^3-3x^2+2x-2)
     * @var res: Result Array (static)
     *
     * Variable order is come from the length of original data to Interpolation.\n
     * order = size - 1;
     *
     */

    clrArr(swp, order + 1), clrArr(res, order + 1); // Initialize

//    for (int i = 0; i < order; ++i) {
//        printf("a%d:", i + 1);
//        scanf("%d", &org[i]);
//        org[i] = -org[i];
//    } // Collecting the coefficients

    for (int order_res = 0; order_res < order; ++order_res) {
        tmp[0] = org[order_res];
        if (order_res == 0) {
            swp[0] = tmp[0];
            swp[1] = tmp[1];
            continue;
        }
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < order_res + 1; ++j) {
                res[i + j] += tmp[i] * swp[j];
            }
        }
        if (order_res == order - 1) {
            break;
        }
        swpArr(swp, res, order + 1);
        clrArr(res, order + 1);
    }

    clrArr(swp, order + 1), clrArr(tmp, 2);
    return res;
}