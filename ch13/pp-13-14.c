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
/* C Programming A Modern Approach
 * pp-13-14.c
 * 2026-03-10
 */

#include <ctype.h>

#include <stdbool.h>
#include <stdio.h>

/* 単語の最大長を定義 */
#define WORD_LEN 100

/* 関数のプロトタイプ宣言 */
bool are_anagrams(const char *word1, const char *word2);

int main(void) {
  char word1[WORD_LEN + 1];
  char word2[WORD_LEN + 1];
  int ch, i;

  /* 1つ目の単語を入力 */
  printf("Enter first word: ");
  i = 0;

  while ((ch = getchar()) != '\n' && ch != EOF) {
    if (i < WORD_LEN) {
      word1[i++] = (char)ch;
    }
  }
  word1[i] = '\0'; /* 文字列の終端を保証 */

  /* 2つ目の単語を入力 */
  printf("Enter second word: ");
  i = 0;
  while ((ch = getchar()) != '\n' && ch != EOF) {
    if (i < WORD_LEN) {
      word2[i++] = (char)ch;
    }
  }
  word2[i] = '\0';

  /* 判定と出力 */
  if (are_anagrams(word1, word2)) {
    printf("The words are anagrams.\n");
  } else {
    printf("The words are not anagrams.\n");
  }

  return 0;
}

/**
 * 2つの文字列がアナグラムかどうかを判定する
 * アルファベット以外の文字は無視し、大文字小文字を区別しない
 */
bool are_anagrams(const char *word1, const char *word2) {
  int counts[26] = {0}; /* 各アルファベットの出現回数を記録 */
  int i;

  /* 1つ目の文字列をスキャンしてカウントアップ */
  while (*word1) {
    if (isalpha((unsigned char)*word1)) {
      /* tolowerの結果から'a'を引くことで0-25のインデックスを得る */
      counts[tolower((unsigned char)*word1) - 'a']++;
    }
    word1++;
  }

  /* 2つ目の文字列をスキャンしてカウントダウン */
  while (*word2) {
    if (isalpha((unsigned char)*word2)) {
      counts[tolower((unsigned char)*word2) - 'a']--;
    }
    word2++;
  }

  /* すべての要素が0であればアナグラム */
  for (i = 0; i < 26; i++) {
    if (counts[i] != 0) {
      return false;
    }
  }

  return true;
}
