/* C Programming A Modern Approach
 * ex-14-09.c
 * 2026-03-17
 *
 * Write the following parameterized macros.
 * (a) CHECK(x, y, n) -- Has the value 1 if both x and y fall
 *     between 0 and n-1, inclusive.
 * (b) MEDIAN(x, y, z) -- Finds the median of x, y, and z.
 * (c) POLYNOMIAL(x) - Computes the polynomial 3x^5 + 2x^4 - 5x^3 - x^2 + 7x -6.
 */

#include <stdio.h>

#define CHECK(x, y, n)                                                         \
  ((x) >= 0 && (x) <= (n) - 1) && ((y) >= 0 && (y) <= (n) - 1) ? 1 : 0

#define MEDIAN(x, y, z)                                                        \
  ((x) <= (y) ? ((y) <= (z) ? (y) : ((x) <= (z) ? (z) : (x)))                  \
              : ((x) <= (z) ? (x) : ((y) <= (z) ? (z) : (y))))

#define POLYNOMIAL(x)                                                          \
  ((((3 * (x) + 2) * (x) - 5) * (x) - 1) * (x) + 7) * (x) - 6

int main(void) {
  printf("(a): %d\n", CHECK(1, 3, 3));
  printf("(b): %d\n", MEDIAN(7, 3, 4));
  printf("(c): %d\n", POLYNOMIAL(3));

  return 0;
}
