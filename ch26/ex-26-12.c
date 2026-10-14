/*
 Write a function that, when passed a year, returns a time_t value representing
 12:00 a.m. on the first day of that year.
*/

#include <stdio.h>
#include <time.h>

time_t get_first_day_of_year(int year)
{
  struct tm t = { 0 };
  t.tm_year = year - 1900;
  t.tm_mon = 0;
  t.tm_mday = 1;
  t.tm_hour = 0;
  t.tm_min = 0;
  t.tm_sec = 0;
  t.tm_isdst = -1;
  return mktime(&t);
}

int main(void)
{
  int year = 2006;
  time_t raw_time = get_first_day_of_year(year);

  if (raw_time == (time_t)-1) {
    fprintf(stderr, "Failed to convert time\n");
    return 1;
  }

  printf("First day of year %d: %s", year, ctime(&raw_time));

  return 0;
}
