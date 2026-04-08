/* C Programming A Modern Approach pp5-10.c
 *
 * Uisng the switch statement, write a progra that converts t numerical
 * grade into a letter grade:
 *
 * Enter numerical grade: 84
 * Letter grade: B
 *
 * Use the following grading scale: A = 90 - 100, B = 80 - 89,
 * C = 70 - 79, D = 60 - 69, F = 0 - 59.
 * Print an error message if the grade is larger than 100 or less than 0.
 * Hint: Break the grade into two digits, then use a switch statement to test
 * the ten's digit.
 */

#include <stdio.h>

int main(void) {

  int num_grade;

  printf("Enter numerical grade: ");
  if (scanf("%d", &num_grade) != 1 || num_grade < 0 || num_grade > 100) {
    printf("Illegal grade\n");
    return 1;
  }

  printf("Letter grade: ");

  switch (num_grade / 10) {
  case 10:
  case 9:
    printf("A\n");
    break;
  case 8:
    printf("B\n");
    break;
  case 7:
    printf("C\n");
    break;
  case 6:
    printf("D\n");
    break;
  default:
    printf("F\n");
    break;
  }

  return 0;
}
