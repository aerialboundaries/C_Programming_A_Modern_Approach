/* (C99) Write a program that converts a complex number in Cartesian coordinates
to polar form.The user will enter a and b(the real and imaginary parts of the
number); the program will display the values of r and θ.
*/

#include <math.h>
#include <stdio.h>

#define PI 3.14

void polar(double a, double b)
{
  double r, theta;
  r = hypot(a, b);
  theta = atan2(b, a);
  printf("r = %f, theta = %f rad\n", r, theta);
}

int main(void)
{
  double a, b;
  printf("Enter a and b: ");
  scanf("%lf %lf", &a, &b);
  polar(a, b);

  return 0;
}
