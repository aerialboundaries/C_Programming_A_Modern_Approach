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
  char ampm;
  char a[21];
  char b[21];
  char c[21];

  // (a)
  strftime(a, sizeof(a), "%A, %B %e, %Y %I:%M", ptr);
  printf("%s", a);
  if (ptr->tm_hour < 12)
    putchar('a');
  else
    putchar('p');

  printf("\n");

  // (b)
  strftime(b, sizeof(b), "%a, %e %b %C %H:%M", ptr);
  printf("%s\n", b);
}
