/*
Section 26.3 described some of the ISO 8601 date and time formats. Here are a
few more:

(a) Year followed by day of year: YYYY-DDD, where DDD is a number
    between 001 and 366

(b) Year, week, and day of week: YYYY-Www-D, where ww is a
    number between 01 and 53, and D is a digit between 1 through 7, beginning
    with Monday and ending with Sunday

(c) Combined date and time:
     YYYY-MM-DDThh:mm:ss

Give strftime strings that correspond to each of these formats.
*/

#include <stdio.h>
#include <time.h>

int main(void)
{
  time_t cur_time = time(NULL);
  struct tm *ptr = localtime(&cur_time);
  char date_time[21];

  // (a)
  strftime(date_time, sizeof(date_time), "%Y-%j", ptr);
  puts(date_time);

  // (b)
  strftime(date_time, sizeof(date_time), "%Y-W%V-%u", ptr);
  puts(date_time);

  // (c)
  strftime(date_time, sizeof(date_time), "%Y-%m-%dT%H:%M:%S", ptr);
  puts(date_time);

  return 0;
}
