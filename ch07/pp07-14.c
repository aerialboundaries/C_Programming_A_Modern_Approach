/* C Programming A Modern Approach pp07-14.c
 * 2025-11-19
 *
 * Write a program that uses Newton's method to comput the square root of
 * a positive floating-point number:
 *
 * Enter a positive nuber: 3
 * Square root: 1.73205
 *
 * Let x be the number entered by the user. Newtin's method requires an
 * initial guess y for the square root of x (we'll use y = 1).
 * Successive guesses are foud by computing the average of y an x/y.
 * The following table shows how the square root of 3 would be found:
 *
 *                                  Average of
 * x      y         x/y       y and x/y
 * 3      1         3           2
 * 3      2         1.5         1.75
 * 3      1.75      1.71429     1.73214
 * 3      1.73214   1.73196     1.73205
 * 3      1.73205   1.73205     1.73205
 *
 * Note that the valudes of y get progressively coloser to the true square
 * root of x. For greater accuracy, your program shuld use variables of
 * type double rather than float. Have the probram terminate when the
 * abosolute vaolue of the difference between the oll valu of y and the
 * new value of y is less than th product of .00001 and y. Hint: Call the
 * fabs function to find the absolute valud of a double. (You'll need to
 * include the <math.h> header at the beginning of your program in order to
 * use fabs.) */

#include <math.h>
#include <stdio.h>

int main(void) {

  float x, x,

      return 0;
}
