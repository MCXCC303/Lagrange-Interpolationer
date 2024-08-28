//
// Created by MCXCC on 2024/8/7.
//
#include "builtin.h"

int adtest() {
  long long numeratorSequence1[2] = {-3, 1};
  long long numeratorSequence2[2] = {-5, 1};
  LBase *lineBase1 = initLineBase(lineBase1, 1);
  lineBase1->numeratorSequence = numeratorSequence1;
  lineBase1->denominator = 4;
  LBase *lineBase2 = initLineBase(lineBase2, 1);
  lineBase2->numeratorSequence = numeratorSequence2;
  lineBase2->denominator = 6;
  LBase *lineBase3 = doFractionAddition(lineBase1, lineBase2);
  return 0;
}