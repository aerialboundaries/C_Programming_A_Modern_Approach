/* C Programming A Modern Approach
 * pp-13-01.c
 * 2026-03-06
 *
 * Write a program that finds the "smallest" and "largest" in a series of words.
 * After the user enters the wrds, the program will determine which words would
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
 * "smaller,", use strcpy to save it in smallest_word. Do a similarcomparison
 * with largest_word. Use strlen to determine whtn the user has entered a
 * four-letter word.
 */

#include <stdio.h>
#include <string.h>

#define N 20

int main(void)
{
    char smallest_word[N + 1], largest_word[N + 1], current_word[N + 1];
    int ch;
    printf("Enter word: ");

    int i = 0;

    while (((ch = getchar()) != '\n' && ch != EOF)) {
        current_word[i++] = ch;
    }
    current_word[i] = '\0';
    strcpy(smallest_word, current_word);
    strcpy(largest_word, current_word);

    if (strlen(current_word) == 4) {
        printf("Smallest word: %s\n", smallest_word);
        printf("Largest word: %s\n", largest_word);

        return 0;
    }

    for (;;) {

        printf("Enter word: ");

        int i = 0;

        while (((ch = getchar()) != '\n' && ch != EOF)) {
            current_word[i++] = ch;
        }
        current_word[i] = '\0';

        // printf("%s\n", current_word);

        if (strlen(current_word) == 4)
            break;

        if (strcmp(current_word, smallest_word) <= 0)
            strcpy(smallest_word, current_word);

        if (strcmp(current_word, largest_word) >= 0)
            strcpy(largest_word, current_word);
    }

    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);

    return 0;
}
