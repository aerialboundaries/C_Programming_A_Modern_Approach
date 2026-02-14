/*******************************************************************************
 * C Programming A Modern Approach  * pp-11-02.c
 *                                   * 2026-02-13
 *                                    *
 *                                                                              *
 * Modify Programming Project 8 from Chapter 5 so that it includes the  *
 * following function:  *
 *                                                                              *
 * void find_closest_flight (int desired_time, int *departure_time,  * int
 * *arrival_time);                                                          *
 *                                                                              *
 * This function will find the flight whose departure time is closest to  *
 * desired_time (expressed in minutes since midnight). It will store the  *
 * departure and arrival times of this flight (also expressed in minutes  *
 * since midnight) in the variables pointed to by departure_time and  *
 * arrival_time, respectively.  *
 *                                                                              *
 *                                                                              *
 *******************************************************************************/

/* C Programming A Modern Approach pp5-8.c
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

#define FLIGHTS 8
#define ABS_DIFF(a, b) ((a - b) > 0 ? a - b : b - a)

void find_closest_flight(int desired_time, int *departure_time,
                         int *arrival_time);

void print_closest_flight(int minutes);

int main(void) {
  int input_hour, input_minute, desired_time, departure_time, arrival_time;

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &input_hour, &input_minute);
  desired_time = 60 * input_hour + input_minute;

  find_closest_flight(desired_time, &departure_time, &arrival_time);

  printf("Closest departure time is ");
  print_closest_flight(departure_time);
  printf(", arriving at ");
  print_closest_flight(arrival_time);
  printf("\n");

  return 0;
}

void find_closest_flight(int desired_time, int *departure_time,
                         int *arrival_time) {
  int flt_dep[FLIGHTS] = {60 * 8 + 0,   60 * 9 + 43, 60 * 11 + 19,
                          60 * 12 + 47, 60 * 14 + 0, 60 * 15 + 45,
                          60 * 19,      60 * 21 + 45},
      flt_arr[FLIGHTS] = {60 * 10 + 16, 60 * 11 + 52, 60 * 13 + 31,
                          60 * 15 + 0,  60 * 16 + 8,  60 * 17 + 55,
                          60 * 21 + 20, 60 * 23 + 58},
      smallest_gap = ABS_DIFF(desired_time, flt_dep[0]);
  *departure_time = flt_dep[0];
  *arrival_time = flt_arr[0];

  for (int i = 1; i < FLIGHTS; i++) {
    if (smallest_gap > ABS_DIFF(desired_time, flt_dep[i])) {
      smallest_gap = ABS_DIFF(desired_time, flt_dep[i]);
      *departure_time = flt_dep[i];
      *arrival_time = flt_arr[i];
    }
  }
}

void print_closest_flight(int minutes) {
  int hour, minute;
  hour = minutes / 60;
  minute = minutes % 60;
  if (hour < 12)
    printf("%d:%02d am.", hour, minute);
  if (hour == 12)
    printf("%d:%02d pm.", hour, minute);
  if (hour > 12 && hour < 24)
    printf("%d:%02d pm.", hour - 12, minute);
  if (hour == 24)
    printf("%d:%02d am.", hour - 12, minute);
}
