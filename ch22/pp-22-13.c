/*
Modify Programming Project 8 from Chapter 5 so that the program obtains
departure and arrival times from a file named flights.dat. Each line of the file
will contain a depar- ture time followed by an arrival time, with one or more
spaces separating the two. Times will be expressed using the 24-hour clock. For
example, here's what flights.dat might look like if it contained the flight
information listed in the original project:

8:00 10:16
9:43 11:52
11:19 13:31
12:47 15:00
14:00 16:08
15:45 17:55
19:00 21:20
21:45 23:58
*/

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
/* Original Program
#include <stdio.h>

int main(void) {
  int input_hour, input_minute, input_time, dep1, dep2, dep3, dep4, dep5, dep6,
      dep7, dep8, abs_diff, min_diff, flt;

  dep1 = 60 * 8;
  dep2 = 60 * 9 + 43;
  dep3 = 60 * 11 + 19;
  dep4 = 60 * 12 + 47;
  dep5 = 60 * 14;
  dep6 = 60 * 15 + 45;
  dep7 = 60 * 19;
  dep8 = 60 * 21 + 45;

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &input_hour, &input_minute);
  input_time = 60 * input_hour + input_minute;

  if (input_time - dep1 < 0) {
    abs_diff = -(input_time - dep1);
  } else {
    abs_diff = (input_time - dep1);
  }
  min_diff = abs_diff;
  flt = 1;
  printf("min_diff1: %d abs: %d flt:%d\n", min_diff, abs_diff, flt);

  if (input_time - dep2 < 0) {
    abs_diff = -(input_time - dep2);
  } else {
    abs_diff = (input_time - dep2);
  }

  if (min_diff > abs_diff) {
    min_diff = abs_diff;
    flt = 2;
  }

  printf("min_diff2: %d abs: %d flt:%d\n", min_diff, abs_diff, flt);

  if (input_time - dep3 < 0) {
    abs_diff = -(input_time - dep3);
  } else {
    abs_diff = (input_time - dep3);
  }

  if (min_diff > abs_diff) {
    min_diff = abs_diff;
    flt = 3;
  }
  printf("min_diff3: %d abs: %d flt:%d\n", min_diff, abs_diff, flt);

  if (input_time - dep4 < 0) {
    abs_diff = -(input_time - dep4);
  } else {
    abs_diff = (input_time - dep4);
  }

  if (min_diff > abs_diff) {
    min_diff = abs_diff;
    flt = 4;
  }

  printf("min_diff4: %d abs: %d flt:%d\n", min_diff, abs_diff, flt);

  if (input_time - dep5 < 0) {
    abs_diff = -(input_time - dep5);
  } else {
    abs_diff = (input_time - dep5);
  }

  if (min_diff > abs_diff) {
    min_diff = abs_diff;
    flt = 5;
  }

  printf("min_diff5: %d abs: %d flt:%d\n", min_diff, abs_diff, flt);

  if (input_time - dep6 < 0) {
    abs_diff = -(input_time - dep6);
  } else {
    abs_diff = (input_time - dep6);
  }

  if (min_diff > abs_diff) {
    min_diff = abs_diff;
    flt = 6;
  }

  printf("min_diff6: %d abs: %d flt:%d\n", min_diff, abs_diff, flt);

  if (input_time - dep7 < 0) {
    abs_diff = -(input_time - dep7);
  } else {
    abs_diff = (input_time - dep7);
  }

  if (min_diff > abs_diff) {
    min_diff = abs_diff;
    flt = 7;
  }

  printf("min_diff7: %d abs: %d flt:%d\n", min_diff, abs_diff, flt);

  if (input_time - dep8 < 0) {
    abs_diff = -(input_time - dep8);
  } else {
    abs_diff = (input_time - dep8);
  }

  if (min_diff > abs_diff) {
    min_diff = abs_diff;
    flt = 8;
  }
  printf("min_diff8: %d abs: %d flt:%d\n", min_diff, abs_diff, flt);

  switch (flt) {

  case 1:
    printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    break;
  case 2:
    printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
    break;
  case 3:
    printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
    break;
  case 4:
    printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
    break;
  case 5:
    printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
    break;
  case 6:
    printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
    break;
  case 7:
    printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
    break;
  case 8:
    printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
    break;
  }

  return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLIGHTS 100

struct flight {
  int dep_total_min;
  int arr_total_min;
};

int main(void)
{
  FILE *in_fp = fopen("flights.dat", "r");
  if (in_fp == NULL) {
    perror("Cannot open flights.dat\n");
    return EXIT_FAILURE;
  }

  struct flight flights[MAX_FLIGHTS];
  int num_flights = 0;
  int h, m, arr_h, arr_m;

  /* read from file */
  while (num_flights < MAX_FLIGHTS &&
         fscanf(in_fp, "%d:%d %d:%d", &h, &m, &arr_h, &arr_m) == 4) {
    flights[num_flights].dep_total_min = h * 60 + m;
    flights[num_flights].arr_total_min = arr_h * 60 + arr_m;
    num_flights++;
  }
  fclose(in_fp);

  /* User input */
  printf("Enter a 24-hour time: ");
  if (scanf("%d:%d", &h, &m) != 2) {
    fprintf(stderr, "time must be in the form of hh:mm (ex 13:13)\n");
    return EXIT_FAILURE;
  }
  int user_time = h * 60 + m;

  /* find the nearest flight */
  int closest_idx = 0;
  int min_diff = abs(user_time - flights[0].dep_total_min);

  for (int i = 1; i < num_flights; i++) {
    int diff = abs(user_time - flights[i].dep_total_min);
    if (diff < min_diff) {
      min_diff = diff;
      closest_idx = i;
    }
  }

  printf("Closest departure time is %02d:%02d, arriving at %02d:%02d\n",
         flights[closest_idx].dep_total_min / 60,
         flights[closest_idx].dep_total_min % 60,
         flights[closest_idx].arr_total_min / 60,
         flights[closest_idx].arr_total_min % 60);

  return 0;
}
