/* C Programming A Modern Approach
 * ex-14-05.c
 * 2026-03-17
 *
 * Let TOUPPER be the following macro:
 * #define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? (c) - 'a' + 'A' : (c))
 * Let s be a string and let i be an int variable. Show the output produced by
 * each of the following program fragments.
 *
 * (a) strcpy(s, "abcd");
 *      i = 0;
 *      putchar(TOUPPER(s[++i]));
 *
 * (b) strcpy(s, "0123");
 *     i = 0;
 *     putchar(TOUPPER(s[++i]));
 *
 */

#include <stdio.h>
#include <string.h>

#define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? (c) - 'a' + 'A' : (c))

int main(void) {
  int i;
  char s[20];

  strcpy(s, "abcd");
  i = 0;
  putchar(TOUPPER(s[++i])); // (a) D

  strcpy(s, "0123");
  i = 0;
  putchar(TOUPPER(s[++i])); // (b) 2

  return 0;
}
