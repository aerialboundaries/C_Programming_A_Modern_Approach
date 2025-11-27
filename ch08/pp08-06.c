/* C Programming A Modern Approach
 * pp08-06.c
 * 2025-11-27
 *
 * The prototypical Internet newbie is a fellow named BIFF, who has a
 * unique way of writing messages. Hiere's a typical BIFF communique.
 *
 * H3Y DUD3, C 15 RILLY C00L!!!!!!!!!!
 *
 * Write a "BIFF filter" that reads a message entered by the user and
 * translates it into BIFF - spleak:
 *
 * Enter message: Hey dude, C is rilly cool
 * In BIFF-speak: H3Y DUD3, C 15 RILLY C00L!!!!!!!!!!
 *
 * Your program should convert the message to upper-case letters,
 * substitute digits for certain letters (A->4, B->8, E->3, I->1, O->0,
 * S->5), and then append 10 or so exclamation marks. Hint: Store the
 * original message in an array of characters, then go back through
 * the array, translating and printing charachters one by one. */

#include <ctype.h>
#include <stdio.h>

#define NUM_CHAR 100
#define NUM_ARRAY ((int)sizeof(a) / sizeof(a[0]))

int main(void) {
  int i = 0;
  char a[NUM_CHAR] = {0}, c;

  printf("Enter message: ");
  while ((c = getchar()) != '\n' && i < NUM_CHAR) {
    a[i] = c;
    i++;
  }
  a[i] = '\0'; // end of string

  for (i = 0; a[i] != '\0'; i++) {
    a[i] = toupper(a[i]);

    switch (a[i]) {
    case 'A':
      a[i] = '4';
      printf("%c", a[i]);
      break;
    case 'B':
      a[i] = '8';
      printf("%c", a[i]);
      break;
    case 'E':
      a[i] = '3';
      printf("%c", a[i]);
      break;
    case 'I':
      a[i] = '1';
      printf("%c", a[i]);
      break;
    case 'O':
      a[i] = '0';
      printf("%c", a[i]);
      break;
    case 'S':
      a[i] = '5';
      printf("%c", a[i]);
      break;
    default:
      printf("%c", a[i]);
      break;
    }
  }

  printf("!!!!!!!!!!\n");

  return 0;
}
