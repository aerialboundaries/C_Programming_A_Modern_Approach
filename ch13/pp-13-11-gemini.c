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
/* C Programming A Modern Approach
 * pp-13-11.c
 */
#include <ctype.h>
#include <stdbool.h> // bool型を使うために追加
#include <stdio.h>

double compute_average_word_length(const char *sentence);

int main(void)
{
    char sentence[80];

    int ch, i = 0;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (i < 79) {
            sentence[i++] = (char)ch;
        }
    }
    sentence[i] = '\0';

    printf(
        "Average word length: %.1f\n", compute_average_word_length(sentence));

    return 0;
}

double compute_average_word_length(const char *sentence)

{
    double total_length = 0;
    int word_count = 0;

    bool in_word = false; // 今、単語の中にいるかどうかのフラグ
    const char *p = sentence;

    while (*p) {
        if (isspace(*p)) {

            // 空白を見つけたら「単語の外」に出た印
            in_word = false;
        } else {
            // 文字を見つけたとき
            total_length++;
            if (!in_word) {

                // まだ単語の中にいない状態から文字を見つけたなら、
                // それは新しい「単語の始まり」です
                word_count++;
                in_word = true;
            }
        }

        p++;
    }

    // 0除算を防ぐための安全装置
    if (word_count == 0)
        return 0.0;

    return total_length / word_count;
}
