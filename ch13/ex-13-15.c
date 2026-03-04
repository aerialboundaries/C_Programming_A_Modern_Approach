/* C Programming A Modern Approach
 * ex-13-15.c
 * 2026-03-04
 *
 * Let f be the following function:
 *
 */
#include <stdio.h>

int f(char *s, char *t)
{
    char *p1, *p2;

    for (p1 = s; *p1; p1++) {
        for (p2 = t; *p2; p2++)
            if (*p1 == *p2)
                break;
        if (*p2 == '\0')
            break;
    }
    return p1 - s;
}

int main(void)
{
    printf("(a) \"abcd\", \"babc\" %d\n", f("abcd", "babc"));
    printf("(b) \"abcd\", \"bcd\" %d\n", f("abcd", "bcd"));

    return 0;
}

/*
 * (a) What is the value of f("abcd", "babc")?
 * (b) What is the value of f("abcd", "bcd")?
 * (c) In general, what value does f return when passed tow strings s and t?
 *
 * My Answer:
 * (a) 3
 * (b) 0
 * (c) The length of the longest prefix of the string s that consists entirely
 *     of characters from the string t. Or, equivalently, the position of
 *     the first character in s that is not also in t.
 *
 */

/* コードの挙動を解剖する
この関数の肝は、内側のループが終わった直後の状態チェックにあります。

内側のループ (p2) の役割:
文字列 s の現在の文字 (*p1) が、文字列 t の中に含まれているか探します。

見つかった場合：if (*p1 == *p2) が真になり、break します。このとき、*p2
は見つかった文字を指しているので、*p2 は \0 ではありません。

見つからなかった場合：ループは t の終端まで回りきります。このとき、*p2 は \0
になっています。

外側のループを抜ける判定:
if (*p2 == '\0') break;
これは「もし t の中を全部探しても *p1
が見つからなかったら、外側のループも終了する」という意味になります。

つまり、**「t に含まれない文字が s
に現れた瞬間にストップする」**という動きになります。

設問の検証
(a) f("abcd", "babc")
*p1 = 'a': t ("babc") の中に 'a' はある？ → ある (*p2 != '\0')。続行。

*p1 = 'b': t の中に 'b' はある？ → ある。続行。

*p1 = 'c': t の中に 'c' はある？ → ある。続行。

*p1 = 'd': t の中に 'd' はある？ → ない。ここで *p2 は \0 になり、外側のループを
break します。

p1 は 'd' の位置（インデックス 3）を指しているので、p1 - s は 3。

(b) f("abcd", "bcd")
*p1 = 'a': t ("bcd") の中に 'a' はある？ → ない。いきなり break。

p1 は 'a' の位置（インデックス 0）を指しているので、p1 - s は 0。

(c) 一般的な意味
あなたの回答通り、これは標準ライブラリ関数の strspn と全く同じ動作です。

s の先頭から調べて、t
に含まれる文字だけで構成されている部分（プレフィックス）の長さを返します。

プロの補足：C言語らしい「簡潔なイディオム」
実務的なコードや、より上級のCプログラマが書く場合、この挙動はもっと短く書かれることがあります。参考までに、nvim
で書き換えて遊んでみてください。

C
#include <stdio.h>

// 同じ動作を、より簡潔に書いた例
int f_idiomatic(char *s, char *t)
{
    char *p1, *p2;

    for (p1 = s; *p1; p1++) {
        for (p2 = t; *p2 && *p1 != *p2; p2++)
            ; // 内側で何もしない
        if (!*p2) // *p2 == '\0' と同義
            break;
    }
    return p1 - s;
}

int main(void)
{
    // テストコード（全文）
    char str[] = "abcd";
    char set1[] = "babc";
    char set2[] = "bcd";

    printf("Result (a): %d\n", f_idiomatic(str, set1)); // 3
    printf("Result (b): %d\n", f_idiomatic(str, set2)); // 0

    return 0;
}
*p2 && *p1 != *p2
のように、ループの継続条件の中に「一致したかどうか」を組み込むのがC言語らしい書き方です。
*/
