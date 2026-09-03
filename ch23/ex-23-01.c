/*
Extend the round nearest function so that it rounds a floating-point number x to n dig-
its after the decimal point. For example, the call round_nearest (3.14159, 3) would
return 3.142. Hint: Multiply x by 10^n", round to the nearest integer, then divide by 10^n".
Be sure that your function works correctly for both positive and negative values of x.

double round_nearest(double x)
{
    return x < 0.0 ? ceil(x - 0.5) : floor(x + 0.5);
}

My Answer:
double round_nearest2(double x, double n)
{
    return x < 0.0 ? ceil((x * pow(10.0, n) - 0.5)) / pow(10.0, n) : floor((x * pow(10.0, n)) + 0.5) / pow(10.0, n);
}

KN Answer:
double round_nearest(double x, int n)
{
  double power = pow(10.0, n);

  if (x < 0.0)
    return ceil(x * power - 0.5) / power;
  else
    return floor(x * power + 0.5) / power;
}

*/
