/* C Programming A Modern Approach
 * pp08-02.c revisited
 * 2025-11-25 2026-04-17 2026-10-27
 *
 * Modify the repdigit.c program of Section 8.1 so that it prints
 * a table showing how many times each digit appears in the number.
 *
 * Enter a number : 41271092
 * Digit:       0   1   2   3   4   5   6   7   8   9
 * Occureences: 1   2   2   0   1   0   0   1   0   1
 */

#include <stdio.h>

int main(void)
{
  int occurrences[10] = { 0 };
  int digit;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  if (n == 0) {
    occurrences[0] = 1;
  } else {
    while (n > 0) {
      digit = n % 10;
      occurrences[digit]++;
      n /= 10;
    }
  }

  printf("Digit:        :");
  for (int i = 0; i < 10; i++)
    printf("%3d  ", i);
  printf("\n");

  printf("Occurrences:  :");
  for (int i = 0; i < 10; i++)
    printf("%3d  ", occurrences[i]);
  printf("\n");

  return 0;
}
