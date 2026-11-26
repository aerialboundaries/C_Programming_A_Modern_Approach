/* C Programming A Modern Approach
 * pp-09-06.c
 *
 * 2026-01-29
 *
 * Write a function that computes the value of the following polynominal:
 *
 * 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6
 *
 * Write a program that asks the user to entera value for x, calls the
 * function to comute the value of polynominal, and then displays
 * the value returned by the function.
 */

#include <stdio.h>

double poly(double x);

int main(void) {
  double x;

  printf("Enter a number x: ");
  if (scanf("%lf", &x) != 1) {
    printf("Invalid imput.\n");
    return 1;
  }
  printf("Answer : %.2lf\n", poly(x));

  return 0;
}

double poly(double x) {
  return ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
}
