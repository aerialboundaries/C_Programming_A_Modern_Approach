/* C Programming A Modern Approach pp6-3.c
 * 2025-11-6
 *
 * Write a program that asks the user to enter a fraction, then
 * reduces the fraction to lowest terms:
 *
 * Enter a fraction: 6/12
 * In lowest terms: 1/2
 *
 * Hint: To reduce a fraction to lowest terms, first compute
 * the GCD of the numerator and denominator. Then divide both
 * the numerator and denominator by the GCD.
 */

// #include <stdio.h>
//
// int main(void) {
//
//   int n, d, remainder, temp_n, temp_d;
//
//   printf("Enter a fraction: ");
//   scanf("%d/%d", &n, &d);
//   temp_n = n;
//   temp_d = d;
//
//   while (d != 0) {
//     remainder = n;
//     n = d;
//     d = remainder % d;
//   }
//
//   printf("In lowest terms: %d/%d", temp_n / n, temp_d / n);
//
//   return 0;
// }
//
#include <stdio.h>

int main(void) {
  // numerator and denominator from user
  int numerator, denominator;

  // for calculation
  int a, b;

  // for temporal
  int temp;

  // GCD
  int gcd;

  printf("Enter a fraction: ");
  scanf("%d/%d", &numerator, &denominator);

  a = numerator;
  b = denominator;

  while (b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  gcd = a;

  printf("In lowest terms: %d/%d\n", numerator / gcd, denominator / gcd);

  return 0;
}
