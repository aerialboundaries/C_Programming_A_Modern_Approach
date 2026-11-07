/* C Programming A Modern Approach
 * pp-12-02.c -a
 * 2026-02-22, 2026-11-06
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

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER 100
// #define DEBUG

// (a) int subscription
bool is_palindrome_a(const char msg[]);

// (b) pointers
bool is_palindrome_b(const char msg[]);

int main(int argc, char *argv[])
{
  char msg[BUFFER];
  char filtered[BUFFER];
  int ch, i = 0;

  printf("Enter a message: ");

  if (fgets(msg, sizeof(msg), stdin) != NULL) {
    for (int k = 0; msg[k] != '\0'; k++) {
      ch = msg[k];
      if (isalpha(ch)) {
        if (i < BUFFER - 1) {
          filtered[i++] = tolower(ch);
        }
      }
    }
    filtered[i] = '\0';
  }

  int opt;
  bool use_pointer = false;

  while ((opt = getopt(argc, argv, ":ab")) != -1) {
    switch (opt) {
    case 'a':
      use_pointer = false;
      break;
    case 'b':
      use_pointer = true;
      break;
    }
  }

  if (!use_pointer) {
    printf("option (a) %s\n",
           is_palindrome_a(filtered) ? "Palindrome" : "Not a palindrome");

  } else {
    printf("option (b) %s\n",
           is_palindrome_b(filtered) ? "Palindrome" : "Not a palindrome");
  }

  return 0;
}

bool is_palindrome_a(const char msg[])
{
  int i = 0, j = 0;
  while (msg[j] != '\0')
    j++;

  if (j > 0)
    j--;

  while (i < j) {
    if (msg[i] != msg[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

bool is_palindrome_b(const char msg[])
{
  const char *p = msg, *q = msg;

  while (*q != '\0') {
    q++;
  }

  if (q > p)
    q--;

  while (p < q) {
    if (*p != *q)
      return false;
    p++;
    q--;
  }

  return true;
}
