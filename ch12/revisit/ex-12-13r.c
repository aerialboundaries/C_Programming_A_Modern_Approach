/* C Programming A Modern Approach
 * ex-12-13.c
 * 2026-02-17, 2026-11-05
 *
 * Section 8.2 had a program fragment in which two nested for loops initialized
 * the array ident for use as an identity matrix. Rewrite this code, using a
 * single pointer to step through the array one element at a time. Hint: Since
 * we won't be using row and col index variables, it won't be easy to tell where
 * to store 1. Instead, we can use the fact that the first element of the array
 * should be 1, the next N elements should be 0, the next element should be 1,
 * and so forth. Use a variable to keep track of how many consecutive 0s have
 * been stored; when the count reaches N, it's time to store 1.
 */

#include <stdio.h>

#define N 10

void make_ident(double *p_ident);

int main(void)
{
  double ident[N][N];
  make_ident((double *)ident);

  return 0;
}

void make_ident(double *p_ident)
{
  int consec_zero = N;
  double *p;

  for (p = p_ident; p < p_ident + N * N; p++) {
    if (consec_zero == N) {
      *p = 1.0;
      consec_zero = 0;
    } else {
      *p = 0.0;
      consec_zero++;
    }
    printf("%6.1f", *p);
    if ((p - p_ident + 1) % N == 0)
      printf("\n");
  }
}
