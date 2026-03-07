/* C Programming A Modern Approach
 * pp-13-02.c
 * 2026-03-06
 *
 * Improve the remind.c program of Section 13.5 in the following ways:
 *
 * (a) Have the program print an error message and igrore a reminder if
 *     the corresponding day is negavie or larger than 31. Hint: Use the
 *     continue statement.
 *
 * (b) Allow the user to enter a day, a 24-hour time, and a reminder.
 *     The printed reminder list should be sorted first by day, then by time.
 *     (The original program allows the user to enter a time, but it's treated
 *     as part of the reminder.)
 *
 * (c) Have the program print a one-year reminder list. Require the user to
 *     enter days in the form month / day.
 */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50 /* maximum number of reminders */
#define MSG_LEN 60    /* max length of reminder message */

int read_line(char str[], int n);

int main(void) {
  char reminders[MAX_REMIND][MSG_LEN + 14];
  char day_time_str[14], msg_str[MSG_LEN + 1];
  int month, day, hour, minute, i, j, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter day time (ex: 10 / 24 13:15 and reminder: ");
    scanf("%2d", &month);
    if (month == 0)
      break;

    scanf(" / %2d %2d:%2d", &day, &hour, &minute);

    if (month < 0 || month > 12 || day < 0 || day > 31 || hour < 0 ||
        hour > 24 || minute < 0 || minute > 59) {
      printf("invalid input\n");
      while (getchar() != '\n')
        ; // do nothing. clear buffer.
      continue;
    }

    sprintf(day_time_str, "%02d / %02d %02d:%02d", month, day, hour, minute);
    read_line(msg_str, MSG_LEN);

    for (i = 0; i < num_remind; i++)
      if (strcmp(day_time_str, reminders[i]) < 0)
        break;
    for (j = num_remind; j > i; j--)
      strcpy(reminders[j], reminders[j - 1]);

    strcpy(reminders[i], day_time_str);
    strcat(reminders[i], msg_str);

    num_remind++;
  }
  printf("\nMonth / Day Time Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf(" %s\n", reminders[i]);

  return 0;
}

int read_line(char str[], int n) {
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
