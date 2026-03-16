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

#define DOUBLE(x) 2 * x

int main(void) {
  printf("(a) :%d\n",
         (int)DOUBLE(1 + 2)); // My answer 6 wrong: correct is 4 2*1+2
  printf("(b) :%d\n",
         (int)4 / DOUBLE(2)); // My answer 1 wrong: correct is 4 4/2*2
  printf("(c) #define DOUBLE(x) (2*(x))");

  return 0;
}
