/* C Programming A Modern Approach
 * ex-13-04-a.c
 * 2026-02-26
 *
 * Modify the read_line function in each of the follwoing ways:
 *
 * (a) Have it skip white space before beginnning to store input charcters.
 * (b) Have it stop reading the first white-space character. Hint: To determine
 * whether or not a character is white space, call the isspace function. (c)
 * Have it stop reading at the first new-line character, then store the new-line
 * character in the strng. (d) Have it leave behind characters that it doesn't
 * have room to sotore.
 */

/* My Answer (a) */
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 80

char *read_line(char a[], int n);

int main(int argc, char *argv[]) {
  char a[MAX_CHAR + 1];

  printf("Enter a sentence: ");

  printf("%s\n", read_line(a, MAX_CHAR));

  return 0;
}

char *read_line(char a[], int n) {
  char ch, *p = a;
  while ((ch = getchar()) != '\n' && ch != EOF) {
    *a++ = ch;
  }
  return a;
}
