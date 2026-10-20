/* C Programming A Modern Approach
 * ex-14-01.c
 * 2026-03-15
 *
 * Write paarameterized macros that complete the following values.
 * (a) The cube of x.
 * (b) The remainder when n is divided by 4.
 * (c) 1 if the product of x and y is less than 100, 0 otherwise.
 * Do your macros always work? If not, describe what armements would make them
 * fail.
 */

#include <stdio.h>

#define CUBE(x) ((x) * (x) * (x))                 // (a)
#define REMAINDER(n) ((n) % 4)                    // (b)
#define PRODUCT(x, y) (((x) * (y)) < 100 ? 1 : 0) // (c)

int main(void)
{
  double x = 3.0f;
  int n = 5;
  int x1 = 4, y1 = 16;

  printf("Cube of %4.2f = %f\n", x, CUBE(x));
  printf("Reminder %d %% 4 = %d\n", n, REMAINDER(n));
  printf("Product of %d and %d < 100? %d\n", x1, y1, PRODUCT(x1, y1));

  return 0;
}

/* Macro will fail when passed arguments with ++ / -- */
