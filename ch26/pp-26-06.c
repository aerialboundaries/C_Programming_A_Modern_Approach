/*
Write programs that display the current date and time in each of the following
formats. Use strftime to do all or most of the formatting.

(a) Sunday, June 3, 2007  05:48p

(b) Sun, 3 Jun 07 17:48

(c) 06/03/07 5:48:34 PM
*/

#include <stdio.h>
#include <time.h>

int main(void)
{
  time_t cur_time = time(NULL);
  struct tm *ptr;
  ptr = localtime(&cur_time);
  char a[64];
  char b[21];
  char c1[21];
  char c2[21];
  int hour = ptr->tm_hour;
  if (hour > 12)
    hour -= 12;

  // (a)
  strftime(a, sizeof(a), "%A, %B %d, %Y %I:%M", ptr);
  printf("%s%c\n", a, ptr->tm_hour <= 11 ? 'a' : 'p');

  // (b)
  strftime(b, sizeof(b), "%a, %d %b %y %H:%M", ptr);
  puts(b);

  // (c)
  strftime(c1, sizeof(c1), "%D ", ptr);
  strftime(c2, sizeof(c2), "%I:%M:%S %p", ptr);
  printf("%s %s\n", c1, c2[0] == '0' ? &c2[1] : c2);

  return 0;
}
