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

// #include <stdio.h>
//
// int main(void) {
//
//   int ch; // read input
//   int i;  // Store the initial
//   char last_name[20] = {0};
//
//   printf("Enter a first and last name: ");
//
//   while ((ch = getchar()) == ' ')
//     /* skip initial spaces */;
//
//   i = ch; // Store initial
//
//   while ((ch = getchar()) != ' ') {
//     if (ch == '\n')
//       break;
//   }
//   /* skip the rest of first name */;
//
//   while ((ch = getchar()) == ' ')
//     /* skip spaces between first and last name */;
//   last_name[0] = ch; // put first letter of last name
//
//   for (int n = 1; n < 20; n++) {
//     if ((ch = getchar()) != ' ' || (ch = getchar()) != '\n') {
//       last_name[n] = ch;
//       if (last_name[n] == '\n')
//         break;
//     }
//   }
//
//   printf("You entered the name: ");
//   for (int m = 0; m < 20; m++)
//     if (last_name[m] != '\n')
//       printf("%c", last_name[m]);
//   printf(", %c.\n", i);
//
//   return 0;
// }

#include <ctype.h> // for isspace
#include <stdio.h>

#define LAST_NAME_MAX 20

int main(void) {
  int ch;
  char first_initial = 0;            // for initial of name
  char last_name[LAST_NAME_MAX + 1]; // to put '\0', +1
  int last_name_len = 0;             // current last name length

  printf("Enter a first and last name: ");

  while ((ch = getchar()) != EOF && isspace(ch))
    /* skip first spaces */;

  if (ch != EOF && ch != '\n') {
    first_initial = ch;
  } else {
    printf("\nError: No name entered.\n");
    return 1;
  }

  // skip the rest of first name
  while ((ch = getchar()) != EOF && ch != '\n' && isspace(ch))
    ;

  // skip space between name and last name
  while (ch != EOF && ch != '\n' && !isspace(ch)) {
    ch = getchar();
  }

  // read last name
  if (ch != EOF && ch != '\n') {
    last_name[last_name_len] = ch;
    last_name_len++;

    while ((ch = getchar()) != EOF && ch != '\n' && !isspace(ch) &&
           last_name_len < LAST_NAME_MAX) {
      last_name[last_name_len] = ch;
      last_name_len++;
    }
  }

  // set '\0' to the last item of last_name
  last_name[last_name_len] = '\0';

  // skip extra letters after last name
  while (ch != EOF && ch != '\n') {
    ch = getchar();
  }

  printf("You entered the name: %s, %c.\n", last_name, first_initial);

  return 0;
}
