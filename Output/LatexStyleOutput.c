/**
 * @author MCXCC
 * @date 2024/8/9
 */

#include "../SingleValue/builtin.h"
#include <stdio.h>

void latexStyleOutput(Factors *factors, int order) {
  /**
   * @brief Print Factors in Latex Output
   * @param factors
   * @param order
   * @return
   *
   * @note factors should already be simplified
   */
  FILE *output = fopen("output.tex", "w+");
  fprintf(output, "$f(x) = ");
  for (int i = order; i >= 0; --i) {
    if (factors->sequence[i][0] == 0) {
      continue;
    }
    if (factors->sequence[i][1] == factors->sequence[i][0] ||
        factors->sequence[i][1] == 1) {
      fprintf(output, "%lld", factors->sequence[i][0]);
    } else if (factors->sequence[i][1] == factors->sequence[i][0]) {
    } else {
      if (factors->sequence[i][0] * factors->sequence[i][1] > 0) {
        fprintf(output, "\\frac{%lld}{%lld}",
                factors->sequence[i][0] > 0 ? factors->sequence[i][0]
                                            : -factors->sequence[i][0],
                factors->sequence[i][1] > 0 ? factors->sequence[i][1]
                                            : -factors->sequence[i][1]);
      } else {
        fprintf(output, "-\\frac{%lld}{%lld}",
                factors->sequence[i][0] > 0 ? factors->sequence[i][0]
                                            : -factors->sequence[i][0],
                factors->sequence[i][1] > 0 ? factors->sequence[i][1]
                                            : -factors->sequence[i][1]);
      }
    }
    if (i != 0 && i != 1) {
      fprintf(output, "x^{%d}", i);
    } else if (i == 1) {
      fprintf(output, "x");
    }
    if (i != 0) {
      if (factors->sequence[i - 1][0] * factors->sequence[i - 1][1] > 0) {
        fprintf(output, "+");
      }
    }
  }
  fputc('$', output);
  fclose(output);
}