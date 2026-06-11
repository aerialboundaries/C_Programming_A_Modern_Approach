/*
2026-06-11

In which standard header would you expect to find each of the following?
(a) A function that determines the current day of the week
(b) A function that tests whether a character is a digit
(c) A macro that gives the largest unsigned int value
(d) A function that rounds a floating-point number to the next higher integer
(e) A macro that specifies the number of bits in a character
(f) A macro that specifies the number of significant digits in a double value
(g) A function that searches a string for a particular character
(h) A function that opens a file for reading

My Answer:
(a) <time.h>
(b) <ctype.h>
(c) <limits.h>
(d) <math.h>
(e) <limits.h>
(f) <float.h>
(g) <string.h>
(h) <stdio.h>
*/

/*
各問題の答え合わせと解説
(a) 曜日に変換する関数
あなたの回答: <time.h>（大正解）

解説: 現在の曜日（tm_wday）を取得するための localtime 関数や mktime 関数、および
struct tm 構造体はすべて <time.h> に定義されています。

(b) 文字が数字（0〜9）かテストする関数
あなたの回答: <ctype.h>（大正解）

解説: 先ほども登場した isdigit 関数（またはマクロ）は <ctype.h>
に含まれています。

(c) unsigned int の最大値を示すマクロ
あなたの回答: <limits.h>（大正解）

解説: 整数型の限界値を表すマクロは <limits.h> に定義されています。具体的には
UINT_MAX というマクロがこれに当たります。

(d) 浮動小数点数を「次の大きな整数」に切り上げる関数
あなたの回答: <fenv.h>

正しい答え: <math.h>

解説:
<fenv.h> はC99で追加された「浮動小数点環境（Floating-Point
Environment）」を制御するためのヘッダで、丸めモードの設定（フラグの変更）などを行う場所です。
実際に数値を引数に取って、切り上げ（天井関数）の計算を行う ceil や ceilf
といった具体的な数学関数は、すべて <math.h> に定義されています。

(e) 1つの文字（character）のビット数を指定するマクロ
あなたの回答: <stdio.h>

正しい答え: <limits.h>

解説:
<stdio.h>
は標準入出力を扱うヘッダなので、型やビット数などのデータ型のサイズに関する情報は持っていません。
「1文字（char 型）が何ビットか」を指定するマクロは CHAR_BIT
であり、これは整数型の特性を定義する <limits.h>
に定義されています（一般的な環境では 8 が定義されています）。

(f) double 型の有効桁数を指定するマクロ
あなたの回答: <float.h>（大正解）

解説: 浮動小数点数（float や double）の精度や有効桁数を表すマクロ（DBL_DIG
など）は、すべて <float.h> に集約されています。

(g) 文字列から特定の文字を検索する関数
あなたの回答: <string.h>（大正解）

解説: 文字列内から文字を検索する strchr 関数などは <string.h>
に定義されています。

(h) ファイルを読み込み用にオープンする関数
あなたの回答: <stdio.h>（大正解）

解説: ファイル操作を行う fopen 関数や FILE 構造体は、すべて <stdio.h>
に定義されています。

修正を反映した満点回答のまとめ
(a) <time.h>

(b) <ctype.h>

(c) <limits.h>

(d) <math.h> （ceil 関数のため）

(e) <limits.h> （CHAR_BIT マクロのため）

(f) <float.h>

(g) <string.h>

(h) <stdio.h>

型のサイズや限界値に関わるものは、それが整数系なら <limits.h>、浮動小数点系なら
<float.h>
という住み分けを意識すると、今後の章でも迷わなくなりますよ。非常に惜しい解答でした。この調子で進めていきましょう。*/
