/* C Programming A Modern Approach
 * ex-09-05.c
 * 2026-01-22
 *
 * Write a function num_digits(n) that returns the number of digits in n
 * (a positive integer). Hint: To determine the number oof digits in a number n,
 * divide it by 10 repeatedly. When n reaches 0, the number of divisions
 * indicates how many digits n originally had. */

#include <stdio.h>

int num_digits(int n);

int main(void) {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  printf("Number of digits: %d\n", num_digits(n));

  return 0;
}
//
// int num_digits(int n) {
//   if (n / 10 == 0)
//     return 1;
//   else
//     return 1 + num_digits(n / 10);
// }

int num_digits(int n) {
  int digits = 0;
  if (n == 0)
    return 1;

  while (n > 0) {
    n /= 10;
    digits++;
  }
  return digits;
}
