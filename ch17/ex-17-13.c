/* C Programming A Modern Approach
 * ex-17-12.c
 * 2026-04-28
 *
 * The following function is supposed to insert a new node into its proper place in an ordered
 * list, returning a pointer to the first node in the modified list. Unfortunately, the function
 * doesn't work correctly in all cases. Explain what's wrong with it and show how to fix it.
 * Assume that the node structure is the one defined in Section 17.5.
 *
 * struct node *insert_into_ordered_list (struct node *list, struct node *new node)
 * {
 *   struct node *cur = list, *prev = NULL;
 *   while (cur->value <= new node->value) {
 *     prev= cur;
 *     cur = cur->next;
 *   }
 *   prev->next = new node;
 *   new node->next = cur;
 *   return list;
 * }
 * 
 */

// My Answer
// if new_nord->value is larger than 1st node, loop does not work


struct node *insert_into_ordered_list (struct node *list, struct node *new_node)
{
  struct node *cur = list, *prev = NULL;

  if (cur->value >= new_node->value) {
    new_node->next = cur;
  }

  while (cur->value <= new_node->value) {
    prev= cur;
    cur = cur->next;
  }
  prev->next = new node;
  new node->next = cur;
  return list;
}

連結リストの挿入処理ですね。実はこの問題は、C言語のポインタ操作における「境界条件（エッジケース）」を網羅する必要がある、非常に教育的な良問です。

残念ながら、提示いただいた修正案にはいくつか改善すべき点があります。このコードが抱えている主な問題点は、「空のリストへの対応」、「リストの先頭への挿入」、そして「リストの末尾への挿入（NULL参照）」の3点です。

元のコードと修正案の共通の問題点
リストが空の場合 (list == NULL):
cur->value を参照した瞬間にセグメンテーションフォールト（強制終了）が発生します。

リストの末尾まで進む場合:
new_node->value がリスト内のどの値よりも大きい場合、cur が NULL になります。その状態で while (cur->value ...) を判定しようとするとエラーになります。

先頭への挿入:
先頭に挿入する場合、関数の戻り値は new_node （新しい先頭）である必要がありますが、今のコードは return list; のままで、古い先頭を返してしまいます。

正しい修正方法
これらのケースをすべてカバーするには、while 文の条件に cur != NULL を追加し、先頭に挿入する場合の分岐を正しく書く必要があります。

修正された全文コード
C
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *insert_into_ordered_list(struct node *list, struct node *new_node)
{
    struct node *cur = list, *prev = NULL;

    /* 1. 挿入場所を探す */
    /* curが末尾に達しておらず、かつ現在の値が挿入する値より小さい間ループ */
    while (cur != NULL && cur->value < new_node->value) {
        prev = cur;
        cur = cur->next;
    }

    /* 2. 新しいノードをリストにつなぐ */
    new_node->next = cur;

    /* 3. 先頭への挿入か、それ以外かで分岐 */
    if (prev == NULL) {
        /* リストが空だったか、先頭の値よりも新しい値の方が小さい場合 */
        return new_node;
    } else {
        /* リストの途中、または末尾への挿入 */
        prev->next = new_node;
        return list;
    }
}
どこが良くなったか
安全なループ: cur != NULL を先にチェックすることで、リストの末尾を通り過ぎてエラーになるのを防いでいます。

先頭挿入への対応: prev == NULL かどうかで、リストの「頭」がすげ変わったかどうかを判断しています。

空リストへの対応: list が NULL で渡されても、while をスキップして if (prev == NULL) に入り、正しく new_node を返します。

プロのアドバイス
連結リストの操作を考えるときは、常に以下の3つのパターンを紙に書いてシミュレーションしてみるのが鉄則です。

Case 1: 空のリスト

Case 2: 先頭への挿入

Case 3: 末尾への挿入

Neovimでこのコードを書いて、いろいろな値を挿入するテストをしてみてください。while 文の条件の順番（cur != NULL を左側に書くこと）も、ショートサーキット評価といって非常に重要なポイントですよ。


