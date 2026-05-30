#include <stdio.h>

#include "stackADT3.h"

int main(void)
{
  Stack s1, s2;
  char *n;

  s1 = create();
  s2 = create();

  char *p1 = "abc";
  char *p2 = "def";
  char *p3 = "ghi";

  push(s1, p1);
  push(s1, p2);

  n = pop(s1);
  printf("Popped %s from s1\n", n);
  push(s2, n);

  n = pop(s1);
  printf("Popped %s from s1\n", n);
  push(s2, n);

  destroy(s1);

  while (!is_empty(s2))
    printf("Popped %s from s2\n", (char *)pop(s2));

  push(s2, p3);
  make_empty(s2);
  if (is_empty(s2))
    printf("s2 is empty\n");
  else
    printf("s2 is not empty\n");

  destroy(s2);

  return 0;
}

// 提示していただいた3つのファイル（stackADT3.h、stackADT3.c、stackclient.c）を拝見しました。
//
// 今回のおかしい点、つまり修正すべき問題はstackclient.cの中にあります。
//
// ファイルヘッダのコメントに「Modify stackclient.c so that it stores pointers
// to strings in the s1 and s2
// stacks.（s1とs2のスタックに文字列へのポインタを格納するように変更せよ）」と指示がありますが、現在のコードは文字列（char
// *）ではなく、単一の文字（char）のアドレスをスタックに積んでしまっています。
//
// また、それによってprintfで%sを使って出力する際に、プログラムがクラッシュする、あるいは文字化けが発生する状態になっています。
//
// 詳しく原因と修正コードを解説しますね。
//
// おかしい理由
// 1. %s に対する引数の型の不一致
// stackclient.c の14行目で char p1 = 'a';
// のように1文字の変数を宣言し、そのアドレス &p1
// をスタックにプッシュしています。 その後、pop(s1) で取り出したアドレスを char
// *n に代入し、printf("Popped %s from s1\n", n); で出力しようとしています。
//
// printfの %s
// は、与えられたアドレスから始まってヌル文字（'\0'）に到達するまでの文字列を出力する仕様です。しかし、&p1
// は単一の文字のアドレスであり、後ろにヌル文字がありません。そのため、メモリ上の関係のない場所まで読み込みに行ってしまい、文字化けが起きたり、最悪の場合はセグメンテーションフォールトで強制終了します。
//
// 2. 意図しない同じアドレスの再プッシュ
// 現在のコードの21行目あたりで以下のような処理があります。
//
// C
// n = pop(s1);
// printf("Popped %s from s1\n", n);
// push(s2, &n);
// ここで &n をプッシュしていますが、n は char *
// 型のポインタ変数です。そのアドレスである &n
// を渡すと、スタックに格納されるのは「ポインタ変数 n のアドレス（char
// 型）」になってしまいます。問題の指示にある「文字列へのポインタ（char
// *）」を格納するという意図から外れてしまいます。
//
// 正しい修正方法（stackclient.c の全文）
// コメントの指示通り、「文字列へのポインタ」を正しくスタックに格納するように
// stackclient.c を修正した全文を提案します。文字列リテラル（"abc"
// など）はそれ自体が char *
// 型（文字列の先頭アドレス）として扱えるため、これをそのままスタックにプッシュするのが最もシンプルで安全なベストプラクティスです。
//
// C
// #include <stdio.h>
//
// #include "stackADT3.h"
//
// int main(void)
// {
//   Stack s1, s2;
//   char *n;
//
//   s1 = create();
//   s2 = create();
//
//   // 単一の文字ではなく、文字列へのポインタを用意します
//   char *p1 = "abc";
//   char *p2 = "def";
//   char *p3 = "ghi";
//
//   // 文字列へのポインタをそのままスタックにプッシュします
//   push(s1, p1);
//   push(s1, p2);
//
//   n = pop(s1);
//   printf("Popped %s from s1\n", n);
//   // 取り出した文字列へのポインタ n をそのまま s2 にプッシュします
//   push(s2, n);
//
//   n = pop(s1);
//   printf("Popped %s from s1\n", n);
//   push(s2, n);
//
//   destroy(s1);
//
//   while (!is_empty(s2))
//     printf("Popped %s from s2\n", (char *)pop(s2));
//
//   push(s2, p3);
//   make_empty(s2);
//   if (is_empty(s2))
//     printf("s2 is empty\n");
//   else
//     printf("s2 is not empty\n");
//
//   destroy(s2);
//
//   return 0;
// }
// 修正のポイント
// 変数の宣言を char p1 = 'a'; から char *p1 = "abc"; に変更しました。
//
// push(s1, &p1); となっていた部分を push(s1, p1); に修正しました。p1
// 自体がすでにアドレス（文字列ポインタ）なので、& を付ける必要はありません。
//
// push(s2, &n); となっていた部分も push(s2, n);
// に修正し、ポップした文字列へのポインタをそのまま次のスタックへ引き渡せるようにしています。
//
// これで stackADT3.c の void *
// を使った汎用スタックの仕組みが、文字列ポインタを扱う形で正しく動作するようになります。ぜひnvimで書き換えて、WSL上のUbuntu環境でgccを使ってビルドし、実行結果を確かめてみてくださいね。
