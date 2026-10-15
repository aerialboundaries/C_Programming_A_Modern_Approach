/*
Write a program that prompts the user to enter two dates, then prints the
difference between them, measured in days. Hint: Use the mktime and difftime
functions.
*/

#include <stdio.h>
#include <time.h>

int main(void)
{
  struct tm e = { 0 };
  e.tm_isdst = -1;
  struct tm s = { 0 };
  s.tm_isdst = -1;

  printf("imput end date (ex: 2006-10-14): ");
  scanf("%d-%d-%d", &e.tm_year, &e.tm_mon, &e.tm_mday);
  e.tm_year -= 1900;
  e.tm_mon--;

  printf("imput start date (ex: 1968-6-4): ");
  scanf("%d-%d-%d", &s.tm_year, &s.tm_mon, &s.tm_mday);
  s.tm_year -= 1900;
  s.tm_mon--;

  time_t end = mktime(&e);
  time_t start = mktime(&s);
  printf("days difference : %g days\n", difftime(end, start) / (60 * 60 * 24));

  return 0;
}
