/* C_programming A Modern Approach ex4-7.c
 *
 * Q: The algorithm for computing the UPC check digit ends with the following
 * steps:
 *
 * Substract 1 from the total.
 * Comppppute the remainder when the adjusted total is divided by 10.
 * subtract the remainder from 9.
 *
 * It's tempting to try to simplify the algorithm by using these steps instead:
 *
 * Compute the remiander when the total is divided by 10.
 * Subtract the remainder from 10.
 *
 * Why doesn't this techique work?
 *
 * My Answer: Because the check digit can take 0 to 10.  The check digit must be
 * 0 to 9.
 *
 * Gemini? はい、あなたの答えの核となる部分は正しいです。

なぜ簡略化されたアルゴリズムは機能しないのか
簡略化されたアルゴリズムが機能しない主な理由は、その処理によって計算される値が、チェックディジットとして許容されない
10 になる可能性があるからです。

1. 元のアルゴリズム（正しい方法）
元のアルゴリズムでは、最終的なチェックディジット C は必ず 0 から 9
の範囲に収まることが保証されます。

調整前の合計 T がある。

T
′
 =T−1 （1を引く）

剰余 R=T
′
 (mod10) （調整後の合計を10で割った余り）

チェックディジット C=9−R

ここで、T
′
 (mod10) の結果 R は常に 0 から 9 です。したがって、C=9−R の結果は必ず 9−9=0
から 9−0=9 の範囲に収まります。

2. 簡略化されたアルゴリズム（誤った方法）
簡略化されたアルゴリズムでは、合計 T が 10 の倍数である場合に問題が発生します。

合計 T がある。（例: T=30）

剰余 R=T(mod10)

チェックディジット C=10−R

問題のケース（T が 10 の倍数、例: T=30）:

剰余 R=30(mod10)=0

チェックディジット C=10−0=10

チェックディジットは**一桁の数字（0 から 9）**でなければなりません。10
は二桁であるため、UPCとして無効です。

3. あなたの答えとの関連
あなたの答え「Because the check digit can take 0 to 10. The check digit must be
0
to 9.」は、この核心（チェックディジットが10になる可能性がある）を正確に指摘しています。

元のアルゴリズムは、最初に T から 1 を引くことで、実質的に T が 10
の倍数であった場合でも、最終結果が 9−(T−1)(mod10) の結果として必ず 0
になるように調整しているのです。
 */
