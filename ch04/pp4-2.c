/* C Programming A Modern Approach pp4-2.c
 *
 * Q: Extend the program in Programming Project 1 to handle three-digit numbers.
 */

#include <stdio.h>

int main(void) {
  int i;
  int first_digit, second_digit, third_digit;
  printf("Enter a three-digit number: ");
  scanf("%d", &i);

  first_digit = i / 100;
  second_digit = i / 10 % 10;
  third_digit = i % 10;

  printf("%d%d%d\n", third_digit, second_digit, first_digit);

  return 0;
}
