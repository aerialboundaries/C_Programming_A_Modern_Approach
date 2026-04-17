/* C Programming A Modern Approach
 * pp08-02.c revisited
 * 2025-11-25 2026-04-17
 *
 * Modify the repdigit.c program of Section 8.1 so that it prints
 * a table showing how many timeos each digit appears in the number.
 *
 * Enter a number : 41271092
 * Digit:       0   1   2   3   4   5   6   7   8   9
 * Occureences: 1   2   2   0   1   0   0   1   0   1
 */

#include <stdbool.h>
#include <stdio.h>

int main(void) {

  int occureences[10] = {0};
  int digit;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10;
    occureences[digit]++;
    n /= 10;
  }

  for (int i = 0; i < 10; i++)
    printf("%-3d", i);

  printf("\n");

  for (int i = 0; i < 10; i++)
    printf("%-3d", occureences[i]);

  printf("\n");

  return 0;
}
