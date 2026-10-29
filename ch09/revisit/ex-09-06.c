/* C Programming A Modern Approach
 * ex-09-06.c
 * 2026-01-22 2026-10-28
 *
 * Write a function digit(n, k) that returns the Kth digit (from the right)
 * in n (a positive integer). For example, digit(829, 1) returns 9,
 * digit(829, 2) returns 2, and digit (829, 3) returns 8. If k is greater
 * than the number of digits in n, have the function return 0. */

#include <stdio.h>

int digit(int n, int k);

int main(void)
{
  printf("%d\n", digit(829, 1));

  return 0;
}

int digit(int n, int k)
{
  int count;
  while (n / 10 > 0) {
    n /= 10;
  }

  for (int i = k; i >= 1; i--) {
    divisor *= 10;
    n /= divisor;
  }

  return n % divisor;
}
