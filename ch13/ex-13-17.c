/* C Programming A Modern Approach
 * ex-13-17.c
 * 2026-03-05
 *
 * Write the following function:
 * bool test_extension(const char *file_name, const char *extension);
 * file_name points to a string containing a file name. The function should
 * return true if the file's extension matches the string pointed to by
 * extension, ignoring the case of letters. For example the call
 * test_extension("memo.txt", "TXT") would return true. Incorporate the "search
 * for the end of string" idiom into your function. Hint: Use the toupper
 * function to convert characters to upper-case before comparing them.
 */
/* C Programming A Modern Approach
 * ex-13-17.c
 * 2026-03-05
 *
 * ファイルの拡張子を大文字小文字を区別せずに判定する
 */
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

// 関数のプロトタイプ宣言
bool test_extension(const char *file_name, const char *extension);

int main(void)
{
    // テストケース
    printf("memo.txt vs TXT: %s\n",
        test_extension("memo.txt", "TXT") ? "true" : "false");
    printf("setup.exe vs EXE: %s\n",
        test_extension("setup.exe", "EXE") ? "true" : "false");
    printf("script.sh vs TXT: %s\n",
        test_extension("script.sh", "TXT") ? "true" : "false");

    return 0;
}

bool test_extension(const char *file_name, const char *extension)
{
    // 1. まずはピリオドを探す（ Section 13.6 のイディオム活用 ）

    // 文字列の末尾まで進み、かつ '.' が見つかるまでループ
    while (*file_name != '\0' && *file_name != '.') {
        file_name++;
    }

    // もし '.' が見つからなかった場合（文字列の末尾に達した場合）
    if (*file_name == '\0') {
        return false;
    }

    // '.' の次の文字から比較を開始する
    file_name++;

    // 2. 拡張子部分を 1 文字ずつ比較する
    // file_name と extension の両方が終わるまでループ
    while (*file_name != '\0' || *extension != '\0') {
        // 片方の大文字変換と、もう片方の文字（すでに大文字想定）を比較
        // extension 側も念のため toupper しておくとより安全です
        if (toupper((unsigned char)*file_name)
            != toupper((unsigned char)*extension)) {
            return false; // 1文字でも違えば false
        }
        file_name++;
        extension++;
    }

    // すべて一致してループを抜ければ true
    return true;
}
