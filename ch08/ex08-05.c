/* C Programming A Modern Approach
 * ex08-05
 *
 * 2025-11-22
 *
 * The Fibonacci numbers are 0, 1, 1, 2, 3, 5, 8, 13, ..., where each
 * number is the sum of the two preceeding numbers. Write a program
 * fragment that declares tn array named fib_nubers of lenth 40 and
 * fills the array with the first 40 Fibonacci numbers. Hint:
 * Fill in the first two numbers individually, then use a loop to
 * compute the remaining numbers.
 */

#include <stdio.h>

int main(void) {

  int fib_numbers[40] = {0, 1};
  int i;

  for (i = 2; i < 40; i++) {
    fib_numbers[i] = fib_numbers[i - 2] + fib_numbers[i - 1];
  }

  for (i = 0; i < 40; i++)
    printf(" %d", fib_numbers[i]);

  return 0;
}
