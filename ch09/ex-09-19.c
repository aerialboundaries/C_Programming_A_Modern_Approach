/* C Programming A Modern Approach
 * ex-09-19.c
 * 2026-01-23
 *
 * Consider the following "mystery" function:
 * void pb(int n)
 * {
 *    if (n != 0) {
 *    pb(n / 2);
 *    putchar('0' + n % 2);
 *    }
 * }
 *
 * Trace the execution of the function by hand. Then write a program
 * that calls the function, passint it a number entered by the user.
 * What dows the function do?
 */

#include <stdio.h>

void pb(int n);

int main(void) {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  pb(n);

  return 0;
}

void pb(int n) {
  if (n != 0) {
    pb(n / 2);
    putchar('0' + n % 2);
  }
}
