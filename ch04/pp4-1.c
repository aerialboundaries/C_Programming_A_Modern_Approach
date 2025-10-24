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
  int i;
  int first_digit, second_digit;
  printf("Enter a two-digit number: ");
  scanf("%d", &i);

  first_digit = i / 10;
  second_digit = i % 10;

  printf("%d%d\n", second_digit, first_digit);

  return 0;
}
