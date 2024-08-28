#ifndef BUILTIN_H
#define BUILTIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

typedef struct lineBase {
  /**
   * @brief LBase included a sequence of numerator and a denominator
   *
   * @example Line: sequence = [-1,-3,-4,-5]
   * @example value = 4
   * @note The numerator directly comes from the polyCalc()
   * @note The denominator comes from factorial()
   * @note After polyCalc there get [60,-107,59,-13,1] as numeratorSequence
   * @note (Means (x-1)(x-3)(x-4)(x-5)=60-107x+59x^2-13x^3+x^4)
   * @note Variable order is the same as the polyCalc()
   * @note In doing factorial first get the order of current line
   * @note l_i's denominator could trans into (i-1)!(n-i)!(-1)^i
   * @note there line_order = i, value_size = n
   *
   * @var numeratorSequence: The numerator of the line
   * @var order: The order of the line
   * @var denominator: The denominator of the line
   */
  long long *numeratorSequence;
  int order;
  int denominator;
} LBase;

typedef struct FactorSequence {
  long long **sequence;
} Factors;

typedef struct linearSequence {
  int *sequence;
  int value;
  int line_order;
} Line;

Factors *sequenceTransfer(Factors *factors, LBase *lineBase);

LBase *doFractionAddition(LBase *lineBase1, LBase *lineBase2);

long long *Simplifier(long long *arr);

Line *initLinearSequence(Line *linearSequence, int line_order, int value);

Line *generateLinearSequence(Line *linearSequence, int order);

LBase *initLineBase(LBase *lineBase, int order);

LBase *generateNumerator(Line *linearSequence, LBase *lineBase);

LBase *generateDenominator(Line *linearSequence, LBase *lineBase);

long long *polyCalc(int order, const int *org);

long long factorial(int n);

long long gcd(long long a1, long long a2);

long long lcm(long long a1, long long a2);

void clrArr(long long *arr, int size);

void swpArr(long long *arr1, long long *arr2, int size);

char *singleValueCalc(char *org);

#ifdef __cplusplus
}
#endif

#endif // BUILTIN_H