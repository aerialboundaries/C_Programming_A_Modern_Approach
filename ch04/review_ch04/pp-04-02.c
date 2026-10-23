/* C Programming A Modern Approach pp4-2.c
 *
 * Q: Extend the program in Programming Project 1 to handle three-digit numbers.
 * 2026-04-06
 */

/* C Programming A Modern Approach pp4-1.c
 * Write a program that asks the user to enter a two-digit number,
 * then prints the number with its digits reversed.  A session with the program
 * should have the following appearance:
 *
 * Enter a two-digit number: 28
 * The reversal is : 82
 *
 * Read the number using %d, then break it into two digits.
 * Hint: If n is an integer, then n % 10 is the last digit in n and n / 10
 * is n with the last digit revmoved.
 */

#include <stdio.h>

void print_reversed_integer(int n)
{
  if (n == 0) {
    printf("0\n");
    return;
  }

  // in case of negative number
  if (n < 0) {
    putchar('-');
    n = -n;
  }

  while (n > 0) {
    printf("%d", n % 10);
    n /= 10;
  }
  printf("\n");
}

int main(void)
{
  int n;

  printf("Enter a integer: ");
  if (scanf("%d", &n) != 1) {
    fprintf(stderr, "Error: Invalid input format.\n");
    return 1;
  }

  printf("The reversal is: ");
  print_reversed_integer(n);

  return 0;
}
