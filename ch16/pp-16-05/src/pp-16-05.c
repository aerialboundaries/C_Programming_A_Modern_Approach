/* C Programming A Modern Approach pp-16-05.c
 * 2026-04-02
 *
 * The following table shows the daily flights from one city to another:
 *
 * Departure time       Arrival tile
 *   8:00 a.m.             10:16 a.m
 *   9:43 a.m.             11:52 a.am
 *  11:19 a.m.             1:31 p.m.
 *  12:47 p.m.             3:00 p.m.
 *   2:00 p.m.             4:08 p.m.
 *   3:45 p.m.             5:55 p.m.
 *   7:00 p.m.             9:20 p.m.
 *   9:45 p.m.            11:58 p.m.
 *
 * Wirte a program that asks user to enter a time (expressed in huors and
 * minutes, using the 24-hour clock). The program then displays the departure
 * and arrival times for the flight whose departure tume is closest to that
 * entered by user:
 *
 * Enter a 24-hou4 time : 13:13
 * Closest departure time is 12:47 p.m., arriving at 3:00 p.m.
 *
 * Hint: Convert the input into a time expressed in minutes since midnight,
 * and compare it to the departure times, also expressed in minutes since
 * midnight. For example, 13:15 is 13 x 60 + 15 = 795 minutes since midnight,
 * which is closer to 12:47 p.m. (767 minutes since midnight) than to any of the
 * other departure times.
 */

#include <stdio.h>

#include "flights.h"
#include "timecalc.h"

int main(void) {
  int input_hour, input_minute, input_time;

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &input_hour, &input_minute);
  input_time = 60 * input_hour + input_minute;

  int minimum_time_diff, closest = FLIGHT_1;

  minimum_time_diff = abs_sec(flt[FLIGHT_1].dep - input_time);

  for (int i = FLIGHT_2; i < FLIGHT_MAX; i++) {
    int diff = abs_sec(flt[i].dep - input_time);
    if (diff < minimum_time_diff) {
      minimum_time_diff = diff;
      closest = i;
    }
  }

  printf("Closest departure time is %s\n", time(flt[closest].dep));
  printf("Arriving at %s\n", time(flt[closest].arr));

  return 0;
}
