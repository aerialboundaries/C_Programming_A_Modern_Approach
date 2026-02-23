/* C Programming A Modern Approach
 * pp-12-02.c -a
 * 2026-02-22
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

// My Anwer for (a)

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 80

int main(void) {
  int ch, i = 0, j = 0, a[N];
  bool palindrome = true;

  printf("Enter a message: ");

  while ((ch = getchar()) != '\n' && ch != EOF) {

    if (isalpha(ch))
      a[i++] = tolower(ch);

    if (i > N) {
      printf("Too much character\n");
      exit(EXIT_FAILURE);
    }
  }

  for (--i; i >= 0; i--) {
    if (a[i] != a[j++]) {
      palindrome = false;
    }
  }

  if (palindrome == true)
    printf("Palindrome\n");
  else
    printf("Not a palindrme\n");

  return 0;
}
