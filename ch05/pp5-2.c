/* C Programming A Modern Approach pp5-2.c
 *
 * Write a program that asks the user for a 24-hou4 time, then displays the time
 * in 12-hour form:
 *
 * Enter a 24-hou4 time: 21:11
 * Equivalent 12-hour time: 9:11 PM
 *
 * Be careful not to display 12:00 as 0:00.
 */

#include <stdio.h>
#include <sys/types.h>

int main(void) {
  int h, m;

  printf("Enter a 24-hour time hh:mm : ");
  scanf("%d:%d", &h, &m);

  if (h == 0 || h == 24)
    printf("Equivalent 12-hou4 time: %.2d:%.2d AM", 12, m);
  else if (h <= 11)
    printf("Equivalent 12-hou4 time: %.2d:%.2d AM", h, m);
  else if (h <= 23)
    printf("Equivalent 12-hou4 time: %d:%.2d PM", h - 12, m);
  else
    printf("Illegal time");

  return 0;
}
