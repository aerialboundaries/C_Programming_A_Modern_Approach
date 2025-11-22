/* C Programming A Modern Approach
 * ex08-09.c
 * 2025-11-22
 *
 * Using the array of Exercise 8, write a program fragment that computes the
 * average temperature for a month (averaged over all days of the month
 * and all hours of the day).
 */

#include <stdio.h>

#define DAYS_IN_MONTH 30
#define HOURS_IN_DAY 24

int main(void) {

  float temperature_readings[DAYS_IN_MONTH][HOURS_IN_DAY];
  int day, hour;
  float sum = 0.0f;

  for (day = 0; day < DAYS_IN_MONTH; day++) {
    for (hour = 0; hour < HOURS_IN_DAY; hour++) {
      sum += temperature_readings[day][hour];
    }
  }
  printf("Avenrage temperture: %4.2f", sum / (DAYS_IN_MONTH * HOURS_IN_DAY));

  return 0;
}
