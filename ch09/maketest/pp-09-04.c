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
 * an array of 26 integers to keep track of how may times each letter has
 * been seen. (For example, after the word smartest has been read, the
 * array should contain the values 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 1 2
 * 2 0 0 0 0 0, refleting the fact that smartest contans one a, one e,
 * one m, one r, two s's and two t's.) Use another loop to read the
 * secon word, except this time decrementing the corresponding array
 * element as each letter is read. Both loops should ignore any characters
 * that aren't letters, and both should treat upper-case letters in the
 * same way as lower-case letters. After the second word has been read,
 * use a third loop to check whether all the elements in the array are
 * zero. If so,the words are anagrams. Hint: You may wish to use
 * functions from <ctype.h>, such as isalpha and tolower. */

/* pp-09-04
 * 2026-01-27
 *
 * Modify Programming Project 16 from Chapter 8 so that it includes the
 * following functions:
 *
 * void read_word(int counts[26]);
 * bool equal_array(int counts1[26], int counts2[26]);
 *
 * main will call read_word twice, once for each of the two words entered
 * by the user. As it reads a word, read_word will use the letters in the
 * word to update the counts array, as described in the original project.
 * (main will declare two arrays, one for each word. These arrays are used
 * to track how many times each letter occures in the words.) main will then
 * call equal_array, passing it the two arrays.equal_array will return true
 * if the elements inthe two arrays are identical (indicating that the words
 * are anagrams) and false otherwise. */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

int main(void) {
  int counts1[26] = {0}, counts2[26] = {0};

  printf("Enter first word: ");
  read_word(counts1);

  printf("Enter second word: ");
  read_word(counts2);

  if (equal_array(counts1, counts2))
    printf("The words are anagram.\n");
  else
    printf("The words are not anagram.\n");

  return 0;
}

void read_word(int counts[26]) {
  int ch;
  while (((ch = getchar()) != '\n')) {
    if (isalpha(ch)) {
      ch = tolower(ch);
      ch = ch - 'a';
      counts[ch]++;
    }
  }
}

bool equal_array(int counts1[26], int counts2[26]) {
  for (int i = 0; i < 26; i++)
    if (counts1[i] != counts2[i])
      return false;

  return true;
}
