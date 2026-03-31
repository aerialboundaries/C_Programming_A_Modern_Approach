/* C Programming A Modern Approach
 * ex-16-07.c
 * 2016-03-30
 *
 * Assume that the fraction structure contains two members: numerator
 * and denominator (both of type int). Write function that perform
 * the following operations on fractions:
 *
 * (a) Reduce the fraction f to lowest terms. Hint: To reduce a
 * fraction to lowest terms, first compute the greatest common divisor (GCD)
 * of the numerator and denominator. Then divide both the numerator
 * and denominator by the GCD.
 *
 * (b) Add the fractions f1 and f2.
 *
 * (c) Substract the fraction f2 from the fraction f1.
 *
 * (d) Multiply the fractions f1 and f2.
 *
 * (e) Divide the faction f1 by the fraction f2.
 *
 * The fraction f, f1 and f2 will be arguments of type struct fraction;
 * each function will return a value of type struct fraction. The fractions
 * returned by the function in parts (b) - (3) should be reduced to lower
 * terms. Hint: You may use the function from part (a) to help write the
 * functions in parts (b) - (e).
 */

/// My Answer:
#include <stdio.h>

typedef struct {
  int numerator, denominator;
} Fraction;
