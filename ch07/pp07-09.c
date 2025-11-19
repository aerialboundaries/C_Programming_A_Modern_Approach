/* C Programming A Modern Approach pp07-09.c
 * 2025-11-19
 *
 * Write a program that asks the user for a 12-hour time, then
 * displays the time in 24-hour form.
 *
 * Enter a 12-hour time: 9:11 PM
 * Equivalent 24-hour time: 21:11
 */

#include <ctype.h>
#include <stdio.h>

int main(void) {

  int input_hour, input_minute, output_hour;
  char ampm;

  printf("Enter a 12-hour time: ");
  scanf("%d:%d %c", &input_hour, &input_minute, &ampm);
  ampm = toupper(ampm);

  switch (ampm) {
  case 'A':
    if (input_hour == 12) {
      output_hour = 0;
    } else {
      output_hour = input_hour;
    }
    break;

  case 'P':
    if (input_hour < 12) {
      output_hour = input_hour + 12;
    } else {
      output_hour = input_hour;
    }
    break;

  default:
    printf("invalid value\n");
    return 1;
  }

  printf("Equivalent 24-hour time: %02d:%02d\n", output_hour, input_minute);

  return 0;
}
