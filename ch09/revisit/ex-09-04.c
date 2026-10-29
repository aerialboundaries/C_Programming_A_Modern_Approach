/* C Programming A Modern Approach
 * ex-09-04.c
 * 2026-1-22 2026-10-28
 *
 * Write a function day_of_year(month, day, year) that returns the day of
 * the year (an integer between 1 and 366) specified by the three arguments. */

#include <stdbool.h>
#include <stdio.h>

int day_of_year(int month, int day, int year);
bool is_leap(int year);

int main(void)
{
  int month = 5, day = 20, year = 2026;

  printf("Day %d in month %d of year %d = Day %d of the year\n", day, month,
         year, day_of_year(month, day, year));

  return 0;
}

bool is_leap(int year)
{
  return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int day_of_year(int month, int day, int year)
{
  int days_in_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  int days_in_year = 0;

  if (is_leap(year))
    days_in_month[2] = 29;

  for (int i = 0; i < month; i++) {
    days_in_year += days_in_month[i];
  }
  return days_in_year + day;
}
