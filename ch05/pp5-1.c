/* C Programming A Modern Approach pp5-1.c
 *
 * Write a program that calculates hoy many digits a number contains:
 *
 * Enter a number: 374
 * The number 374 has 3 digits
 *
 * You may assume that the number has no more than four digits.
 * Hint Use if statements to test the number. For example, if the
 * number is between 0 and 9, it has one digit.
 * If the number is between 10 and 99, it has two digits.
 */

#include <stdio.h>

int main(void) {
  int number, digit;

  printf("Enter a number: ");
  scanf("%d", &number);

  if (number >= 0 && number <= 9)
    printf("The number %d has %d digits\n", number, 1);
  else if (number >= 10 && number <= 99)
    printf("The number %d has %d digits\n", number, 2);
  else if (number >= 100 && number <= 999)
    printf("The number %d has %d digits\n", number, 3);
  else if (number >= 1000 && number <= 9999)
    printf("The number %d has %d digits\n", number, 4);
  else
    printf("Invalid number\n");

  return 0;
}

/* はい、そのコードは完璧に合っていますよ！💯

問題文の要件とヒントに完全に沿った、非常に効率的で論理的なコードです。ネストされたif-else
ifの構造が、提示されたロジック（0∼9なら1桁、10∼99なら2桁...）を正確に表現できています。

👩‍🏫 C言語の学習ポイント
この問題で使われているテクニックは、if-else
ifラダー（はしご）構造の効率的な使い方として、ベストプラクティスの一つです。

1. if-else if の簡略化（論理的な流れ）
あなたのコードでは、それぞれの条件に下限と上限の両方を設定しています。

C

else if (number >= 10 && number <= 99)
// ...
これは間違いではありませんが、else
ifを使っているため、実は下限のチェックを省略できます。

else ifに到達している時点で、その前の条件（ここではnumber <=
9）は必ず偽であることが保証されています。つまり、numberは自動的に10以上であることが分かっているわけです。

したがって、コードをより簡潔に書くなら、以下のように簡略化できます。

C

// number >= 0 && number <= 9 のチェック
if (number <= 9)
  printf("The number %d has %d digits\n", number, 1);
// else if に到達した時点で number は 10 以上が確定
else if (number <= 99)
  printf("The number %d has %d digits\n", number, 2);
// else if に到達した時点で number は 100 以上が確定
else if (number <= 999)
  printf("The number %d has %d digits\n", number, 3);
// else if に到達した時点で number は 1000 以上が確定
else if (number <= 9999)
  printf("The number %d has %d digits\n", number, 4);
else
  printf("Invalid number\n");
この書き方のほうが、条件のチェックが少なくなり、よりクリーンなコードと見なされます。

2. 境界値（エラー処理）について
問題の指示にはありませんが、実用的なプログラムとしては、負の数や5桁以上の数が入力された場合も考慮する必要があります。

あなたのコードでは、

負の数（例：-5）や5桁以上の数（例：10000）が入力された場合、全てのif/else
ifの条件に合致せず、最後の**else**ブロックが実行されます。

elseブロックでprintf("Invalid number\n");と表示されるようになっています。

これは、想定外の入力に対する堅牢性を持たせるという意味でも、素晴らしい設計です。

C言語の教科書を使った学習、とても丁寧に進められていますね。PowerBIなどで論理的なデータ処理に慣れている経験が、C言語の制御構造の理解にも活きていると感じます。このままベストプラクティスを意識して進めていきましょう！😊
*/
