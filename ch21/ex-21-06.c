/*
2026-06-11

The <ctype.h> header usually defines most of its functions as macros as well.
These macros rely on a static array that's declared in <ctype. h> but defined in
a separate file. A portion of a typical <ctype.h> header appears below. Use this
sample to answer the following questions.

(a) Why do the names of the "bit" macros (such as _UPPER) and the_ctype array
    begin with an underscore?

(b) Explain what the _ctype array will contain. Assuming that the character set
is ASCII. show the values of the array elements at positions 9 (the horizontal
tab character), 32 (the space character), 65 (the letter A), and 94 (the ^
    character). See Section 23.5 for a description of what each macro should
return.

(c) What's the advantage of using an array to implement these macros?
*/

#define _UPPER 0x01   /* upper-case letter */
#define _LOWER 0x02   /* lower-case letter */
#define _DIGIT 0x04   /* decimal digit */
#define _CONTROL 0x08 /* control character */
#define _PUNCT 0x10   /* punctuation character */
#define _SPACE 0x20   /* white-space character */
#define _HEX 0x40     /* hexadecimal digit */
#define _BLANK 0x80   /* space character */

#define isalnum(c) (_ctype[c] & (_UPPER | _LOWER | _DIGIT))
#define isalpha (c)(_ctype[c] & (_UPPER | _LOWER))
#define iscntrl(c) (_ctype[c] & _CONTROL)
#define isdigit (c)(_ctype[c] & _DIGIT)
#define isgraph(c) (_ctype[c] & (_PUNCT | _UPPER | _LOWER | _DIGIT))
#define islower (c)(_ctype[c] & _LOWER)
#define isprint (c)(_ctype[c] & (_BLANK | _PUNCT | _UPPER | _LOWER | _DIGIT))
#define ispunct (c)(_ctype[c] & _PUNCT)
#define isspace (c)(_ctype[c] & _SPACE)
#define isupper(c) (_ctype[c] & _UPPER)
#define isxdigit (c)(_ctype[c] & (_DIGIT | _HEX))

/* My Answer
(a): To avoid name conflicts with identifiers defined by the programmer. The C
standard reserves identifiers starting with an underscore followed by an
uppercase letter for library internal use.
（プログラマが定義する識別子との衝突を避けるため。Cの標準規格は、アンダースコアに大文字が続く識別子をライブラリの内部利用向けに予約している。）

(b)
The array contains bitwise ORed flags representing the characteristics of each
character.
（配列には、各文字の特性を表すフラグをビット論理和した値が含まれる。）

Position 9 (\t): 0x28 (_CONTROL | _SPACE)

Position 32 (' '): 0xA0 (_SPACE | _BLANK)

Position 65 ('A'): 0x41 (_UPPER | _HEX)

Position 94 ('^'): 0x10 (_PUNCT)

(c):
It is highly efficient because character classification requires only a single
array lookup and a bitwise AND operation. Additionally, it ensures safety
because the argument c is evaluated exactly once, avoiding bugs caused by side
effects (e.g., *p++).
（配列の参照と1回のビット論理積だけで文字判定ができるため極めて高速である。さらに、引数
c
がちょうど1回しか評価されないため、副作用によるバグを防ぐことができ安全である。


*/

