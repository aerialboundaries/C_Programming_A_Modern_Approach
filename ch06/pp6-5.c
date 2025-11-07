/* C Programming A Modern Approach pp6-5.c
 * 2025-11-07
 *
 * Programming Project 1 in Chapter 4 asked you to write a program that
 * displays a two-digit number with its digits reversed. Generalize the program
 * so that the number can have one, tow, three, or more digits. Hint: Use a
 * do loop that repeatedly divides the number by 10, stopping when it reaches 0.
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
  int any_digit;
  int quotient, remainder;
  printf("Enter a any-digit number: ");
  scanf("%d", &any_digit);
  quotient = any_digit;

  do {
    remainder = quotient % 10;
    quotient = quotient / 10;

    printf("%d", remainder);
  } while (quotient != 0);

  printf("\n");

  return 0;
}
