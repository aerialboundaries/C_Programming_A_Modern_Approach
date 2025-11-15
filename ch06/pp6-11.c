/* C Programming A Modern Approach pp6-11.c
 * 2025-11-08
 *
 * The value of the mathematical constant e can be exressed as an inifite
 * series:
 *
 * e = 1 + 1/1! + 1/2! + 1/3! + ...
 *
 * Write a program that approximates e by computing the value of
 * 1 + 1/1! + 1/2! + 1/3! ... + 1/n!
 * where n is an integer entered by the user.
 */

// #include <stdio.h>
//
// int main(void) {
//   int n;
//   float x, e;
//   printf("Enter a number: ");
//   scanf("%d", &n);
//
//   for (int i = 1; i <= n; i++) {
//     for (float i2 = 1; i2 <= i; i2++)
//       x += 1 / i2;
//   }
//   e = 1 + x;
//   printf("e = %4.2f", e);
// }
//
#include <stdio.h>

int main(void) {
  int n;
  float e = 1.0f;
  float factorial = 1.0f;

  printf("Enter a number: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    factorial *= i;
    e += 1.0f / factorial;
  }
  printf("Approximation of e: %f\n", e);
  return 0;
}
