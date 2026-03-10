/* C Programming A Modern Approach
 * pp-13-11.c
 * 2026-03-10
 *
 * Modify Programming Project 14 from Chapter 8 so that it stores the words in a
 * two- dimensional char array as it reads the sentence, with each row of the
 * array storing a single word. Assume that the sentence contains no more than
 * 30 words and no word is more than 20 characters long. Be sure to store a null
 * character at the end of echa word so that it can be treated as a string.
 */

/* C Programming A Modern Approach
 * pp08-14.c
 * 2025-12-04
 *
 * Write a program that reverses the words in a sentence:
 *
 * Enter a sentence: you can cage a swallow can't you?
 * Reversal of sentence: you can't swallow a cage can you?
 *
 * Hint: Use a loop to read the characters one by one and store thenm
 * in a one-dimensional char array. Have the loop stpo at a period,
 * question mark, or exclamation pont (the "terminating character"),
 * which is saved in a separated char variable. Then use a second
 * loop to search backward through the array for the beginning of
 * the last word. Print the last word, then search backward for the
 * next-to-last word. Repeaat until the beginning of the array is
 * reached. Finally print the terminating charachter.
 */

#include <ctype.h>
#include <stdio.h>

#define MAX_WORDS 30
#define MAX_LENGTH 20

int main(void)
{
    int i = 0, j = 0;
    int ch;
    char terminating_ch = 0;
    char sentence[MAX_WORDS][MAX_LENGTH + 1] = { 0 }; // ヌル文字のために +1

    printf("Enter a sentence: ");

    // 【修正 1: 終端文字で入力を停止】
    while ((ch = getchar()) != EOF) {
        if (ch == '.' || ch == '?' || ch == '!') {
            terminating_ch = ch;
            break;
        }
        if (!isspace(ch)) {
            sentence[i][j++] = ch;
        } else {
            sentence[i][j] = '\0';
            i++;
            j = 0;
        }
    }

    if (terminating_ch == 0) {
        // ... エラー処理 ...
        return 1;
    }

    printf("Reversal of sentence: ");

    for (i = MAX_WORDS; i >= 0; i--) {
        if (sentence[i][0] != '\0') {
            printf("%s", sentence[i]);
            if (i > 0)
                printf(" ");
        }
    }
    // 【修正 3: 終端文字を出力】
    printf("%c\n", terminating_ch);

    return 0;
}
