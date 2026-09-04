/*
Write a program that copies a text file from standard input to standard output, replacing each
control character (other than \n) by a question mark.
*/

#include <ctype.h>
#include <stdio.h>

int main(void) {
  int ch;

  while ((ch = getchar()) != EOF) {
    if (!iscntrl((unsigned char)ch) || ch == '\n') {
      putchar(ch);
    } else {
      putchar('?');
    }
  }

  return 0;
}
