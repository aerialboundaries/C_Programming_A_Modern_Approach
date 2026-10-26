/* C Programming A Modern Approach pp07-02.c
 * 2025-11-17 revisited 2026-04-12 2026-10-26
 *
 * Modify the square2.c program of Section 6.3 so that it pauses after
 * every 24 squares and displays the following message:
 *
 * Press Enter to cntinue...
 *
 * After displaying the message, the program shuld use getchar to read
 * a character. getchar won't allow the program to continue until the
 * user presses the Enter key.
 */

#include <stdio.h>

int main(void)
{
  int i, n;

  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n);
  while (getchar() != '\n')
    ;

  for (i = 1; i <= n; i++) {
    printf("%10d%10d\n", i, i * i);
    if (i % 24 == 0) {
      printf("Press Enter to continue...\n");
      getchar();
    }
  }

  return 0;
}
