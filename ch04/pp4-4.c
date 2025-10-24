/* C Programming A Modern Approach pp4-4.c
 * Write a program that reads an integer entered by
 * the user and displays it in octal (base8):
 *
 * Enter a number between 0 and 32767: 1953
 * In octal, your number is : 03641
 *
 * The output should be displayed using five digits,
 * even if fewerdigits are sufficient.
 * Hint: To convert the number to octal, first divide it
 * by 8; the remainder is the last digit of the octal
 * number (1, in this case).  Then divide the original
 * number by 8 and repeat the process to arrive at
 * the next-to-last digit.  (print f is capable of
 * displaying numbers in base 8, as we'll see in
 * Chapter 7, so there's actually an easier way to
 * write this program.
 */

#include <stdio.h>

int main(void) {

  int i, q1, r1, q2, r2, q3, r3, q4, r4, q5, r5;

  printf("Enter a number between 0 and 32767: ");
  scanf("%d", &i);
  q1 = i / 8;
  r1 = i % 8;
  q2 = q1 / 8;
  r2 = q1 % 8;
  q3 = q2 / 8;
  r3 = q2 % 8;
  q4 = q3 / 8;
  r4 = q3 % 8;
  q5 = q4 / 8;
  r5 = q4 % 8;

  printf("In octal, your number is : %d%d%d%d%d\n", r5, r4, r3, r2, r1);

  return 0;
}
