/* C Programming A Modern Approach
 * pp08-13.c
 * 2025-12-02
 *
 * Modify Programming Project 11 from Chapter 7 sot that the program labels
 * its out put:
 *
 * Enter a first and last name: Lloyd Fosdick
 * You entered the name: Fosdick, L.
 *
 * The program will need to store the last name (but not the first name)
 * in an array of characters until it can be printed. You may assume that
 * the last name is no more than 20 characters long.
 */

/* C Programming A Modern Approach pp07-11.c
 * 2025-11-19
 *
 * Write a program that takes a first name and last name entered
 * by the user and displays the last name, a comma, and the
 * first initial, followed by a period:
 *
 * Enter a first and last name: Lloyd Fosdick
 * Fosdick, L.
 *
 * The user's input may contain extra spaces before the first
 * name, between the first and last names, and after the last
 * name.*/

#include <stdio.h>

int main(void) {

  int ch; // read input
  int i;  // Store the initial
  char last_name[20];

  printf("Enter a first and last name: ");

  while ((ch = getchar()) == ' ')
    /* skip initial spaces */;

  i = ch; // Store initial

  while ((ch = getchar()) != ' ') {
    if (ch == '\n')
      break;
  }
  /* skip the rest of first name */;

  while ((ch = getchar()) == ' ')
    /* skip spaces between first and last name */;
  last_name[0] = ch; // put first letter of last name

  do {
    if (ch == '\n' || ch == ' ')
      break;
    for (int n = 0; n < 20; n++)
      last_name[n] = ch;
  } while ((ch = getchar()));

  printf("You entered the name: ");
  for (int m = 0; m < 20; m++)
    printf("%c", last_name[m]);
  printf(", %c.\n", i);

  return 0;
}
