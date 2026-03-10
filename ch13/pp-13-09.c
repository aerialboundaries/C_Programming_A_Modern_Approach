/* C Programming A Modern Approach
 * pp-13-09.c
 * 2026-03-10
 *
 * Modify Programming Porject 10 from chapter 7 so that it includes the
 * following function:
 *
 * int compute_vowel_count(const char *sentence);
 *
 * The function returns the number of vowels in the string pointed to by the
 * sentence parameter.
 */

/* C Programming A Modern Approach pp07-10.c
 * 2025-11-19
 *
 * Write a program that counts the number of vowels (a, e, i, o and u)
 * in a sentence:
 *
 * Enter a sentence: And that's the way it is.
 * Your sentence contains 6 vowels.
 */

#include <ctype.h>
#include <stdio.h>

int compute_vowel_count(const char *sentence);

int main(void)
{

    int ch, i = 0;
    char sentence[80];

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n') {
        sentence[i++] = toupper(ch);
    }
    sentence[i] = '\0';

    printf(
        "Your sentence contains %d vowels.\n", compute_vowel_count(sentence));

    return 0;
}

int compute_vowel_count(const char *sentence)
{
    int i, sum = 0;
    const char vowels[] = { 'A', 'E', 'I', 'O', 'U' };
    while (*sentence) {
        for (i = 0; i < 5; i++) {
            if (*sentence == vowels[i]) {
                sum++;
                break;
            }
        }
        sentence++;
    }

    return sum;
}
