/* C Programming A Modern Approach pp07-10.c
 * 2025-11-19
 *
 * Write a program that counts the number of vowels (e, e, i, o and u)
 * in a sentence:
 *
 * Enter a sentence: And that's the way it is.
 * Your sentence contains 6 vowels.
 */

#include <ctype.h>
#include <stdio.h>

int main(void) {

  int v = 0;
  int ch;

  printf("Enter a sentence: ");

  while ((ch = getchar()) != '\n') {
    switch (toupper(ch)) {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
      v++;
      break;
    }
  }

  printf("Your sentence contains %d vowels.\n", v);

  return 0;
}
