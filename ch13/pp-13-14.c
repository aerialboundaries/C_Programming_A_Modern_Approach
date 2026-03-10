/* C Programming A Modern Approach
 * pp-13-14.c
 * 2026-03-10
 *
 * Modify Programming Project 16 from Chapter 8 so that it includes the
 * following function: bool are_anagrams(const char *word1, const char *word2);
 * The function return true if the strings pointed to by word 1 and word2 are
 * anagrams.
 */

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
#include <string.h>

#define MAX 26
bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
    int ch, n;
    char ana1[MAX] = { 0 }, ana2[MAX] = { 0 };

    printf("Enter first word: ");
    n = 0;

    while (((ch = getchar()) != '\n')) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            ana1[n++] = ch;
        }
    }

    printf("Enter second word: ");
    n = 0;

    while (((ch = getchar()) != '\n')) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            ana1[n++] = ch;
        }
    }

    if (are_anagrams(ana1, ana2))
        printf("The words are anagrams.");
    else
        printf("The words are not anagrams.");

    printf("\n");

    return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
    bool anagram = true;
    char word3[strlen(word2)];
    strcpy(word3, word2);

    const char *p = word1;
    char *q = word3;

    if (strlen(p) == strlen(q)) {
        while (*p) {
            while (*q) {
                if (*p == *q) {
                    *q -= *p;
                    anagram = true;
                } else {
                    anagram = false;
                    q++;
                }
                p++;
            }
        }
    } else {
        anagram = false;
    }
    return anagram;
}
