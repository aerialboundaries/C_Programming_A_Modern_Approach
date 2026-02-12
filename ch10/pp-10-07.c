/* C Programming A Modern Approach
 * pp-10-07.c
 * 2026-02-11
 *
 * Write a program that prompts the user for a number and then displays
 * the number, using characters to simulate the effect of seven-segment
 * display:
 *
 * Enter a number: 491-9014
 *
 *      _      _   _
 * |_| |_| |  |_| | | |  |_|
 *   |  _| |   _| |_| |    |
 *
 * Characters other than digits should be ignored. Write the program so
 * that the maximum number of digits is controlled by a macro named
 * MAX_DIGITS, which has the value 10. If the number contains more than
 * this number of digits, the extra digits are ignored. Hints: Use
 * two external arrays. One is the segments array (see Exercise 6 in
 * Chapter 8), which stores data representing the correspondence between
 * digits and segments. The other array, digits, will be an array of
 * characters with 4 rows (since each segumented digit is four characters
 * high) and MAX_DIGITS * 4 columns (digits are three characters wide,
 * but a space is needed between digits for readability). Write your
 * program as four functions: main, clear_digits_array, process_digit,
 * and print_digits_array. Here are the prototypes for the latter three
 * functions:
 *
 * void clear_digits_array(void);
 * void process_digit(int digit, int position);
 * void print_digits_array(void);
 *
 * clear_digits_array will store blank characters into all elements of
 * the digits array. process_digit will store the seven-segment representation
 * of digit into a specified position in the digits array (positions range
 * from 0 to MAX_DIGITS - 1). print_digits_array will display the rows of
 * the digits array, each on a single line, producing output such as that
 * shown in the example.
 */

#include <stdio.h>

#define MAX_DIGITS 10
#define WIDTH 4
#define IS_DIGIT(ch) (ch >= '0' && ch <= '9')

/* Proto Type */
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

/* external variables */
const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0},
                             {1, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 0, 0, 1},
                             {0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1},
                             {1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};

char digits[4][MAX_DIGITS * WIDTH];

int main(void) {
  int digit_count = 0, digit;

  clear_digits_array();

  printf("Enter a number: ");

  while ((digit = getchar()) != '\n' && digit_count < MAX_DIGITS) {
    if (IS_DIGIT(digit)) {
      digit -= '0';
      process_digit(digit, digit_count * WIDTH);
      digit_count++;
    }
  }

  print_digits_array();

  return 0;
}

void clear_digits_array(void) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < MAX_DIGITS * WIDTH; j++) {
      digits[i][j] = ' ';
    }
  }
}

void process_digit(int digit, int position) {
  /* Upper row */
  if (segments[digit][0] == 1)
    digits[0][position + 1] = '_';

  /* Middle row */
  if (segments[digit][5] == 1)
    digits[1][position + 0] = '|';
  if (segments[digit][6] == 1)
    digits[1][position + 1] = '_';
  if (segments[digit][1] == 1)
    digits[1][position + 2] = '|';

  /* Lower row */
  if (segments[digit][4] == 1)
    digits[2][position + 0] = '|';
  if (segments[digit][3] == 1)
    digits[2][position + 1] = '_';
  if (segments[digit][2] == 1)
    digits[2][position + 2] = '|';
}

void print_digits_array(void) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < MAX_DIGITS * WIDTH; j++) {
      printf("%c", digits[i][j]);
    }
    printf("\n");
  }
}
