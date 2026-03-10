/* C Programming A Modern Approach
 * pp-13-11.c
 * 2026-03-10
 *
 * Modify Programming Project 13 from Chapter 7 so that it includes the
 * following function:
 *
 * double compute_average_word_length(const char *sentence);
 *
 * The function returns the average length of the words in the string pointed to
 * by sentence.
 */

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

#include <ctype.h>
#include <stdio.h>

double compute_average_word_length(const char *sentence);

int main(void)
{

    char ch;
    char sentence[80];
    int i = 0;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n' && ch != EOF) {
        sentence[i++] = ch;
    }
    sentence[i] = '\0';

    printf("Average word length: %4.1f", compute_average_word_length(sentence));

    return 0;
}

double compute_average_word_length(const char *sentence)
{
    float sum_words = 1.0f; // last word dows not have space, so add 1.
    float length = 0.0f;
    const char *p = sentence;

    while (*p) {
        if (isspace(*p)) {
            sum_words++;
        } else {
            length++;
        }
        p++;
    }
    printf("words %f\n", sum_words);
    printf("length %f\n", length);
    return length / sum_words;
}
