#include <stdio.h>

#define MAX_LENGTH 100

int main(void) {
  int n = 0;
  int ch;
  char terminating_ch = 0;
  char sentence[MAX_LENGTH + 1] = {0}; // ヌル文字のために +1

  printf("Enter a sentence: ");

  // 【修正 1: 終端文字で入力を停止】
  while ((ch = getchar()) != EOF && n < MAX_LENGTH) {
    if (ch == '.' || ch == '?' || ch == '!') {
      terminating_ch = (char)ch;

      break;
    }
    sentence[n] = (char)ch;
    n++;
  }

  if (terminating_ch == 0) {
    // ... エラー処理 ...
    return 1;
  }

  sentence[n] = '\0'; // 文字列の終端

  printf("Reversal of sentence: ");

  // 【修正 2: 逆走ロジックの再構築】
  int current_pos = n - 1; // 最後の文字のインデックスから開始
  int word_start;

  int word_end;

  while (current_pos >= 0) {

    // 1. **空白文字をスキップ**し、単語の末尾 (word_end) を見つける
    while (current_pos >= 0 && sentence[current_pos] == ' ') {
      current_pos--;
    }
    word_end = current_pos;

    if (current_pos < 0) {
      break; // 配列の先頭に達したら終了
    }

    // 2. **単語の開始** (word_start) を見つける
    while (current_pos >= 0 && sentence[current_pos] != ' ') {
      current_pos--;
    }
    word_start = current_pos + 1; // 空白の次が単語の始まり

    // 3. **単語を順方向に出力**
    for (int i = word_start; i <= word_end; i++) {
      printf("%c", sentence[i]);
    }

    // 単語の間に空白を出力

    if (current_pos >= 0) {

      printf(" ");
    }
  }

  // 【修正 3: 終端文字を出力】
  printf("%c\n", terminating_ch);

  return 0;
}
