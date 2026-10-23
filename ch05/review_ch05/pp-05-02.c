/* C Programming A Modern Approach pp5-2.c
 * 2026-04-07
 * rev 2026-10-23
 *
 * Write a program that asks the user for a 24-hour time, then displays the time
 * in 12-hour form:
 *
 * Enter a 24-hour time: 21:11
 * Equivalent 12-hour time: 9:11 PM
 *
 * Be careful not to display 12:00 as 0:00.
 */

#include <stdio.h>

int main(void)
{
  int hour, minute, hour12;

  for (;;) {
    printf("Enter a 24-hour time: ");
    if ((scanf("%d:%d", &hour, &minute) != 2) || (hour < 0 || hour > 23) ||
        (minute < 0 || minute > 59)) {
      fprintf(stderr, "Wrong input. Enter hour:minute.\n");
      while (getchar() != '\n')
        ;
    } else {
      break;
    }
  }

  hour12 = ((hour % 12) == 0 ? 12 : (hour > 12 ? hour - 12 : hour));

  printf("Equivalent 12-hour time: %2d:%02d %s\n", hour12, minute,
         (hour < 12) ? "AM" : "PM");

  return 0;
}
