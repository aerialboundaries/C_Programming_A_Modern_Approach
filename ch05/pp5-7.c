/* C Programmign A Modern Approach pp5-7.c
 *
 * Wirte a program that finds the largest and smallest of forur integers entered
 * by the user:
 *
 * Enter for ingegers: 21 43 10 35
 * Largest: 43
 * Smallest: 10
 *
 * Use as few if statements as possilbe.
 * Hint : Four if statements are sufficient.
 */

#include <stdio.h>

int main(void) {
  int i1, i2, i3, i4, max, min;

  printf("Enter four integers : ");
  scanf("%d%d%d%d", &i1, &i2, &i3, &i4);

  if (i1 > i2) {
    max = i1;
    min = i2;
  } else {
    max = i2;
    min = i1;
  }

  if (max > i3)
    max = max;
  else
    max = i3;

  if (min < i3)
    min = min;
  else
    min = i3;

  if (max > i4)
    max = max;
  else
    max = i4;

  if (min < i4)
    min = min;
  else
    min = i4;

  printf("Largest: %d\n", max);
  printf("Smallest: %d\n", min);

  return 0;
}

/* ご提示のコードと課題、拝見しました！「if文を可能な限り少なくする」という制約は、いかに効率よくロジックを組むかというC言語の基礎力を試す、とても良い問題ですね。

現在のコードは、最初の2つの整数 (i1, i2) で max と min
を初期化し、残りの2つの整数 (i3, i4) に対してそれぞれ max と min
を更新する、というロジックです。

現在の if 文の数は以下の通りです。

初期化：i1 と i2 を比較する if/else (1つの if と見なせます)

i3 の比較：max の更新 (1つ)

i3 の比較：min の更新 (1つ)

i4 の比較：max の更新 (1つ)

i4 の比較：min の更新 (1つ)

合計で 5つの if 文（または if/else ブロック）がありますね。

目標は、これを4つに減らすことですね！

🚀 if 文を4つに減らす方法：三項演算子を活用
この問題を解決する最もエレガントな方法は、C言語特有の三項演算子 (? :)
を使うことです。三項演算子は、単純な条件分岐と代入を1行で記述できるため、if/else
の代わりとして非常に有効です。

三項演算子 (? :) の基本
C

(条件) ? (条件が真のときの値) : (条件が偽のときの値)
修正案（if文4つ）
i3 と i4 の更新で冗長になっていた部分を、三項演算子を使って簡潔に書き換えます。
Largest and Smallest of Four Integers (4 Ifs)
10月24日 2:58

開く

比較：なぜ4つで済むのか
元のコードでは、if (max > i3) max = max; else max = i3;
のように、値が変わらない場合でも if 文を完全に使っていました。

三項演算子を使った場合 (max = (i3 > max) ? i3 : max;)

i3 が現在の max より大きければ、max の新しい値として i3 を選びます。

そうでなければ（i3 が max 以下であれば）、max
の現在の値（max）をそのまま選びます。

このように、三項演算子を使うことで、更新が必要な時だけ代入するロジックを、if
文を使わずに（あるいは if
の同等機能として）1行で、しかもヒントの通り4つの条件分岐で実現できています。

別の4つに減らす解釈（最大値と最小値を同時に比較）
もし、初期化 (i1 vs i2) を2つの if に分けず、残り3つの数値をそれぞれ2つの if
文で処理するという方法を取ると、以下のように4つの if
文で実現することも可能です。

C

// i1とi2の比較を if/else で1つと見なす
if (i1 > i2) { max = i1; min = i2; } else { max = i2; min = i1; } // (1)
// i3の比較を max/min 2つではなく、一つのifで処理
if (i3 > max) max = i3; else if (i3 < min) min = i3; // (2)
// i4の比較を max/min 2つではなく、一つのifで処理
if (i4 > max) max = i4; else if (i4 < min) min = i4; // (3)
// 合計3つ。これでは少なすぎる。

// 結局、ヒントが求める「4つのif文」を満たすには、
// 初期化(1) + i3の最大更新(1) + i4の最大更新(1) + i4の最小更新(1)
// のように、三項演算子で簡潔に記述するのが最も自然な方法となります。

C言語では、三項演算子はコードを簡潔にする非常に強力なツールです。ぜひ活用してくださいね！*/
