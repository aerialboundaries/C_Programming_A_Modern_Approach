/*
(C99) Write a program that converts a complex number in polar
coordinates to Cartesian form.After the user enters the values of r and θ,
the program will display the number in the form a + bi,
where

    a = r cos θ
    b = r sin θ
*/

#include <math.h>
#include <stdio.h>

void cartesian(double r, double theta)
{
  double a, b;

  // 直交座標の成分を計算
  a = r * cos(theta);
  b = r * sin(theta);

  // 結果を表示 (形式: a + bi)
  // 虚部が負の場合の表示（例: 3 - 2i
  // など）を綺麗にするための配慮もできますが、まずは基本の形にします
  printf("Cartesian form: %.2f + %.2fi\n", a, b);
}

int main(void)
{
  double r, theta;

  printf("Enter r and theta (in radians): ");
  if (scanf("%lf %lf", &r, &theta) == 2) {
    cartesian(r, theta);
  } else {
    printf("Invalid input.\n");
  }

  return 0;
}
