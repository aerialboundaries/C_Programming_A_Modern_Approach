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
 * in a one-dimensional char array. Have the loop stop at a period,
 * question mark, or exclamation pont (the "terminating character"),
 * which is saved in a separated char variable. Then use a second
 * loop to search backward through the array for the beginning of
 * the last word. Print the last word, then search backward for the
 * next-to-last word. Repeaat until the beginning of the array is
 * reached. Finally print the terminating charachter.
 *
 * pp-12-05.c
 * 2026-02-25
 * Modify Programming Project 14 from Chapter 8 so that it uses a pointer
 * instead of an integer to keep track of the current position in the array that
 * contains the sentence.
 */

#include <stdio.h>

#define MAX_LENGTH 100

int main(void)
{
    int ch;
    char terminating_ch = 0;
    char sentence[MAX_LENGTH];
    char *p = sentence;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != EOF && p < (sentence + MAX_LENGTH)) {
        if (ch == '.' || ch == '?' || ch == '!') {
            terminating_ch = (char)ch;
            break;
        } else {
            *p = (char)ch;
            p++;
        }
    }

    printf("Reversal of sentence: ");

    // 【修正 2: 逆走ロジックの再構築】
    char *current_pos = p - 1; // 最後の文字のインデックスから開始
    char *word_start;
    char *word_end;

    while (current_pos >= sentence) {

        // 1. **空白文字をスキップ**し、単語の末尾 (word_end) を見つける
        while (current_pos >= sentence && *current_pos == ' ') {
            current_pos--;
        }
        word_end = current_pos;

        if (current_pos < sentence) {
            break; // 配列の先頭に達したら終了
        }

        // 2. **単語の開始** (word_start) を見つける
        while (current_pos >= sentence && *current_pos != ' ') {
            current_pos--;
        }
        word_start = current_pos + 1; // 空白の次が単語の始まり

        // 3. **単語を順方向に出力**
        for (char *q = word_start; q <= word_end; q++) {
            printf("%c", *q);
        }

        // 単語の間に空白を出力

        if (current_pos >= sentence) {
            printf(" ");
        }
    }

    // 【修正 3: 終端文字を出力】
    printf("%c\n", terminating_ch);

    return 0;
}
