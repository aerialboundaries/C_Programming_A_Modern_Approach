/* C Programming A Modern Approach pp07-02.c
 * 2025-11-17
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

int main(void) {
  int i, n;
  char ch;

  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n);
  ch = getchar();
  /* dispose of new-line character following number of entries */
  /* could simply be getchar();
   * scanfはユーザーに入力された\nを読み残しとしてのこしてしまう
   * これをキャンセルするためにgetchar()を事前に一回実行する必要
   * がある*/

  for (i = 1; i <= n; i++) {
    printf("%10d%10d\n", i, i * i);
    if (i % 24 == 0) {
      printf("Press Enter to continue...");
      getchar();
    }
  }
  return 0;
}
