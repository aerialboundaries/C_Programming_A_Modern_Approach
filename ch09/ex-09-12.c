/* C Programming A Modern Approach
 * ex-09-12.c
 * 2026-01-23
 *
 * Write the following function:
 * double inner_product(double a[], double b[], int n);
 * The function should return a[0] * b[0] + a[1] * b[1] + ... + a[n-1] * b[n-1].
 */

#include <stdio.h>

double inner_product(double a[], double b[], int n);

int main(void) {
  double a[] = {0.25, 4.5, 6.3, -10.5}, b[] = {30, -2.3, 18.3, 0.2};
  int n = 4;
  printf("Answer is: %g\n", inner_product(a, b, n));

  return 0;
}
double inner_product(double a[], double b[], int n) {
  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    sum += a[i] * b[i];
  }
  return sum;
}
