/* C Programming A Modern Approach
 * ex-14-06.c
 * 2026-03-17
 *
 * (a) Write a macro DISP(f, x) that expands into a call of printf that
 * displays the value of function f when called with argument x.
 * For example,
 *
 * DISP(sqrt, 3.0);
 *
 * should expand into
 * printf("sqrt(%g) = %g\n", 3.0, sqrt(3.0));
 *
 * (b) Write a macro DISP2(f, x, y) that's similar to DISP but
 * works for functions with two arguments.
 *
 */

#include <math.h>
#include <stdio.h>

#define DISP(f, x) (printf(#f "(%g) = %g\n", (double)(x), (f)(x)))
#define DISP2(f, x, y) (printf(#f "(%d, %d) = %d\n", (x), (y), (f)((x), (y))))

int add(int x, int y) { return x + y; }

int main(void) {
  DISP(sqrt, 3.0);
  DISP2(add, 2, 3);

  return 0;
}
