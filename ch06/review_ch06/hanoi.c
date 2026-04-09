#include <stdio.h>

/*
 * ハノイの塔を解く再帰関数
 * n     : 円盤の枚数
 * from  : 移動元の杭の名前
 * to    : 移動先の杭の名前
 * aux   : 補助（一時避難先）の杭の名前

 */
void hanoi(int n, char from, char to, char aux) {
  if (n == 1) {
    // 円盤が1枚なら、そのまま移動元から移動先へ

    printf("円盤 1 を %c から %c へ移動\n", from, to);
    return;
  }

  // 1. 上の n-1 枚を from から aux へ移動させる（toを補助として使う）
  hanoi(n - 1, from, aux, to);

  // 2. 一番下の円盤（n枚目）を from から to へ移動させる
  printf("円盤 %d を %c から %c へ移動\n", n, from, to);

  // 3. aux に避けていた n-1 枚を aux から to
  // へ移動させる（fromを補助として使う）
  hanoi(n - 1, aux, to, from);
}

int main(void) {

  int n = 3; // 円盤の枚数（まずは3枚で試すのがおすすめ）

  printf("%d枚の円盤を移動させる手順:\n", n);
  hanoi(n, 'A', 'C', 'B'); // A杭からC杭へ、Bを補助に使って移動

  return 0;
}
