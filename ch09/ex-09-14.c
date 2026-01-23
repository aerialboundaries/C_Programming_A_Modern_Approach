/* C Programming A Modern Approach
 * ex-09-14.c
 * 2026-01-23
 *
 * The following function is supposed to return true if any element of the array
 * a has the value 0 and false if all element are nonzero. Sadly, it contains
 * an error. Find the error and show how to fix it.
 *
 * bool has_zero(int a[], int n)
 * {
 *    int i;
 *
 *    for (i = 0; i < n; i++)
 *      if (a[i] == 0)
 *        return true;
 *      else
 *        return false;
 * }
 *
 * My Answer */
bool has_zero(int a[], int n) {
  int i;

  for (i = 0; i < n; i++)
    if (a[i] == 0)
      return true;
  return false;
}
