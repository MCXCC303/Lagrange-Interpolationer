/**
 * @author MCXCC
 * @date 2024/8/8
*/

#ifndef LAGRANGE_INTERPOLATION_LINEARSEQUENCE_H
#define LAGRANGE_INTERPOLATION_LINEARSEQUENCE_H

#include "stdlib.h"

typedef struct linearSequence {
    int *sequence;
    int value;
    int line_order;
} Line;

Line *initLinearSequence(Line *linearSequence, int line_order, int value);

Line *generateLinearSequence(Line *linearSequence, int order);

#endif //LAGRANGE_INTERPOLATION_LINEARSEQUENCE_H
