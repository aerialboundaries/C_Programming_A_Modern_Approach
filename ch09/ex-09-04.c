/* C Programming A Modern Approach
 * ex-09-04.c
 * 2026-1-22
 *
 * Write a function day_of_year(month, day, year) that returns the day of
 * the year (an integer between 1 and 366) specified by the three arguments. */

#include <stdio.h>

int day_of_year(int month, int day, int year);

int main(void) {

  int month, day, year;
  printf("Enter month, day, year: ");
  scanf("%d %d %d", &month, &day, &year);
  printf("Day of the year: %d\n", day_of_year(month, day, year));

  return 0;
}

int day_of_year(int month, int day, int year) {
  int normal_year[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int reap_year[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int answer = 0, i;

  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
    for (i = 0; i < month; i++) {
      answer += reap_year[i];
    }
    return answer + day;
  } else {
    for (i = 0; i < month; i++) {
      answer += normal_year[i];
    }
    return answer + day;
  }
}
