/**
 * @author MCXCC
 * @date 2024/8/8
*/

#include "stdlib.h"
#include "LinearSequence.h"


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