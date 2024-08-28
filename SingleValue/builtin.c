/**
 * @author MCXCC
 * @date 2024/8/7
 */

#include "builtin.h"

long long factorial(int n) {
  /**
   * @brief Do factorial
   * @param n
   * @return n!
   */
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

long long gcd(long long a1, long long a2) {
  /**
   * @brief Pre-set to calculate full-division algorithm.
   * @param a1
   * @param a2
   * @return gcd
   *
   * @var tmp: Temporary in swpArr
   * @var res: Remainder
   */
  long long n = a1, m = a2;
  long long tmp, res;
  if (m < n) {
    tmp = m;
    m = n;
    n = tmp;
  }
  while ((m % n) != 0) {
    res = m % n;
    m = n;
    n = res;
  }
  return n;
}

long long lcm(long long a, long long b) { return a * b / gcd(a, b); }

void clrArr(long long *arr, int size) {
  /**
   * @brief Clear an array or set the array into default value.
   * @param arr
   * @param size
   * @return
   */
  for (int i = 0; i < size; ++i) {
    arr[i] = 0;
  }
}

void swpArr(long long *arr1, long long *arr2, int size) {
  /**
   * @brief Swap two arrays (MEM changed).
   * @param arr1
   * @param arr2
   * @param size
   * @return
   *
   * @var tmp: Temporary Array
   */
  long long tmp[size];
  for (int i = 0; i < size; ++i) {
    tmp[i] = arr1[i];
    arr1[i] = arr2[i];
    arr2[i] = tmp[i];
  }
}
