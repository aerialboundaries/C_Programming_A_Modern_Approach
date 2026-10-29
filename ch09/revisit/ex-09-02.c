/* C Programmimg A Modern Approach
 * ex-09-02.c
 * 2026-01-12
 *
 * Write a function check(x, y, n) that returns 1 if both x and y fall
 * between 0 and n - 1, inclusive. The function should return 0 otherwise.
 * Assume that x, y, and n are all of type int.
 */

#include <stdio.h>

int check(int x, int y, int n);

int main(void)
{
  printf("%d\n", check(1, 2, 3));

  return 0;
}

int check(int x, int y, int n)
{
  return (x >= 0 && x <= n - 1 && y >= 0 && y <= n - 1);
}
