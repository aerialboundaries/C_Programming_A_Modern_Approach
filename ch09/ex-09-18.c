/* C Programming A Modern Approach
 * ex-09-03.c
 * 2026-01-21
 *
 * Write a function gcd(m, n) that calculates the greatest common divisor
 * of the integers m and n. (Programming project 2 in chapter 6 describes
 * Euclid's algorithm for computing the GCD) */

#include <stdio.h>

int gcd(int m, int n);

int main(void) {

  int m, n;
  printf("Enter two integers: ");
  scanf("%d %d", &m, &n);

  printf("Greatest common divisor: %d", gcd(m, n));

  return 0;
}

int gcd(int m, int n) {
  int tmp;
  if (n == 0)
    return m;
  else {
    return gcd(n, m % n);
  }
}
