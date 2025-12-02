/* C Programming A Modern Approach
 * pp10-10.c
 * 2025-12-01
 *
 * Modify Programming Project 8 from Chapter 5 so that the deparure times
 * are stored in an array and the arrival times are stored in a second array.
 * (The times are intergers, representing theh number of minutes since
 * midnight.) The program will use a loop to search the array of departure times
 * for the one closest to the time entered by the user. */

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

#define DEP 8
#define ARR 8

int main(void) {
  int input_hour, input_minute, input_time, abs_diff, min_diff = 1440, flt,
                                                      closest_flt;

  const int departure[DEP] = {60 * 8,       60 * 9 + 43, 60 * 11 + 19,
                              60 * 12 + 47, 60 * 14,     60 * 15 + 45,
                              60 * 19,      60 * 21 + 45};
  const int arrival[ARR] = {60 * 10 + 16, 60 * 11 + 52, 60 * 13 + 31,
                            60 * 15,      60 * 16 + 8,  60 * 17 + 55,
                            60 * 19 + 20, 60 * 23 + 58};

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &input_hour, &input_minute);
  input_time = 60 * input_hour + input_minute;

  for (flt = 0; flt < 8; flt++) {
    if (input_time - departure[flt] < 0) {
      abs_diff = -(input_time - departure[flt]);
    } else {
      abs_diff = (input_time - departure[flt]);
    }
    if (min_diff > abs_diff) {
      min_diff = abs_diff;
      closest_flt = flt;
    }
  }

  switch (closest_flt) {

  case 0:
    printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    break;
  case 1:
    printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
    break;
  case 2:
    printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
    break;
  case 3:
    printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
    break;
  case 4:
    printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
    break;
  case 5:
    printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
    break;
  case 6:
    printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
    break;
  case 7:
    printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
    break;
  }

  return 0;
}
