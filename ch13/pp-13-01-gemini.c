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
/* C Programming A Modern Approach
 * pp-13-01.c
 * 2026-03-06
 *
 * Find the smallest and largest in a series of words.
 */
#include <stdio.h>
#include <string.h>

#define N 20

// 入力を受け取る処理を共通化するとコードが綺麗になります
void read_line(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
}

int main(void)
{
    char smallest_word[N + 1], largest_word[N + 1], current_word[N + 1];

    // 1. 最初の単語を入力
    printf("Enter word: ");
    read_line(current_word, N);

    // 最初の単語を最小・最大の両方にセット
    strcpy(smallest_word, current_word);
    strcpy(largest_word, current_word);

    // 2. メインループ
    // 最初の単語が4文字だった場合も考慮して、判定をループの入り口で行います
    while (strlen(current_word) != 4) {
        printf("Enter word: ");
        read_line(current_word, N);

        // 新しく入力された単語を比較し、必要なら更新する
        if (strcmp(current_word, smallest_word) < 0) {
            strcpy(smallest_word, current_word);
        }
        if (strcmp(current_word, largest_word) > 0) {
            strcpy(largest_word, current_word);
        }
    }

    // 3. 結果の表示
    printf("\nSmallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);

    return 0;
}
