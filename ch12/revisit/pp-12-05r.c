/* C Programming A Modern Approach
 * pp08-14.c
 * 2025-12-04,
 *
 * Write a program that reverses the words in a sentence:
 *
 * Enter a sentence: you can cage a swallow can't you?
 * Reversal of sentence: you can't swallow a cage can you?
 *
 * Hint: Use a loop to read the characters one by one and store them
 * in a one-dimensional char array. Have the loop stop at a period,
 * question mark, or exclamation pont (the "terminating character"),
 * which is saved in a separated char variable. Then use a second
 * loop to search backward through the array for the beginning of
 * the last word. Print the last word, then search backward for the
 * next-to-last word. Repeaat until the beginning of the array is
 * reached. Finally print the terminating charachter.
 *
 * pp-12-05.c
 * 2026-02-25, 2026-11-06
 * Modify Programming Project 14 from Chapter 8 so that it uses a pointer
 * instead of an integer to keep track of the current position in the array that
 * contains the sentence.
 */

#include <stdio.h>

#define MAX_CHAR 100

void reverse(const char sentence[], char terminate);

int main(void)
{
  char sentence[MAX_CHAR];
  int i = 0, ch, terminate;

  printf("Enter a sentence: ");
  while ((ch = getchar()) != '\n' && ch != EOF) {
    if (ch == '.' || ch == '!' || ch == '?') {
      terminate = ch;
    } else {
      sentence[i++] = ch;
    }
  }

  sentence[i] = '\0';

  reverse(sentence, terminate);

  return 0;
}

void reverse(const char sentence[], char terminate)
{
  const char *p = sentence, *q, *end, *temp;

  while (*p++ != '\0')
    ;

  q = end = p;

  while (p-- >= sentence) {
    if (*p == ' ') {
      for (temp = p + 1; temp <= q; temp++) {
        putchar(*temp);
      }
      if (q == end)
        putchar(' ');
      q = p;
    }
    if (p == sentence) {
      for (temp = p; temp < q; temp++) {
        putchar(*temp);
      }
    }
  }

  putchar(terminate);
}
