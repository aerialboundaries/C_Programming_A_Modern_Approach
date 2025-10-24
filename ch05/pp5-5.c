/* C Programming A Modern Approach pp5-5.c
 *
 * In one state, single residents are subject to the following income tax:
 *
 * Income         Amount of tax
 * Not over $750  1% of income
 * $750-$2,250    $7.50   plus 2% of amount over $750
 * $2,250-$3,750  $37.50  plus 3% of amount over $2,250
 * $3,750-%5,250  $82.50  plus 4% of amount over $3,750
 * $5,250-$7,000  $142.50 plus 5% of amount over $5,250
 * Over $7,000    $230.00 plus 6% of amount over $7,000
 *
 * Write a program that asks the user to enter the amount of taxable income,
 * then displays the tax due. */

#include <stdio.h>

int main(void) {
  int income;

  printf("Enter Income: ");
  scanf("%d", &income);

  if (income < 750)
    printf("Tax due = $%.2f", income * 0.01);
  else if (income < 2250)
    printf("Tax due = $%.2f", 7.5 + (income - 750) * .02);
  else if (income < 3750)
    printf("Tax due = $%.2f", 37.5 + (income - 2250) * .03);
  else if (income < 5250)
    printf("Tax due = $%.2f", 82.5 + (income - 3750) * .04);
  else if (income < 7000)
    printf("Tax due = $%.2f", 142.5 + (income - 5250) * .05);
  else
    printf("Tax due = $%.2f", 230 + (income - 7000) * .06);

  return 0;
}

/*C言語の所得税計算プログラム、拝見しました！複雑な税率計算を if-else if
構文で見事に表現できていますね。

はい、このコードは基本的な計算ロジックにおいては正しく、税率表の要件を満たしています。ロジックの組み立ても非常に優れています！

ただし、C言語のベストプラクティスと正確な金融計算という観点から、改善すべき点が2つあります。

🧐 評価と修正提案（金融計算の精度向上）
1. データ型の不一致（最も重要）
現在、入力である income は int (整数型)
で宣言されています。しかし、税額の計算（income * 0.01 や 7.5 +
...）には浮動小数点数（小数点以下を持つ数値）が使われています。

income が int だと、income - 750 も整数になります。

C言語では、整数同士の演算では結果も整数になりますが、今回のコードのように**片方が浮動小数点数（例:
0.01）**であれば、暗黙的に浮動小数点数での演算に昇格されるため、計算自体は問題ありません。

しかし、所得や税額のような金額を扱う場合、入力を最初から浮動小数点型で受け取る方が、より柔軟で厳密な計算に対応できます。

【修正案】

income の型を int から double (または float) に変更し、scanf の書式指定子を %d
から %lf (long float = double) に変更しましょう。

2. 入力エラー処理の追加
前回の質問でも触れたように、堅牢なプログラムでは scanf
の戻り値チェックが必須です。ユーザーが誤って数字ではないものを入力した場合に備えましょう。

✅ 修正後の全文コード
これらのベストプラクティスを適用した、より堅牢で正確な所得税計算プログラムがこちらです。
Income Tax Calculator
10月24日 0:29

開く

修正のポイント解説
double 型の採用:

int income; を double income; に変更しました。

scanf の引数を "%d" から "%lf" に変更しました。

税率テーブルの金額（例: 750 や 7.5）に .0
を付けて、全て浮動小数点リテラルとして扱うようにしました（例:
750.0）。これは可読性を高め、計算が常に double
で行われていることを明確にするためです。

if 条件の修正:

元のコードの if (income < 750) は、income が整数だったため $750 以下（750
を含む）を意味していました。

税率表では境界値（750,2250 など）が下の税率帯に含まれるため、income <= 750.0
のように、境界値を含む条件に修正しました。

この修正により、金額を扱うプログラムとして、より正確でプロフェッショナルなコードになりました。

税率の計算ロジックは完璧だったので、この調子でC言語の学習を続けてくださいね！😊

他にご希望の例題や、コードについて気になる点はありますか？
*/
