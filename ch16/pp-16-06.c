/* C Programming A Modern Approach pp5-9.c
 * pp-16-06.c
 *
 * Write a  program that prompts the user to enter two dates and then
 * indicates which date comes earlier on the calendar:
 *
 * Enter first date (mm/dd/yy): 3/6/08
 * Enter second date (mm/dd/yy): 5/17/07
 * 5/17/07 is earlier than 3/6/08
 *
 * Task:
 * Modify Programming Project 9 from Chapter 5 so that each date entered by the
 * user is stored  in a date structure (see Exercise 5).
 * Incorporate the compare_dates function of Exercise 5 into your program.
 */

#include <stdio.h>

struct dates {
  int month, day, year;
} d1, d2;

int compare_dates(struct dates d1, struct dates d2);

int main(void) {

  printf("Enter first date (mm/dd/yy): ");
  scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);
  printf("Enter second date (mm/dd/yy): ");
  scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);

  if (compare_dates(d1, d2) == -1)
    printf("%d/%d/%.2d is earlier than %d/%d/%.2d", d1.month, d1.day, d1.year,
           d2.month, d2.day, d2.year);
  else if (compare_dates(d1, d2) == 1)
    printf("%d/%d/%.2d is earlier than %d/%d/%.2d", d2.month, d2.day, d2.year,
           d1.month, d1.day, d1.year);
  else
    printf("The two dates are the same.\n");
  return 0;
}

int compare_dates(struct dates d1, struct dates d2) {
  if (d1.year < d2.year)
    return -1;
  if (d1.year > d2.year)
    return 1;
  if (d1.month < d2.month)
    return -1;
  if (d1.month > d2.month)
    return 1;
  if (d1.day < d2.day)
    return -1;
  if (d1.day > d2.day)
    return 1;
  return 0;
}
