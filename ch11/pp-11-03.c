/*******************************************************************************
 * C Programming A Modern Approach  * pp-11-03.c
 *                                   * 2022-02-13
 *                                    *
 *                                                                              *
 * Modify Programming Project 3 from Chapter 6 so that it includes the  *
 * following function:  *
 *                                                                              *
 * void reduce(int numeroator, int denominator, int *reduced_numerator,  * int
 * *reduced_denominator);                                       *
 *                                                                              *
 * numerator and denominator are the numerator and denominator of a fraction.  *
 * reduced_nominator and reduced_denominator are pointers to variables in  *
 * which the function will store the numerator and denominator of the francion
 * * once it has been reduced to lowest terms.   *
 *                                                                              *
 *******************************************************************************/

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

#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator,
            int *reduced_denominator);

int main(void) {
  // numerator and denominator from user
  int numerator, denominator;

  // reduced numerator and denominator
  int reduced_numerator, reduced_denominator;

  printf("Enter a fraction: ");
  scanf("%d/%d", &numerator, &denominator);

  reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);

  printf("In lowest terms: %d/%d\n", reduced_numerator, reduced_denominator);

  return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator,
            int *reduced_denominator) {
  // for calculation
  int a, b;

  // for temporal
  int temp;

  // GCD
  int gcd;

  a = numerator;
  b = denominator;

  while (b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }

  gcd = a;

  *reduced_numerator = numerator / gcd;
  *reduced_denominator = denominator / gcd;
}
