/* C Programming A Modern Approach pp6-02.c
 * 2025-11-6 revisit 2026-04-08 2026-10-26
 *
 * Write a program that asks the user to enter two integers,
 * then calculates and displays their greatest common divisor (GCD):
 *
 * Enter two integers: 12 28
 * Greatest common divisor: 4
 *
 * Hint: The classic algorithm for computing the GCD, known as Euclid's
 * algorithm, goes as follows: Let m and n be variables containing the
 * two numbers. If n is 0, then stop: m contains the GCD. Otherwise,
 * compute the remainder when m is divided by n. Copy n into m and
 * copy the remainder into n. Then repeat the process, starting with
 * testing whether n is 0.
 */

#include <stdio.h>

int gcd(int m, int n);

int main(void)
{
  int m, n;

  for (;;) {
    printf("Enter two integers: ");
    if (scanf("%d %d", &m, &n) != 2) {
      fprintf(stderr, "Enter two integers.\n");
      continue;
    }
    printf("Greatest common divisor: %d\n", gcd(m, n));
    return 0;
  }
}

int gcd(int m, int n)
{
  int temp;

  for (;;) {
    if (n == 0)
      return m;

    temp = m % n;
    m = n;
    n = temp;
  }

  return 0;
}
