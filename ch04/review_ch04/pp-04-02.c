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

int main(void) {
  int number, d1, d2, d3;

  printf("Enter a three digit number: ");
  scanf("%d", &number);

  d1 = number / 100;
  d2 = number % 100 / 10;
  d3 = number % 10;

  printf("The reversal is: %d%d%d\n", d3, d2, d1);

  return 0;
}
