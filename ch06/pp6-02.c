/* C Programming A Modern Approach pp6-02.c
 * 2025-11-6
 *
 * Write a program that asks the user to enter two integers,
 * then calculates and displlays their greatest common divisor (GCD):
 *
 * Enter two integers: 12 28
 * Greatest common divisor: 4
 *
 * Hint: The classic algorithm for computing the GCD, know as Euclid's
 * algorithm, goes as follows: Let m and n be variables containing the
 * two numbers. If n is 0, then stop: m contains the GCD. Otherwise,
 * compute the remainder when m is divided by n. Copy n into m and
 * copy the remainder into n. Then repeat the process, starting with
 * testing whether n is 0.
 */

#include <stdio.h>

int main(void) {

  int m, mo, n; // moという変数名はわかりにくいのでtempなどにすべき
  printf("Enter two integers: ");
  scanf("%d %d", &m, &n);

  while (n != 0) {
    mo = m;
    m = n;
    n = mo % n;
  }
  printf("Greatest common divisor: %d", m);

  return 0;
}
