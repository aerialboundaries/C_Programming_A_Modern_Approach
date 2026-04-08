/* C Programming A Modern Approach pp5-2.c
 * 2026-04-07
 *
 * Write a program that asks the user for a 24-hou4 time, then displays the time
 * in 12-hour form:
 *
 * Enter a 24-hour time: 21:11
 * Equivalent 12-hour time: 9:11 PM
 *
 * Be careful not to display 12:00 as 0:00.
 */

#include <stdio.h>

int main(void) {
  int h, m;

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &h, &m);

  printf("Equivalent 12-hour time: ");

  if (h == 0) {
    printf("%2d:%.2d AM\n", 12, m);
  } else if (h < 12) {
    printf("%2d:%.2d AM\n", h, m);
  } else if (h == 12) {
    printf("%2d:%.2d PM\n", h, m);
  } else {
    printf("%2d:%.2d PM\n", h % 12, m);
  }

  return 0;
}
