/* C Programming A Modern Approach pp6-08.c
 * 2025-11-07
 *
 * Write a program that prints a one-month calendar. The user specifies
 * the number of days in the month and the day of the week on which the
 * month begings:
 *
 * Enter number of days in month: 31
 * Enter starting day of the week (1=Sun, 7=Sat): 3
 *
 *         1   2   3   4   5
 *  6  7   8   9  10  11  12
 * 13 14  15  16  17  18  19
 * 29 21  22  23  24  25  26
 * 27 28  29  30  31
 *
 * Hint: This program isn't as hard as it looks. The most important part
 * is a for statement that uses a variable i to count from 1 to n, where
 * n is the number of days in the month, printing each value of i. Inside
 * the loop, an if statement tests whether i is the last day in a week; if
 * so, it prints a new-line character.
 */

#include <stdio.h>

int main(void)
{
  int n, day;

  printf("Enter number of days in month: ");
  if (scanf("%d", &n) != 1 || n < 1 || n > 31) {
    fprintf(stderr, "The number shoud be 1 - 31\n");
    return 1;
  }

  printf("Enter starting day of the week (1=Sun, 7=Sat): ");
  if (scanf("%d", &day) != 1 || day < 1 || day > 7) {
    fprintf(stderr, "The number shoud be 1 - 7\n");
    return 1;
  }

  for (int i = 1; i <= day - 1; i++)
    printf("   ");

  for (int i = 1; i <= n; i++) {
    if ((day - 1 + i) % 7 == 0)
      printf("%2d\n", i);
    else
      printf("%2d ", i);
  }

  putchar('\n');

  return 0;
}
