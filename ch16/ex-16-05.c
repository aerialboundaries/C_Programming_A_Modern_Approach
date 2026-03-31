/* C Programming A Modern Approach
 * ex-16-05.c
 * 2016-03-30
 *
 * Write the following functions, assuming that the date structure
 * contains three members: month, day, and year (all of type int).
 *
 * (a) int day_of_year(struct date d);
 * Returns the day of the year (an integer between 1 and 366)
 * that corresponds to the date d.
 *
 * (b) int compare_dates(struct date d1, struct date d2);
 * Returns -1 if d1 is an earlier than d2, +1 if d1 is a latter
 * date than d2, and 0 if d1 and d2 are the same.
 */

/* My Answer (a) */
#include <stdio.h>

#define IS_LEAP(n) ((((n) % 400 == 0)) || ((n) % 4 == 0 && (n) % 100 != 0))

struct date {
  int month, day, year;
};

int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);

int main(void) {

  struct date d1 = {6, 4, 1968}, d2 = {10, 14, 2011}, d3 = {10, 14, 2011};

  /// (a)
  printf("The day of %4d/%02d/%02d is: %d\n", d1.year, d1.month, d1.day,
         day_of_year(d1));

  /// (b)
  printf("%d\n", compare_dates(d1, d2));
  printf("%d\n", compare_dates(d2, d3));
}

int day_of_year(struct date d) {
  int days = 0;
  int days_normal[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  for (int i = 0; i < d.month - 1; i++) {
    days += days_normal[i];
  }
  days += d.day;

  if (IS_LEAP(d.year) && (d.month > 2)) {
    days++;
  }

  return days;
}

int compare_dates(struct date d1, struct date d2) {
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
