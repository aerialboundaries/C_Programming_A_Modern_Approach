/*
Use strtok to write the following function:
int count_words (char *sentence) ;
count_words returns the number of words in the string sentence, where a "word" is
any sequence of non-white-space characters. count_words is allowed to modify the
string.


My Answer:
int count_words (char *sentence)
{
  char *p;
  p = strtok(sentence, " \t");
  int counter = 1;
  while (p != NULL) {
    p = strtok(NULL, " t");
    counter++;
  }
  return counter;
}

Gemini:
#include <stdio.h>
#include <string.h>

 * 文字列中の単語数（空白以外の文字の連続）をカウントする関数
 * @param sentence 対象の文字列（strtokによって破壊的に変更されます）
 * @return 単語数

int count_words(char *sentence)
{
    int counter = 0;

    // 定義されている全ホワイトスペースを区切り文字として指定
    // (スペース, タブ, 改行, 復帰, ページ送り, 垂直タブ)
    const char *delim = " \t\n\r\f\v";


    // 最初のトークンを取得
    char *p = strtok(sentence, delim);

    // トークンが存在する間ループを回してカウント
    while (p != NULL) {
        counter++;
        p = strtok(NULL, delim); // 次のトークンを取得
    }

    return counter;
}

int main(void)
{
    // strtok は文字列を書き換えるため、変更可能な配列として定義

    char s1[] = "Hello world! This is C99.";
    char s2[] = "   \t  \n "; // 空白のみ
    char s3[] = "OneWord";

    printf("s1 words: %d\n", count_words(s1)); // 5
    printf("s2 words: %d\n", count_words(s2)); // 0
    printf("s3 words: %d\n", count_words(s3)); // 1


    return 0;

}gg

*/
