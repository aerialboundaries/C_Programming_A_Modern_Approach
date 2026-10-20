/* C Programming A Modern Approach
 * ex-14-03.c
 * 2026-03-15
 *
 * Let DOUBLE be the following macro:
 * #define DOUBLE(x) 2*x
 *
 * (a) What is the value of DOUBLE(1+2)?
 * (b) What is the value of  4/DOBLE(2)?
 * (c) Fix the definition of DOUBLE.
 */

#include <stdio.h>

#define DOUBLE(x) (2 * (x))

int main(void)
{
  printf("DOUBLE(1+2) = %d\n", DOUBLE(1 + 2));   // 6
  printf("4 / DOUBLE(2) = %d\n", 4 / DOUBLE(2)); // 1

  return 0;
}
