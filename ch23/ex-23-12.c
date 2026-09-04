/* Many versions of <string.h> provide additional (nonstandard) functions, such as those
listed below. Write each function using only the features of the C standard.

(a) strdup(s) -Returns a pointer to a copy of s stored in memory obtained by calling
    malloc. Returns a null pointer if enough memory couldn't be allocated.
(b) stricmp(s1, s2)-Similar to strcmp, but ignores the case of letters.
(c) strlwr(s) -Converts upper-case letters in s to lower case, leaving other characters
    unchanged; returns s.
(d) strrev(s) -Reverses the characters in s (except the null character); returns s.
(e) strset (s, ch) -Fills s with copies of the character ch; returns s.

If you test any of these functions, you may need to alter its name. Functions whose names
begin with str are reserved by the C standard.

Gemini:
C言語の標準ライブラリ関数（<string.h>, <stdlib.h>, <ctype.h>）のみを使用して、これらの非標準関数を実装するコードを作成しました。

問題文にある通り、標準予約語との衝突を防ぐため関数名には接頭辞 my_ を付与しています。そのままお使いのエディタ（nvim）やコンパイラ（gcc）でテストできるよう、全文を記述しています。

C
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

(a) strdup: 文字列 s の複製を malloc で確保して返す
char *my_strdup(const char *s)
{
    // \0 の分を含めてメモリ領域を確保
    size_t len = strlen(s) + 1;
    char *copy = malloc(len);

    if (copy == NULL) {
        return NULL;
    }

    // メモリ確保に成功したら複製してポインタを返す
    return memcpy(copy, s, len);
}

(b) stricmp: 大文字・小文字を無視して文字列 s1 と s2 を比較する 
int my_stricmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s2 != '\0') {
        unsigned char c1 = tolower((unsigned char)*s1);
        unsigned char c2 = tolower((unsigned char)*s2);

        if (c1 != c2) {
            return c1 - c2;
        }
        s1++;
        s2++;
    }

    // どちらかが '\0' に達した後の比較（長さの違いを判定）
    return (unsigned char)tolower((unsigned char)*s1) - 
           (unsigned char)tolower((unsigned char)*s2);
}

(c) strlwr: 文字列 s 内の大文字を小文字に変換する（s 自体を返す）
char *my_strlwr(char *s)
{
    char *p = s;
    while (*p != '\0') {
        *p = (char)tolower((unsigned char)*p);
        p++;
    }
    return s;
}

(d) strrev: 文字列 s を反転させる（s 自体を返す）
char *my_strrev(char *s)
{
    if (s == NULL || *s == '\0') {
        return s;
    }

    // 先頭と末尾（'\0' の手前）を指すポインタを用意
    char *start = s;
    char *end = s + strlen(s) - 1;

    // 両端から挟み込むように文字を入れ替える
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    return s;
}

 (e) strset: 文字列 s の全文字を ch で埋める（s 自体を返す） 
char *my_strset(char *s, char ch)
{
    char *p = s;
    while (*p != '\0') {
        *p = ch;
        p++;
    }
    return s;
}

int main(void)
{
    // (a) my_strdup のテスト
    char *dup_str = my_strdup("Hello, World!");
    if (dup_str != NULL) {
        printf("(a) my_strdup: %s\n", dup_str);
        free(dup_str); // malloc したメモリの解放
    }

    // (b) my_stricmp のテスト
    printf("(b) my_stricmp (\"Apple\", \"apple\"): %d\n", my_stricmp("Apple", "apple"));
    printf("(b) my_stricmp (\"Apple\", \"Banana\"): %d\n", my_stricmp("Apple", "Banana"));

    // (c) my_strlwr のテスト
    char text_lwr[] = "C Programming 101";
    printf("(c) my_strlwr: %s\n", my_strlwr(text_lwr));

    // (d) my_strrev のテスト
    char text_rev[] = "Algorithm";
    printf("(d) my_strrev: %s\n", my_strrev(text_rev));

    // (e) my_strset のテスト
    char text_set[] = "SecretData";
    printf("(e) my_strset: %s\n", my_strset(text_set, '*'));

    return 0;
}
実装時のベストプラクティス・ポイント

<ctype.h> 関数の安全な呼び出し:

tolower などの関数に char を渡す際、負の値（日本語や特殊文字など）が入ると未定義動作になるのを防ぐため、(unsigned char) にキャストして渡しています。

(a) my_strdup での memcpy 利用:

strlen であらかじめ長さが分かっている場合、strcpy よりも memcpy を使う方が余計な終端チェックが走らず効率的です。

(d) my_strrev でのポインタ挟み込み:

start < end となるまで先頭と末尾の要素を交換していく手法は、配列反転の典型的なアルゴリズムです。

予約名回避:

C標準の仕様上、str で始まる関数名は将来の拡張用に予約されているため、自作関数を作成する際は my_ などを付与して回避するのが適切な作法です。
*/
