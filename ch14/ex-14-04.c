/* C Programming A Modern Approach
 * ex-14-04.c
 * 2026-03-15
 *
 * For each of the followingmacros, give an example that illustrates a problem
 * with the macro and show how to fix it.
 *
 * (a) #define AVA(x, y) (x+y)/2
 * (b) #define AREA(x,y) (x)*(y)
 *
 */

#include <stdio.h>

#define AVG(x, y) (((x) + (y)) / 2) // (a)
#define AREA(x, y) ((x) * (y))      // (b)

int main(void) {
  int x = 2, y = 4;
  printf("= :%d\n", AVG(x, y));
  printf("= :%d\n", AREA(x, y));

  return 0;
}
