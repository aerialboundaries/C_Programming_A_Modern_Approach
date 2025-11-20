/* C Programming A Modern Approach pp07-13.c
 * 2025-11-19
 *
 * Write a program that calculates the average word length for a sentence:
 *
 * Enter a sentence: It was deja vu all over again.
 * Average word length: 3.4
 *
 * For simplicity, your program should consider a punctuation mark to be
 * part of the word to which it is atached. Display the average word
 * length to one decimal place. */

#include <stdio.h>

int main(void) {

  float sum_words = 1.0f; // last word dows not have space, so add 1.
  float length = 0.0f;
  char ch;

  printf("Enter a sentence: ");

  while ((ch = getchar()) != '\n') {
    if (ch != ' ') {
      length++;
    } else {
      sum_words++;
    }
  }
  printf("length: %f\n", length);
  printf("sum_words: %f\n", sum_words);
  printf("Average word length: %4.1f", length / sum_words);

  return 0;
}
