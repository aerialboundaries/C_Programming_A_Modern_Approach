/* C Programming A Modern Approach
 * ex-09-06.c
 * 2026-01-22
 *
 * Write a function digit(n, k) that returns the Kth digit (from the right)
 * in n (a positive integer). For example, digit(829, 1) returns 9,
 * digit(829, 2) returns 2, and digit (829, 3) returns 8. If k is greater
 * than the number of digits in n, have the function return 0. */

#include <stdio.h>

int digit(int n, int k);

int main(void) {

  int n, k;

  printf("Enter number n k: ");
  scanf("%d %d", &n, &k);
  printf("Answer: %d\n", digit(n, k));

  return 0;
}

int digit(int n, int k) {
  /* divisor of n */
  int divisor = 1;
  for (int i = 1; i < k; i++)
    divisor *= 10;

  if (n / divisor == 0)
    return 0;

  return (n / divisor) % 10;
}
