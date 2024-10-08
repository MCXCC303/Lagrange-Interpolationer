/**
 * @author MCXCC
 * @date 2024/8/8
 */

#include "builtin.h"

long long *Simplifier(long long *arr) {
  /**
   * @brief Get a 1D vector (nu,de) input, use nu as the numerator and de as the
   * denominator, simplify the fraction and return a 1D vector (nu',de')
   *
   * @param arr: a 1D vector (nu,de)
   * @return a 1D vector (nu',de')
   *
   * @example before: arr = {4,6}
   * @example after: arr = {2,3}
   *
   * @note The value of original array will be changed
   */
  if (*arr == 0) {
    return arr;
  }
  long long _gcd = gcd(*arr, *(arr + 1));
  *arr /= _gcd;
  *(arr + 1) /= _gcd;
  return arr;
}