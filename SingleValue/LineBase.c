/**
 * @author MCXCC
 * @date 2024/8/8
 */

#include "builtin.h"
#include <stdlib.h>

LBase *initLineBase(LBase *lineBase, int order) {
  /**
   * @brief Initialize a LineBase.
   * @param lineBase
   * @param order
   * @return LBase(Initialized)
   *
   * @note LBase->denominator will not be initialized, this directly set by
   * factorial()
   *
   * @example LBase *lineBase1 = initLineBase(*lineBase1, order);
   */
  lineBase = (LBase *)malloc(sizeof(LBase));
  lineBase->numeratorSequence = NULL;
  lineBase->order = order;
  return lineBase;
}

LBase *generateNumerator(Line *linearSequence, LBase *lineBase) {
  /**
   * @brief Generate the numerator sequence of the line and give the sequence to
   * LBase.
   * @param linearSequence
   * @param lineBase
   * @return LBase(Generated)
   *
   * @note The sequence of the line is given by polyCalc()
   *
   * @example LBase *lineBase1 = generateNumerator(*linearSequence, *lineBase1);
   */
  long long *numerator = polyCalc(lineBase->order, linearSequence->sequence);
  for (int i = 0; i < lineBase->order + 1; ++i) {
    numerator[i] *= linearSequence->value;
  }
  lineBase->numeratorSequence = numerator;
  return lineBase;
}

LBase *generateDenominator(Line *linearSequence, LBase *lineBase) {
  /**
   * @brief Generate the denominator of the line and give the denominator to
   * LBase.
   * @param linearSequence
   * @param lineBase
   * @return LBase(Generated)
   *
   * @note The denominator of the line is given by factorial()
   * @note denominator is calculated by (i-1)!(n-i)!(-1)^(n-i)
   * @note there line_order = i, order = n
   *
   * @example LBase *lineBase1 = generateDenominator(*linearSequence,
   * *lineBase1);
   */
  int denominator;
  denominator = factorial(linearSequence->line_order - 1) *
                factorial(lineBase->order + 1 - linearSequence->line_order);
  if ((lineBase->order + 1 - linearSequence->line_order) % 2 == 0) {
    denominator *= 1;
  } else {
    denominator *= -1;
  }
  lineBase->denominator = denominator;
  return lineBase;
}