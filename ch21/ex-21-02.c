/*
2026-06-11

Having located the header files on your system (see Exercise 1), find a standard
header in which a macro hides a function.

My Answer:
WSL（Ubuntu）上の標準Cライブラリにおいて、「マクロが関数を隠している（マクロと関数が同名で定義されている）」具体的な例と、それをシステム上で実際に見つける方法を解説します。

Linux環境（GNU C Library /
glibc）において、このトリックが最も顕著に使われている標準ヘッダの一つが
<ctype.h> です。

1. 発見した具体例：<ctype.h> の文字判定関数
<ctype.h> には、文字がアルファベットかどうかを判定する isalpha
や、数字かどうかを判定する isdigit
などの関数が定義されています。これらは本物の関数として存在していますが、実行速度を高速化するために、全く同じ名前のマクロとしても定義されています。

実際のヘッダファイル内での定義の仕組み
glibcの <ctype.h>
の内部では、大まかに以下のような構造で関数とマクロが共存しています。

C
// 1. まずは本物の関数のプロトタイプ宣言（外部連携用）
extern int isalpha (int) __THROW;
extern int isdigit (int) __THROW;

// 2. その後、同じ名前で高速なマクロを定義
# define isalpha(c)   __isctype((c), _ISalpha)
# define isdigit(c)   __isctype((c), _ISdigit)
このように定義されているため、通常通り isalpha(ch)
と呼び出すと、プリプロセッサによって高速なマクロ __isctype(...)
に置き換わります。しかし、前述の通り (isalpha)(ch) と括弧で囲んだり #undef
isalpha
を行ったりすると、マクロ展開が無効化され、1番のオブジェクトファイル内に実体がある本物の
extern int isalpha(int) 関数が呼び出される仕組みになっています。

2. システム上でこれを見つける Bash コマンド
WSLのターミナルを使って、実際にマクロが関数を隠している記述を探し出す方法です。

ヘッダファイルの実体は /usr/include/ にありますが、そこから直接 grep
コマンドを使って「関数宣言の後に #define
で同じ名前が定義されている箇所」を検索することができます。

grepによる検索例
以下のコマンドをターミナルで実行すると、<ctype.h> の中で isalnum
などの関数がどのようにマクロとして再定義されているか（隠されているか）の該当行をピンポイントで確認できます。

Bash
grep -n "define is" /usr/include/ctype.h
実行すると、以下のようなマクロ定義の行が多数見つかります。

Plaintext
// 実行結果のイメージ
202:#  define isalnum(c)	__isctype((c), _ISalnum)
203:#  define isalpha(c)	__isctype((c), _ISalpha)
204:#  define iscntrl(c)	__isctype((c), _IScntrl)
205:#  define isdigit(c)	__isctype((c), _ISdigit)
3. 実証コード例
この <ctype.h>
の仕様を利用して、通常呼び出し（マクロ）と、括弧をつけた呼び出し（本物の関数）の挙動を比較・検証するプログラムの全文です。

C
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    char test_char = 'A';

    // 1. 通常の呼び出し
    // プリプロセッサによって __isctype((test_char), _ISalpha)
のようなマクロに置換されます if (isalpha(test_char)) {
        printf("通常の呼び出し（マクロ展開）: '%c' はアルファベットです。\n",
test_char);
    }

    2. マクロを隠して本物の関数を呼び出す
    名前を括弧で囲むことで、プリプロセッサは parameterized macro
として認識できなくなり、 コンパイラは標準ライブラリ（libc.a /
libc.so）内の本物の isalpha 関数を呼び出します。 if ((isalpha)(test_char)) {
        printf("括弧付きの呼び出し（本物の関数）: '%c'
はアルファベットです。\n", test_char);
    }

    3. 関数ポインタへの代入（マクロ隠しの必須テクニック）
    マクロのままだとアドレスを取得できませんが、マクロ展開されないため関数アドレスを取得できます。
    int (*fp_isalpha)(int) = isalpha;

    if (fp_isalpha(test_char)) {
        printf("関数ポインタ経由の呼び出し: '%c' はアルファベットです。\n",
test_char);
    }

    return 0;
}
コンパイルと実行
Bash
gcc -Wall -Wextra main.c -o main
./main
標準ライブラリが提供するこの「関数をマクロで隠す」手法は、普段は意識せずに高速化の恩恵を受けつつ、関数ポインタが必要なときには本物の関数として振る舞うことができる、C言語の非常に洗練された設計思想の一つです。
*/
