/* C Programming A Modern Approach
 * pp-12-02-b.c
 * 2026-02-23
 *
 * (a) Write a program that reads a message, then checks whether it's a
 * palindrome (the letters in the message are the same from left to right as
 * from right to left):
 *
 * Enter a message: He lived as a devil, eh?
 * Palindrome
 *
 * Enter a message: Madam, I am Adam.
 * Not a palindrome
 *
 * Ignore all characters that aren't letters. Use integer variables to keep
 * track of positions in the  array.
 *
 * (b) Revise the program to use pointers instead of integers to keep track of
 * positions in the array.
 */

// My Anwer for (b)

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define N 80

int main(void) {
  int ch, a[N], *p = a, *q = a;
  bool palindrome = true;

  printf("Enter a message: ");

  while ((ch = getchar()) != '\n' && ch != EOF) {
    if (isalpha(ch)) {
      if (p < a + N) {
        *p++ = tolower(ch);
      }
    }
  }

  p--;

  while (q < p) {
    if (*q != *p) {
      palindrome = false;
      break;
    }
    q++;
    p--;
  }

  if (palindrome)
    printf("Palindrome\n");
  else
    printf("Not a palindrome\n");

  return 0;
}
