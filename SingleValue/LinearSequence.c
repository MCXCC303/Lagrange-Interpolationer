/**
 * @author MCXCC
 * @date 2024/8/8
*/

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

Line *initLinearSequence(Line *linearSequence, int line_order, int value) {
    /**
     * @brief Initialize a Line.
     * @param linearSequence
     * @param line_order
     * @param value
     * @return Line(Initialized)
     *
     * @note Line->sequence will not be initialized, this directly set by generateLinearSequence()
     *
     * @example Line *line1 = initLinearSequence(line1,line_order,value);
     */
    linearSequence = (Line *) malloc(sizeof(Line));
    linearSequence->sequence = NULL;
    linearSequence->line_order = line_order;
    linearSequence->value = value;
    return linearSequence;
}

Line *generateLinearSequence(Line *linearSequence, int order) {
    /**
     * @brief Generate a Line's sequence.
     * @param linearSequence
     * @param order
     * @return Line(Generated)
     *
     * @note Line->sequence will be initialized
     *
     * @example Line *line1 = generateLinearSequence(line1, order);
     */
    int *sequence;
    sequence = (int *) malloc(sizeof(int) * order);
    for (int i = 0; i < order; ++i) {
        if (i + 1 >= linearSequence->line_order) {
            sequence[i] = -(i + 2);
            continue;
        }
        sequence[i] = -(i + 1);
    }
    linearSequence->sequence = sequence;
    return linearSequence;
}