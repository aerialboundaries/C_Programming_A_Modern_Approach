/* C Programming A Modern Approach
 * pp08-14.c
 * 2025-12-04
 *
 * Write a program that reverses the words in a sentence:
 *
 * Enter a sentence: you can cage a swallow can't you?
 * Reversal of sentence: you can't swallow a cage can you?
 *
 * Hint: Use a loop to read the characters one by one and store thenm
 * in a one-dimensional char array. Have the loop stpo at a period,
 * question mark, or exclamation pont (the "terminating character"),
 * which is saved in a separated char variable. Then use a second
 * loop to search backward through the array for the beginning of
 * the last word. Print the last word, then search backward for the
 * next-to-last word. Repeaat until the beginning of the array is
 * reached. Finally print the terminating charachter.
 */

#include <stdio.h>

#define MAX_LENGTH 100

int main(void) {
  int n = 0, word_len = 0, end_word, start_word;
  char ch;
  char terminating_ch;
  char sentence[MAX_LENGTH] = {0}; // Including '\0'

  printf("Enter a sentence: ");

  while ((ch = getchar()) != '\n') {
    sentence[n] = ch;
    n++;
  }

  for (n = MAX_LENGTH - 1; n >= 0; n--) {
    switch (sentence[n]) {
    case '.':
      terminating_ch = '.';
      end_word = n - 1;
      break;
    case '?':
      terminating_ch = '?';
      end_word = n - 1;
      break;
    case '!':
      terminating_ch = '!';
      end_word = n - 1;
      break;
    }
  }
  printf("end_word: %d\n", end_word);
  printf("Reversed : ");

  for (n = end_word; n >= 0; n--) {
    if (n == 0 || sentence[n] != ' ') {
      word_len++;
    }
    if (sentence[n] == ' ') {
      for (int m = n + 1; m <= n + word_len; m++) {
        printf("%c", sentence[m]);
      }
      printf(" ");
      word_len = 0;
    }
    if (n == 0) {
      for (int m = n; m <= n + word_len - 1; m++) {
        printf("%c", sentence[m]);
      }
      word_len = 0;
    }
  }

  printf("%c\n", terminating_ch);

  return 0;
}
