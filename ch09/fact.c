/* Recursion fact.c
 * 2026-01-09 */

#include <stdio.h>

int fact(int n);

int main(void) {
  printf("Factorial of 3 : %d\n", fact(3));
  return 0;
}

int fact(int n) {
  if (n <= 1)
    return 1;
  else
    return n * fact(n - 1);
}
