/* C Programming A Modern Approach
 * ex-12-09.c
 * 2026-02-16
 *
 * Write the following fucntion:
 *
 * double inner_product(const double *a, const double *b, int n);
 *
 * a and b both point to arrays of length n. The funcition should
 * return a[0] * b[0] + a[1] * b[1] + ... +a[n-1] * b[n-1].
 * Use pointer arithmetic -- not subscripting -- to visit array elements.
 *
 */

double inner_product(const double *a, const double *b, int n) {
  double sum = 0.0;
  const double *p, *q;
  p = a;
  q = b;
  for (int i = 0; i < n; i++) {
    sum += *p++ * *q++;
  }
  return sum;
}
