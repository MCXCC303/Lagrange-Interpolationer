//
// Created by MCXCC on 2024/8/7.
//

#include "builtin.h"

int pltest() {
  int org[4] = {-1, -3, -4, -5};
  long long *p = polyCalc(4, org);
  return 0;
}