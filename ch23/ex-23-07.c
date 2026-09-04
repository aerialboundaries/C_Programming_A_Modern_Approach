/*
Section 23.6 explains how to call strchr repeatedly to locate all occurrences of a charac-
ter within a string. Is it possible to locate all occurrences in reverse order by calling
strrchr repeatedly?

My Answer: Yes.  p = strrchr(p - 1, 'f');

Answer by Gemini:
論理的には「可能（Yes）」ですが、提示された式をそのまま繰り返し（ループ）で呼び出すと、バッファアンダーラン（未定義動作）や無限ループを引き起こしてしまいます。

問題点と理由
配列の先頭を突き抜ける危険性（バッファアンダーラン）
strrchr(p - 1, 'f') と書くと、初回検索で文字列の先頭（s[0]）に文字が見つかった場合、次のループで p - 1 は配列の外（メモリの手前）を指してしまいます。配列の先頭より前のメモリ領域をアクセス・参照することはC言語では未定義動作（Undefined Behavior）です。

末尾文字のヌル文字（'\0'）の扱い
strrchr(s, ch) は、指定した検索文字列 s の先頭アドレスから終端の '\0' までを検索対象にします。先頭アドレスを前にずらしても、常に文字列の末尾までを対象に探してしまうため、1回見つかった場所より後ろの領域を切り落とす工夫（ヌル文字で一時的に区切るなど）をしないと、同じ文字を何度も見つけて無限ループになります。

正しい実装のアプローチ
strrchr を繰り返し使って逆順検索を実現するには、「見つかった位置に一時的に '\0' を書き込んで文字列を短く切る」 か、あるいは 「検索対象の文字列自体を1文字ずつ短くしたコピーに切り出す」 必要があります。

元のアドレスを変更せず、自前でポインタ演算を行って安全に実現するコード例です。

C
#include <stdio.h>
#include <string.h>

void find_in_reverse(char *s, char ch)
{
    // 一時的に文字列を切るために writable なコピーを作成するなどの配慮が必要
    char *p = strrchr(s, ch);

    while (p != NULL) {
        printf("Found '%c' at index: %td\n", ch, p - s);

        // 見つかった位置を一時的に終端文字 ('\0') に置き換えて
        // 次回の strrchr の検索範囲をその手前までに絞る
        *p = '\0';

        // 手前の領域から再検索
        p = strrchr(s, ch);
    }
}

int main(void)
{
    char str[] = "offline_file_format";
    find_in_reverse(str, 'f');
    return 0;
}
実務上のワンポイント
strrchr を無理に繰り返し呼ぶと上記のように文字列を破壊（書き換え）する必要が出てくるため、実務や標準的なC言語のコードでは、「通常の strchr で先頭から全件検索して結果を配列/スタックに保持し、逆順に出力する」 か、単に 「配列の末尾インデックスからループで手前へ向かって探す」 方法が選ばれます。
*/
