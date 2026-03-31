/* C Programming A Modern Approach
 * ex-16-06.c
 * 2016-03-30
 *
 * Write the following function, assuming that the time structure contains
 * three members: hours, minutes, and seconds (all type int).
 * struct time split_time(long total_seconds);
 * total_secodns is a time represented as the number of seconds since
 * midnight. The fucnction returns a structure containing the equivalent
 * time in hours (0-23), minutes (0-59), and seconds(0-59).
 */

#include <stdio.h>

#define MAX_SEC 86400

struct time {
  int hours, minutes, seconds;
};

struct time split_time(long total_seconds);

int main(void) {
  long total_seconds = 0;
  for (;;) {
    printf("Input total seconds: ");
    if (scanf("%ld", &total_seconds) != 1)
      printf("Invalid input. Please input again\n");

    if (total_seconds > MAX_SEC)
      printf("Invalid number. Please input again\n");
    else
      break;
  }

  printf("Total %ld seconds from midnight : %02d:%02d:%02d\n", total_seconds,
         split_time(total_seconds).hours, split_time(total_seconds).minutes,
         split_time(total_seconds).seconds);

  return 0;
}

struct time split_time(long total_seconds) {
  struct time t1;
  int remaining_sec = total_seconds;
  t1.hours = total_seconds / 3600;
  remaining_sec = total_seconds - t1.hours * 3600;
  t1.minutes = remaining_sec / 60;
  remaining_sec = remaining_sec - t1.minutes * 60;
  t1.seconds = remaining_sec;
  return t1;
}
