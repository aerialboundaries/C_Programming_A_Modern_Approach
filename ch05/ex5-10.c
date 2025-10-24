/* C Programming A Modern Approach ex5-10.c
 *
 * What output does the following program fragment produce? (Assume that i is an
 * integer varialble.)
 */

#include <stdio.h>

int main(void) {
  int i = 1;

  switch (i % 3) {
  case 0:
    printf("zero\n");
  case 1:
    printf("one\n");
  case 2:
    printf("two");
  }
  return 0;
}

/* My Answer: one */

/* そのご回答、残念ながら間違いです😔。

正しい出力は

one
two
になります。

C言語の**switch文の振る舞いについて、大切なベストプラクティス**と合わせて詳しく解説しますね。

switch文の「フォールスルー」について
C言語のswitch文の動作で、非常に重要かつ、間違いやすいポイントが**break文**の存在です。

1. switchの式の評価
まず、switch文の式が評価されます。

C

int i = 1;
switch (i % 3) { // i % 3 は 1 % 3 で、結果は 1 になります。
// ...
変数のiは1なので、i % 3の結果は**1**です。

2. マッチしたcaseから実行開始
この結果1に一致するcaseラベルは**case 1:**です。

C

  case 1:
    printf("one\n"); // ここから実行が始まります。
  case 2:
    printf("two");
  }
したがって、最初にoneが出力されます。

3. breakがないと実行が「フォールスルー」する
C言語のswitch文の大きな特徴は、break文がない場合、マッチしたcaseから下のcaseの処理をすべて実行し続けてしまうという点です。これを**フォールスルー
(fall-through)**と呼びます。

あなたのコードでは、case 1:の後にbreak文がありません。

C

  case 1:
    printf("one\n"); // 実行される
  case 2:           // breakがないので、case
1:の実行後、ここを素通りして実行が継続されます。     printf("two");   //
実行される   } case 1:の処理が終わると、制御は次のcase
2:の処理に**「フォールスルー」**してしまいます。そのため、case
2:の中のprintf("two");も実行されます。

最後にtwoが出力され、switch文のブロックが終わるので、処理が終了します。

最終出力
printf("one\n");の後に改行(\n)があり、printf("two");の後には改行がないため、出力は次のようになります。

one
two
👩‍🏫 ベストプラクティス：必ずbreakを！
ほとんどの場合、switch文では、一つのcaseの処理が終わったら、他のcaseの処理を実行せずにswitch文から抜けたいはずです。そのため、各caseブロックの最後には必ずbreak;を書くのがベストプラクティスであり、一般的な書き方です。

フォールスルーを意図的に行う場合は、コメントでその旨を明記するのが親切です。

修正後のコード例（意図した動作）
もし、「i %
3が1の時だけoneを出力して終わりたい」という意図であれば、このようにbreakを追加します。

C

#include <stdio.h>

int main(void) {
  int i = 1;

  switch (i % 3) {
  case 0:
    printf("zero\n");
    break; // breakを追加
  case 1:
    printf("one\n");
    break; // breakを追加
  case 2:
    printf("two\n"); // ここにも break; を追加するのが一般的
  }
  return 0;
}
// 出力: one
これで期待通り「one」だけが出力されますよ😊

C言語のswitch文は、このフォールスルーの挙動を知らないとバグの原因になりやすいので、しっかりと覚えておきましょう！*/
