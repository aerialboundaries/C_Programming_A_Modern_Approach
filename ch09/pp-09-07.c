/* C Programming A Modern Approach
 * pp-09-07.c
 * 2026-01-29
 *
 * The power function of Section 9.6 can be made faster by having it
 * calculate x^n in a different way. We first notice that n is a power
 * of 2, then x^n can be computed by squaring. For example, x^4 is
 * the squiare of x^2, so x^4 can be conputed using only two multiplications
 * instead of three. As it happens, this tequnique can be used even
 * when n is not a power of 2. If n is even, use the formula x^n = (x^n/2)^2.
 * If n is odd, then x^n = x * x^n-1. Write a recursive function
 * that computes x^n. (The recursion ends when n = 0, in which case function
 * returns 1.) To test your function, write a program that asks the user to
 * enter values for x and n, calls power to compute x^n, and then displays the
 * valued returned by the function.
 */

#include <stdio.h>

int power(int x, int n);

int main(void) {

  int x, n;
  printf("Enter x n: ");
  if (scanf("%d %d", &x, &n) != 2) {
    printf("Invalid imput.\n");
    return 1;
  }

  printf("%d ^ %d = %d\n", x, n, power(x, n));

  return 0;
}

int power(int x, int n) {
  if (n == 0) {
    return 1;
  }

  int temp = power(x, n / 2);

  if (n % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