/*
教科書「C Programming
    : A Modern
Approach」第21章の、標準ライブラリの内部実装（ビットマスクとテーブル参照）に関する非常に本質的な問題ですね。

          あなたの回答は、全体の方向性やエッセンス（マクロで高速化する、マスクをかけるなど）を綺麗に捉えられています。素晴らしい着眼点です。

              これをC言語の標準規格、およびビット演算の正確なルールに照らし合わせ、さらに隙のない満点解答にするための修正点と解説を、(
                  a) から(c) まで順番にお伝えしますね。

      (a) アンダースコアで始まる理由 あなたの回答 in order to avoid
      double definition of UPPER macro.（UPPERマクロの二重定義を避けるため）

      講師の解説と修正
      方向性は合っていますが、「二重定義を避ける」というよりも、さらに一歩進めて「ユーザー（プログラマ）が作る名前との衝突を避けるため」、そして「標準ライブラリの仕様として予約されているから」と答えると満点になります。

      21.1節の「Restrictions on Names Used in the
      Library（名前の制限）」で学んだ通り、C言語の標準規格では、「アンダースコア＋大文字」で始まる名前はすべて標準ライブラリの内部実装のために予約されています。

      もしライブラリ側が単に #define UPPER
      0x01 と定義してしまうと、ユーザーが自分のプログラム内で int UPPER = 10;
のような変数を定義したときに、プリプロセッサによって破壊されてしまいます。ユーザーが絶対に使ってはいけない（使わないはずの）予約語のルールを利用して、衝突を防いでいるのが本当の理由です。

    (b)
    _ctype 配列の中身と特定の要素の値
    あなたの回答 _ctype array contains bynary data of
    char in order to be masked by other macros.position 9 : 0x09,
    position 32 : 0x20,
    position 94 : 0x5E

    講師の解説と修正 ここが今回最大の落とし穴です。 あなたが提示してくださった
    0x09、0x20、0x5E
という数値は、実はASCIIコードにおけるその文字自体の値（10進数の9
    ,
    32,
    94を16進数にしたもの）になっています。

        この _ctype
        配列に格納されているのは、文字のコードそのものではなく、問題文の最初にある
        _UPPER や _LOWER
        などの「属性フラグ（ビット）」を足し合わせた（ORした）数値になります。

        提示されたマクロの定義（例
    : islower(c)(_ctype[c] & _LOWER)）を見ると、配列から取り出した値と
      _LOWER（0x02）の間でビット論理積（
          &）を行っています。これが正しく動くためには、配列のその位置に「あらかじめ
      0x02 が含まれている」必要があります。

      これを踏まえて、各位置（文字）がどのフラグを持つべきかを計算します。教科書の23
      .5節（または各関数の定義）を元に判定します。

      1. position 9 （水平タブ \t）
      水平タブは「コントロール文字（制御文字）」であり、同時に「空白文字（スペース・タブなど）」です。

      該当するフラグ : _CONTROL(0x08) と _SPACE(0x20)

                           値 : 0x08 |
                       0x20 =
        0x28

        2. position 32 （スペース文字
        ' '）
スペースは「印刷可能な文字（グラフィック文字ではない）」であり、「空白文字」であり、さらに1文字のスペースそのものを指す
        _BLANK にも該当します。

        該当するフラグ : _SPACE(0x20) と _BLANK(0x80)

                             値 : 0x20 |
                         0x80 =
            0xA0

            3. position 65 （大文字
            'A'） 'A'
は「大文字」であり、同時に「16進数の数字（A〜F）」でもあります。

            該当するフラグ
    : _UPPER(0x01) と _HEX(0x40)

          値 : 0x01 |
      0x40 = 0x41

             4. position 94 （記号
             '^'） '^'
はアルファベットでも数字でもないため、「区切り文字・記号（punctuation）」に該当します。

             該当するフラグ
    : _PUNCT(0x10)

          値 : 0x10

      (c)配列を使用するメリット あなたの回答 by
      using array the calculation is once
      and
      fast.（配列を使うことで計算が1回で済み、速い）

              講師の解説と修正
              大正解です。まさにその通りです。これをさらに専門的な言葉で補強します。

              もし配列を使わずにマクロを組もうとすると、前の問題にあった(
                  (c) >= 'a' && (c) <= 'z')
                  のように、複数の比較演算や論理演算が必要になります。
              しかし、配列（参照テーブル
              / Lookup
              Table）を用意しておけば、「配列の添え字としてアクセスする（_ctype
                  [c]）＋ 1回のビット演算（
&）」という極めて少ないCPU命令だけで、どんな文字の判定も一瞬で終わらせることができます。

          さらに、前の問題で解説した「引数 c
          がマクロ内で1回しか評価されないため、islower(*p++)
              のような副作用（Side
          Effect）によるバグが起きない」という、安全面での決定的なメリットも含まれます。

          清書されたベストな回答例
          もし試験やノートにまとめる際は、以下のように表現すると完璧です。

          (a)
To avoid name conflicts with identifiers defined by the programmer. The C
standard reserves identifiers starting with an underscore followed by an
uppercase letter for library internal use.
（プログラマが定義する識別子との衝突を避けるため。Cの標準規格は、アンダースコアに大文字が続く識別子をライブラリの内部利用向けに予約している。）

(b)
The array contains bitwise ORed flags representing the characteristics of each
character.
（配列には、各文字の特性を表すフラグをビット論理和した値が含まれる。）

Position 9 (\t): 0x28 (_CONTROL | _SPACE)

Position 32 (' '): 0xA0 (_SPACE | _BLANK)

Position 65 ('A'): 0x41 (_UPPER | _HEX)

Position 94 ('^'): 0x10 (_PUNCT)

(c)
It is highly efficient because character classification requires only a single
array lookup and a bitwise AND operation. Additionally, it ensures safety
because the argument c is evaluated exactly once, avoiding bugs caused by side
effects (e.g., *p++).
（配列の参照と1回のビット論理積だけで文字判定ができるため極めて高速である。さらに、引数
c
がちょうど1回しか評価されないため、副作用によるバグを防ぐことができ安全である。）

ビット演算と配列を組み合わせたこの「テーブル参照」は、C言語の低レイヤ（コンパイラやOSの内部）で頻出する非常に美しいアルゴリズムですので、ぜひ仕組みを整理してみてください。*/
