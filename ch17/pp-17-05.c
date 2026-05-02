/* C Programming A Modern Approach
 * pp-17-05.c
 * 2026-05-01
 *
 * Write a program that sorts a series of words entered by the user:
 * Enter word: foo
 * Enter word: bar
 * Enter word: baz
 * Enter word: quux
 * Enter word:
 *
 * In sorted order: bar baz foo quux
 * Assume that each word is no more than 20 characters long. Stop reading when
 * the user enters an empty word (i.e., presses Enter without entering a word).
 * Store each word in a dynamically allocated string, using an array of pointers
 * to keep track of the strings, as in the remind2.c program (Section 17.2).
 * After all words have been read, sort the array (using any sorting technique)
 * and then use a loop to print the words in sorted order. Hint: Use the
 * read_line function to read each word, as in remind2.c.
 */

/* headers */
#include <ctype.h> // for readline function
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* constatnts */
#define MAX_WORDS 50
#define WORD_LEN 20

/* function prototypes */
int read_line(char str[], int n);

/* main */
int main(void) {
  char *words[MAX_WORDS];      // array of poiner
  char temp_str[WORD_LEN + 1]; // temporary buffer
  int num_words = 0;
  int i, j;

  for (;;) {
    if (num_words >= MAX_WORDS) {
      printf("--- No more space ---\n");
      break;
    }

    printf("Enter word: ");

    // read into temp buffer
    int len = read_line(temp_str, WORD_LEN);

    // exit if empty line
    if (len == 0)
      break;

    // malloc read char + 1 into malloc
    words[num_words] = malloc(len + 1);
    if (words[num_words] == NULL) {
      printf("Error: malloc failed\n");
      exit(EXIT_FAILURE);
    }
    // copy strin to temporary memory
    strcpy(words[num_words], temp_str);

    num_words++;
  }

  // sort by selection sort
  for (i = 0; i < num_words - 1; i++) {
    for (j = i + 1; j < num_words; j++) {
      // compare by strcmp
      if (strcmp(words[i], words[j]) > 0) {
        char *temp = words[i];
        words[i] = words[j];
        words[j] = temp;
      }
    }
  }

  /* display result */
  printf("\nIn sorted order:");
  for (i = 0; i < num_words; i++) {
    printf(" %s", words[i]);
    // Do not forget free
    free(words[i]);
  }
  printf("\n");

  return 0;
}

/* function imlementation */
int read_line(char str[], int n) {
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  while (ch != '\n' && ch != EOF) {
    if (i < n)
      str[i++] = ch;
    ch = getchar();
  }
  str[i] = '\0';
  return i;
}
