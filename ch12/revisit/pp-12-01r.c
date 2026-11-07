/* C Programming A Modern Approach
 * pp-12-01.c
 * 2026-02-18, 2026-11-06
 *
 * (a) Write a program that reads a message, then prints the reversal of the
 * message: Enter a message: Don't get mad, get even. Reversal is: .neve teg
 * ,dam teg t'noD
 *
 * Hint: Read the message one character at a time (using getchar) and store the
 * characters in an array. Stop reading when the array is full or character read
 * is '\n'.
 *
 * (b) Revise the program to use a pointer instead of an integer to keep trak of
 * the current position in the array.
 */

#include <stdio.h>
#include <unistd.h>

#define BUFFER 100

// (a)
void reverse_a(const char msg[])
{
  int j = 0;

  while (msg[j] != '\0') {
    j++;
  }
  if (j > 0)
    j--;

  while (j >= 0) {
    printf("%c", msg[j--]);
  }
  printf("\n");
}

void reverse_b(const char msg[])
{
  const char *p = msg;

  while (*p != '\0') {
    p++;
  }
  if (p > msg) {
    p--;
  }
  while (p >= msg) {
    printf("%c", *p);
    p--;
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  int ch, i = 0;
  char msg[BUFFER];

  printf("Enter a message: ");
  while ((ch = getchar()) != '\n' && ch != EOF) {
    if (i < BUFFER - 1) {
      msg[i++] = ch;
    }
  }
  msg[i] = '\0';

  int use_pointer = 0;
  int opt;
  while ((opt = getopt(argc, argv, "ab")) != -1) {
    switch (opt) {
    case 'a':
      use_pointer = 0;
      break;
    case 'b':
      use_pointer = 1;
      break;
    }
  }

  if (!use_pointer)
    reverse_a(msg);
  else
    reverse_b(msg);

  return 0;
}
