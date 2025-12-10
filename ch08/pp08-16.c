/* C Programming A Modern Approach
 * pp08-16.c
 * 2025-12-06
 *
 * Write a program that tests whether two words are anagrams (mutations of
 * the same letters):
 *
 * Enter first word: smartest
 * Enter second word: mattress
 * The words are anagrams.
 *
 * Enterfirst wordk: dumbest
 * Enter second word: stumble
 * The words are not anagrams.
 *
 * Write a loop that reads the first word, character by character, using
 * an array of 26 integers to keep track of how may times each eetter has
 * been seen. (For example, after the word smartest has been reahd, the
 * array should contain the values 1 0 0 0 10 0 0 0 0 0 0 1 0 0 0 0 1 2
 * 2 0 0 0 0 0, refleting the fact that smartest contans one a, one e,
 * one m, one r, two s's and two t's.) Use another loop to read the
 * secon word, except this time decrementing the corresponding array
 * element as each letter is read. Both loops should ignore any characters
 * that aren't letters, and both should treat upper-case letters in the
 * same way as lower-case letters. After the second word has been read,
 * use a third loop to check whether all the elements in athe array are
 * zero. If so,the words are anagrams. Hing: You may wish to use
 * functions from <ctype.h>, such as isalpha and tolower. */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX 26

int main(void) {
  int ch, i, n, ana1[MAX] = {0}, ana2[MAX] = {0};
  bool is_anagram = false;

  printf("Enter first word: ");

  while (((ch = getchar()) != '\n')) {
    if (isalpha(ch)) {
      ch = tolower(ch);
      n = ch - 'a';
      ana1[n]++;
    }
  }

  printf("Enter second word: ");

  while (((ch = getchar()) != '\n')) {
    if (isalpha(ch)) {
      ch = tolower(ch);
      n = ch - 'a';
      ana2[n] = ana1[n];
    }
  }

  for (i = 0; i < MAX; i++) {
    if (ana2[i] == 0) {
      is_anagram = true;
    } else {
      is_anagram = false;
      break;
    }
  }

  printf("ana1: ");
  for (i = 0; i < MAX; i++) {
    printf("%d", ana1[i]);
  }
  printf("\n");

  printf("ana2: ");
  for (i = 0; i < MAX; i++) {
    printf("%d", ana2[i]);
  }
  printf("\n");

  //   for (i = 0; i < MAX; i++) {
  //     if (ana[i] == ana2[i]) {
  //       is_anagram = true;
  //     } else {
  //       is_anagram = false;
  //       break;
  //     }
  //   }

  if (is_anagram)
    printf("The words are anagrams.");
  else
    printf("The words are not anagrams.");

  printf("\n");

  return 0;
}
