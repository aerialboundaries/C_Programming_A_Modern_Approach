/*
 (C99) Write the following function:
double evaluate_polynomial (double a[], int n, double x) ;
The function should return the value of the polynomial anx^n + " + ... + ao, where the
a's are stored in corresponding elements of the array a, which has length n + 1. Have the
function use Horner's Rule to compute the value of the polynomial:
(( ... ((a,x + an 1)x + an2)x + ... )x + aj)x + ao
Use the fma function to perform the multiplications and additions.

My Answer:

double evaluate_polynomial (double a[], int n, double x)
{
  double result = a[n];
  for (int i = n - 1; i >= 0; i--) {
    result = fma(result, x, a[i]);
  }
  return result;
}
*/
