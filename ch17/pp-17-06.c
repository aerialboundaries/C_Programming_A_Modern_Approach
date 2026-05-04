/* C Programming A Modern Approach
 * pp-17-06.c
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
 *
 * Modify Project 5 so that it uses qsort to sort the array of pointers
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
int compare_words(const void *p, const void *q);

/* main */
int main(void) {
  char *words[MAX_WORDS];      // array of poiner
  char temp_str[WORD_LEN + 1]; // temporary buffer
  int num_words = 0;
  int i;

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
    // copy str into temporary memory
    strcpy(words[num_words], temp_str);

    num_words++;
  }

  // sort by qsort
  // 1st argument: pointer to array
  // 2nd argument: number of elements
  // 3rd arugument: sizeof element (char*)
  // 4th argument: compare function

  qsort(words, num_words, sizeof(char *), compare_words);

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

  // skip the forwarding sace
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

// for qsort
int compare_words(const void *p, const void *q) {
  // cast to char** and derererene and pass to strcmp
  return strcmp(*(char **)p, *(char **)q);
}
