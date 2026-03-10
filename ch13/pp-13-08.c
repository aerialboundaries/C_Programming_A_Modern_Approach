/* C Programming A Modern Approach
 * pp-13-08.c
 * 2026-03-09
 *
 * Modify Programming Project 5 from Chater 7 so that it includes the following
 * function: int compute_scrabble_value(const char *word); The function returns
 * the SCRABBLE value of the string pointed to by word.
 *
 *
 * C Programming A Modern Approai p07-05.c
 * 2025-11-17
 *
 * In the SCRABBLE Crosword Game, players form words using small tiles,
 * each containing a letter and a face value. The face value varies
 * from one letter to another, based on the letter's rarity. (Here
 * are the face values: 1: AEILNORSTU, 2: DG, 3: BCMP, 4: FHVWY,
 * 5: K, 8: JX, 10: QZ.) Write a program that computes the value of a word
 * by summing the values of its letters:
 *
 * Enter a word: pitfall
 * Scrabble value: 12
 *
 * Your program should allow any mixture of lower-case and upper-case latters
 * in the word. Hint: Use the toupper library function.
 */

#include <ctype.h>
#include <linux/limits.h>
#include <stdio.h>
#include <string.h>

#define NUM_GROUP 7

int compute_scrabble_value(const char *word);

int main(void)
{

    char ch;
    char word[80];
    int i = 0;

    printf("Enter a word: ");

    while ((ch = getchar()) != '\n' && ch != EOF) {
        word[i++] = toupper(ch);
    }
    word[i] = '\0';

    printf("Scrabble value: %d\n", compute_scrabble_value(word));
    ;

    return 0;
}

int compute_scrabble_value(const char *word)
{
    const char *scrabble[]
        = { "AEILNORSTU", "DG", "BCMP", "FHVWY", "K", "JX", "QZ" };

    const int value[] = { 1, 2, 3, 4, 5, 8, 10 };

    int i, sum = 0;
    size_t j;

    while (*word) {
        for (i = 0; i < NUM_GROUP; i++) {
            for (j = 0; j < strlen(scrabble[i]); j++) {
                if (*word == scrabble[i][j]) {
                    sum += value[i];
                    break;
                }
            }
        }
        word++;
    }
    return sum;
}
