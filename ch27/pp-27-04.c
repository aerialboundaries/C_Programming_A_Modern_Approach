/*
(C99) Write a program that displays the nth roots of unity when given a positive
integer n. The nth roots of unity are given by the formula e^2pi ik/n, where k
is an integer between 0 and n-1.
*/

#include <complex.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
  int n;

  printf("Enter a positive integer n: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Error: Please enter a valid positive integer.\n");
    return 1;
  }

  // 円周率 π の定義（acos(-1.0) を使うと高精度に得られます）
  double pi = acos(-1.0);
  double two_pi = 2.0 * pi;

  printf("The %d-th roots of unity are:\n", n);

  for (int k = 0; k < n; k++) {
    // 偏角の計算: 2 * pi * k / n
    double angle = two_pi * k / n;

    // オイラーの公式に基づいて複素数を計算 (e^(i * angle))
    double complex root = cexp(_Complex_I * angle);

    // 実部と虚部を取り出して表示
    // 浮動小数点の誤差で微小な非ゼロが出る場合があるため、綺麗に丸めることもできます
    printf("k = %d: %.4f + %.4fi\n", k, creal(root), cimag(root));
  }

  return 0;
}
