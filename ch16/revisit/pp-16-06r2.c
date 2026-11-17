/* C Programming A Modern Approach pp5-9.c
 * pp-16-06.c
 * revisit 2026-11-17
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

typedef struct date {
  int m, d, y;
} Date;

int compare_dates(const struct date *d1, const struct date *d2);

int main(void)
{
  Date d1, d2;

  printf("Enter first date (mm/dd/yy): ");

  if (scanf("%d/%d/%d", &d1.m, &d1.d, &d1.y) != 3) {
    fprintf(stderr, "Wrong date.\n");
    return 1;
  }

  printf("Enter second date (mm/dd/yy): ");

  if (scanf("%d/%d/%d", &d2.m, &d2.d, &d2.y) != 3) {
    fprintf(stderr, "Wrong date.\n");
    return 1;
  }

  if (compare_dates(&d1, &d2) == -1)
    printf("%d/%d/%02d is earlier than %d/%d/%02d\n", d1.m, d1.d, d1.y, d2.m,
           d2.d, d2.y);
  else if (compare_dates(&d1, &d2) == 1)
    printf("%d/%d/%02d is earlier than %d/%d/%02d\n", d2.m, d2.d, d2.y, d1.m,
           d1.d, d1.y);
  else
    printf("Two dates are the same.\n");

  return 0;
}

int compare_dates(const Date *d1, const Date *d2)
{
  if (d1->y != d2->y)
    return (d1->y < d2->y) ? -1 : 1;

  if (d1->m != d2->m)
    return (d1->m < d2->m) ? -1 : 1;

  if (d1->d != d2->d)
    return (d1->d < d2->d) ? -1 : 1;

  return 0;
}
