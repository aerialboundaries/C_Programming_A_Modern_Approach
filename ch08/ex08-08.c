/* C Programming A Modern Approach
 * ex08-08.c
 * 2025-11-22
 *
 * Write a declaration for a two-dimensional array named temperature_readings
 * that stores one month of hourly temperature readings. (For emplicity,
 * assume that a month has 30days.) The rows of the array should represent
 * days of the month: the columns should represent hours of the day. */

#include <stdio.h>

#define DAYS_IN_MONTH 30
#define HOURS_IN_DAY 24

int main(void) {

  float temperature_reading[DAYS_IN_MONTH][HOURS_IN_DAY];

  return 0;
}
