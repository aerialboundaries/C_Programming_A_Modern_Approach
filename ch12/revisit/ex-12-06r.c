/* C Programming A Modern Approach
 * ex-12-06.c
 * 2026-02-16, 2026-11-06
 *
 * Rewrite the following function to use pointer arithmetic instead of array
 * subscripting. (In other words, eliminate the variable i and uses of the []
 * operator.) Make as few changes as possible.
 *
 * int sum_array(const int a[], int n)
 * {
 *    int i, sum;
 *    sum = 0;
 *    for (i = 0; i < n; i++)
 *      sum += a[i];
 *    return sum;
 * }
 *
 */

int sum_array(const int a[], int n)
{
  const int *p;
  int sum;
  sum = 0;
  for (p = a; p < a + n; p++)
    sum += *p;
  return sum;
}
