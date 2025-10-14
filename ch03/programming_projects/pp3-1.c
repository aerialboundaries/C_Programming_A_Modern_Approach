/* C Programming A Modern Approach CH03 Programmming Promects 3.1 */

/* Write a program that accepts a date from the user inthe form mm/dd/yyyy and
 * then displays it in the form of yyyymmdd:
 *
 * Enter a date (mm/dd/yyyy): 2/17/2011
 * You entered the date 20110217 */

#include <stdio.h>

int main(void) {
  int m, d, y;
  printf("Enter a date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &m, &d, &y);
  printf("You entered the date %d%.2d%.2d\n", y, m, d);

  return 0;
}
