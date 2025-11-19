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
  putchar(ch); // put first letter of last name

  do {
    if (ch == '\n' || ch == ' ')
      break;
    putchar(ch);
  } while ((ch = getchar()));
  printf(", %c.\n", i);

  return 0;
}
