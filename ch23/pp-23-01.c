/*

Write a program that finds the roots of the equation ax2 + bx +c =0 using the formula

-b±b2-4ac
2a

Have the program prompt for the values of a, b, and c, then print both values of x. (If b2 -
4ac is negative, the program should instead print a message to the effect that the roots are
complex.)

*/

#include <math.h>
#include <stdio.h>

int main(void) {
  double a, b, c;
  double x1, x2, discriminant;

  printf("input a, b, c (ex 1, 5, 4) : ");
  while (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
    fprintf(stderr, "wrong input. Retry. :");

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
      ;
    }
  }

  if (a == 0.0) {
    printf("a cannot be \n");
    return 1;
  }

  discriminant = b * b - 4.0 * a * c;
  if (discriminant < 0) {
    printf("the roots are complex");
    return 0;
  }

  x1 = (-b + sqrt(discriminant)) / (2.0 * a);
  x2 = (-b - sqrt(discriminant)) / (2.0 * a);

  printf("x = %4.2f and %4.2f\n", x1, x2);

  return 0;
}
