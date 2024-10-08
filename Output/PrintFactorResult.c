/**
 * @author MCXCC
 * @date 2024/8/8
 */

#include "../SingleValue/builtin.h"
#include <stdio.h>

void printFactorResult(Factors *factors, int order) {
  /**
   * @brief Print the factor result in console
   * @param factors
   * @param order
   * @return
   *
   * @note factors should already be simplified
   */
  printf("f(x) = ");
  for (int i = 0; i < order + 1; ++i) {
    if (factors->sequence[i][0] == 0) {
      if (i < order && factors->sequence[i + 1][0] != 0) {
        printf(" + ");
      }
      continue;
    }
    if (i == 0) {
      if (factors->sequence[i][1] == 1) {
        printf("%lld", factors->sequence[i][0]);
      } else {
        if (factors->sequence[i][0] < 0) {
          printf("(%lld/%lld)", factors->sequence[i][0],
                 factors->sequence[i][1]);
        } else {
          printf("%lld/%lld", factors->sequence[i][0], factors->sequence[i][1]);
        }
      }
    } else {
      if (i == 1) {
        printf("x*");
      } else {
        printf("x^%d*", i);
      }
      if (factors->sequence[i][1] == 1) {
        printf("%lld", factors->sequence[i][0]);
      } else {
        printf("(%lld/%lld)", factors->sequence[i][0], factors->sequence[i][1]);
      }
    }
    if (i != order && (i < order && factors->sequence[i + 1][0] != 0)) {
      printf(" + ");
    }
  } // Still have bugs here
}

char *returnFactorResult(Factors *factors, int order) {
  freopen("result.txt", "w+", stdout);
  printf("f(x) = ");
  for (int i = 0; i < order + 1; ++i) {
    if (factors->sequence[i][0] == 0) {
      if (i < order && factors->sequence[i + 1][0] != 0) {
        printf(" + ");
      }
      continue;
    }
    if (i == 0) {
      if (factors->sequence[i][1] == 1) {
        printf("%lld", factors->sequence[i][0]);
      } else {
        if (factors->sequence[i][0] < 0) {
          printf("(%lld/%lld)", factors->sequence[i][0],
                 factors->sequence[i][1]);
        } else {
          printf("%lld/%lld", factors->sequence[i][0], factors->sequence[i][1]);
        }
      }
    } else {
      if (i == 1) {
        printf("x*");
      } else {
        printf("x^%d*", i);
      }
      if (factors->sequence[i][1] == 1) {
        printf("%lld", factors->sequence[i][0]);
      } else {
        printf("(%lld/%lld)", factors->sequence[i][0], factors->sequence[i][1]);
      }
    }
    if (i != order && (i < order && factors->sequence[i + 1][0] != 0)) {
      printf(" + ");
    }
  }
  char *result = (char *)malloc(sizeof(char) * 1000);
  fclose(stdout);
  FILE *fp = fopen("result.txt", "r");
  fgets(result, 256, fp);
  fclose(fp);
  return result;
}
