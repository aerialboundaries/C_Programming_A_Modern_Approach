/* C Programming A Moern Approach
 * pp08-11.c
 * 2025-12-01
 *
 * Modify Programming Project 4 from Chapter 7 so that the program labels
 * its output:
 *
 * Enter phone number: 1-800-COL-LECT
 * In numeric form: 1-800-265-5328
 *
 * The program will need to store the phone number (either in its original
 * form or in its numeric form) in an array of characters untilit can be
 * printed. You may assume that the pho number is no more than 15
 * charater long. */

/* C Programming A Modern Approach pp07-04.c
 * Write a program that translates an alphabetic phone number into numeric
 * form:
 *
 * Enter phone number: CALLATT
 * 2255288
 *
 * (Incase you don't have a telephone nearby, here are the letters on the keys:
 * 2=ABC, 3=DEF, 4=GHI, 5=JKL, 6=MNO, 7=PRS, 8=TUV, 9=WXY.) If the original
 * phone number contains nonalphabetic characters (digits or punctuation,
 * for example), leave them unchanged.
 *
 * Enter phone number: 1-800-COL-LECT
 * 1-800-265-5325
 *
 * You may assume that any letters entered by the user are upper case.
 */

#include <ctype.h>
#include <stdio.h>

#define MAX_LENGTH 15

int main(void) {
  int i = 0, n;
  int ch_original, ch_converted;
  char original[MAX_LENGTH];
  char converted[MAX_LENGTH];
  const char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                          'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                          'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y'};
  const char numbers[] = {'2', '2', '2', '3', '3', '3', '4', '4',
                          '4', '5', '5', '5', '6', '6', '6', '7',
                          '7', '7', '8', '8', '8', '9', '9', '9'};

  printf("Enter Phone Number: ");

  while ((ch_original = getchar()) != '\n') {
    original[i] = toupper(ch_original);
    if (original[i] >= 'A' && original[i] <= 'Y') {
      for (n = 0; n < 24; n++) {
        if (original[i] == letters[n]) {
          converted[i] = numbers[n];
          break;
        }
      }
    } else {
      converted[i] = original[i];
    }
    i++;
  }

  printf("In numeric form: ");
  for (i = 0; i < MAX_LENGTH; i++) {
    printf("%c", converted[i]);
  }
  putchar('\n');

  return 0;
}
