/* Recursion power.c
 * 2026-01-09 */

#include <stdio.h>

int power(int x, int n);

int main(void) {
  int x, n;
  printf("Enter x n : ");
  scanf("%d %d", &x, &n);
  printf("%d ^ %d = %d\n", x, n, power(x, n));

  return 0;
}

int power(int x, int n) {
  if (n == 0)
    return 1;
  else
    return x * power(x, n - 1);
}
