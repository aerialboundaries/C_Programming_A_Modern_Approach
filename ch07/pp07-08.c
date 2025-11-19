/* C Programming A Modern Approach pp07-08.c
 * 2025-11-19
 *
 * Modify Programming Project 8 from Chapter 5 so that the user enters a
 * time using the 12-hour clock. The input will have the form hours: minutes
 * following by either A, P, AM, or PM (either lower-case or upper-case).
 * White space is allowed (but not required) between the numerical time
 * and the AM/PM indicator. Examples of valid input:
 *
 * 1:15P
 * 1:15 PM
 * 1:15 p
 * 1:15 pm
 * 1:15 P
 * 1:15 PM
 * 1:15 p
 * 1:15 pm
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
 */
#include <ctype.h>
#include <stdio.h>

int main(void) {
  int input_hour, input_minute, input_time, dep1, dep2, dep3, dep4, dep5, dep6,
      dep7, dep8, abs_diff, min_diff, flt;
  char ampm;

  dep1 = 60 * 8;
  dep2 = 60 * 9 + 43;
  dep3 = 60 * 11 + 19;
  dep4 = 60 * 12 + 47;
  dep5 = 60 * 14;
  dep6 = 60 * 15 + 45;
  dep7 = 60 * 19;
  dep8 = 60 * 21 + 45;

  printf("Enter a 12-hour time with am, pm, a and p or its upper case: ");
  scanf("%d:%d %c", &input_hour, &input_minute, &ampm);
  ampm = toupper(ampm);

  switch (ampm) {
  case 'A':
    if (input_hour == 12) {
      input_hour = 0;
    } else {
      input_time = 60 * input_hour + input_minute;
    }
    break;
  case 'P':
    input_time = 60 * (input_hour + 12) + input_minute;
    break;
  }

  abs_diff =
      ((input_time - dep1 < 0) ? -(input_time - dep1) : (input_time - dep1));
  min_diff = abs_diff;
  flt = 1;
  printf("min_diff1: %d abs: %d flt:%d\n", min_diff, abs_diff, flt);

  abs_diff =
      (input_time - dep2 < 0) ? -(input_time - dep2) : (input_time - dep2);
  if (min_diff > abs_diff) {
    min_diff = abs_diff;
    flt = 2;
  }

  printf("min_diff2: %d abs: %d flt:%d\n", min_diff, abs_diff, flt);

  abs_diff =
      (input_time - dep3 < 0) ? -(input_time - dep3) : (input_time - dep3);

  if (min_diff > abs_diff) {
    min_diff = abs_diff;
    flt = 3;
  }
  printf("min_diff3: %d abs: %d flt:%d\n", min_diff, abs_diff, flt);

  abs_diff =
      (input_time - dep4 < 0) ? -(input_time - dep4) : (input_time - dep4);

  if (min_diff > abs_diff) {
    min_diff = abs_diff;
    flt = 4;
  }

  printf("min_diff4: %d abs: %d flt:%d\n", min_diff, abs_diff, flt);

  abs_diff =
      (input_time - dep5 < 0) ? -(input_time - dep5) : (input_time - dep5);

  if (min_diff > abs_diff) {
    min_diff = abs_diff;
    flt = 5;
  }

  printf("min_diff5: %d abs: %d flt:%d\n", min_diff, abs_diff, flt);

  abs_diff =
      (input_time - dep6 < 0) ? -(input_time - dep6) : (input_time - dep6);

  if (min_diff > abs_diff) {
    min_diff = abs_diff;
    flt = 6;
  }

  printf("min_diff6: %d abs: %d flt:%d\n", min_diff, abs_diff, flt);

  abs_diff =
      (input_time - dep7 < 0) ? -(input_time - dep7) : (input_time - dep7);

  if (min_diff > abs_diff) {
    min_diff = abs_diff;
    flt = 7;
  }

  printf("min_diff7: %d abs: %d flt:%d\n", min_diff, abs_diff, flt);

  abs_diff =
      (input_time - dep8 < 0) ? -(input_time - dep8) : (input_time - dep8);

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
