/*
(C99) Make the following modifications to the quadratic.c program of
Section 27.4:

(a) Have the user enter the coefficients of the polynomial (the values of the
variables a, b, and c).

(b) Have the program test the discriminant before displaying the values of the
roots. If the discriminant is negative, have the program display the roots in
the same way as before. If it's nonnegative, have the program display the roots
as real numbers (without an imaginary part). For example, if the quadratic
equation is x^2 + x - 2 = 0, the output of the program would be

root1 = 1
root2 = -2

(c) Modify the program so that it displays a complex number with a negative
imaginary part as a - bi instead of a + -bi. For example, the output of the
program with the original coefficients would be

root1 = -0.2 + 0.4i
root2 = -0.2 - 0.4i
*/

/* Finds the roots of the equation 5x**2 + 2x + 1 = 0 */

#include <complex.h>
#include <stdio.h>
#include <tgmath.h>

int main(void)
{
  double a, b, c;
  printf("Enter coefficients (ex: 5 2 1)\n");
  scanf("%lf %lf %lf", &a, &b, &c);

  double disc = b * b - 4 * a * c;
  if (disc >= 0) {
    double root1 = (-b + sqrt(disc)) / (2.0 * a);
    double root2 = (-b - sqrt(disc)) / (2.0 * a);
    printf("root1 = %g\n", root1);
    printf("root2 = %g\n", root2);
  } else {
    double complex discriminant_sqrt = csqrt(b * b - 4 * a * c);
    double complex root1 = (-b + discriminant_sqrt) / (2.0 * a);
    double complex root2 = (-b - discriminant_sqrt) / (2.0 * a);

    double im1 = cimag(root1);
    double im2 = cimag(root2);

    if (im1 < 0) {
      printf("root1 = %g - %gi\n", creal(root1), -im1);
    } else {
      printf("root1 = %g + %gi\n", creal(root1), im1);
    }

    if (im2 < 0) {
      printf("root2 = %g - %gi\n", creal(root2), -im2);
    } else {
      printf("root2 = %g + %gi\n", creal(root2), im2);
    }
  }

  return 0;
}
