/* C Programming A Modern Approach
 * pp-13-01.c
 * 2026-03-06 2026-11-09
 *
 * Write a program that finds the "smallest" and "largest" in a series of words.
 * After the user enters the words, the program will determine which words would
 * come first and last if the words were listed in dictionary order. The program
 * must stop accepting input when the user enters a four-letter word. Assume
 * that no word is more than 20 letters long. An interactive session with the
 * program might look like this:
 *
 * Enter word: dog
 * Enter word: zebra
 * Enter word: rabbit
 * Enter word: catfish
 * Enter word: walrus
 * Enter word: cat
 * Enter word: fish
 *
 * Smallest word: cat
 * Largest word: zebra
 *
 * Hint: Use two strings named smallest_word and largest_word to keep track of
 * the "smallest" and "largest" words entered so far. Each time the user enters
 * a new word, use strcmp to compare it with smallest_word; if the new word is
 * "smaller,", use strcpy to save it in smallest_word. Do a similar comparison
 * with largest_word. Use strlen to determine when the user has entered a
 * four-letter word.
 */

#include <stdio.h>
#include <string.h>

#define MAX_CHAR 20

int main(void)
{
  char entered_word[MAX_CHAR + 1];
  char smallest_word[MAX_CHAR + 1];
  char largest_word[MAX_CHAR + 1];
  int ch, i, count = 0;

  for (;;) {
    printf("Enter word: ");

    if (fgets(entered_word, sizeof(entered_word), stdin) == NULL) {
      break;
    }
    entered_word[strcspn(entered_word, "\n")] = '\0';

    if (strlen(entered_word) == 4) {
      break;
    }

    if (strlen(entered_word) == 0) {
      continue;
    }

    if (count == 0) {
      strcpy(smallest_word, entered_word);
      strcpy(largest_word, entered_word);
    } else {
      if (strcmp(entered_word, smallest_word) < 0)
        strcpy(smallest_word, entered_word);
      if (strcmp(entered_word, largest_word) > 0)
        strcpy(largest_word, entered_word);
    }

    count++;
  }

  printf("Smallest word: %s\n", smallest_word);
  printf("largest word: %s\n", largest_word);

  return 0;
}
