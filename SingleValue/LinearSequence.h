/**
 * @author MCXCC
 * @date 2024/8/8
*/

#ifndef LAGRANGE_INTERPOLATION_LINEARSEQUENCE_H
#define LAGRANGE_INTERPOLATION_LINEARSEQUENCE_H

#include "stdlib.h"

typedef struct linearSequence {
    /**
     * @brief Line: Included a sequence of x and a value as y and a order of which point will this line go for
     *
     * @remark l_i = y0(x-a0)(x-a1)...(x-a_(i-1))(x-a_(i+1))...(x-an)/(ai-a0)(ai-a1)...(ai_(i-1))(ai_(i+1))...(ai-an)
     * @remark sequence = [a0,a1,...,a(i-1),a(i+1),...an]
     * @remark line_order = i
     *
     * @remark In simple, the x of every value will be set into (1,2,3...n)
     * @remark the sequence will trans into:
     * @remark sequence = [1,2,...i-1,i+1,...n]
     *
     * @note Use generateLinearSequence() to generate this sequence
     */
    int *sequence;
    int value;
    int line_order;
} Line;

Line *initLinearSequence(Line *linearSequence, int line_order, int value);

Line *generateLinearSequence(Line *linearSequence, int order);

#endif //LAGRANGE_INTERPOLATION_LINEARSEQUENCE_H
