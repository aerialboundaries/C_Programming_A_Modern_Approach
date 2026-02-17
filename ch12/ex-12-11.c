/* C Programming A Modern Approach
 * ex-12-11.c
 * 2026-02-16
 *
 * Modify the find_largest function so that it uses pointer arithmetic
 * --not sbscripting -- to visit array elements.
 *
 * int find_largest(int a[], int n)
 * {
 *    int i, max;
 *    max = a[0];
 *    for (i = 1; i < n; i++)
 *        if (a[i] > max)
 *          max = a[i];
 *    return max;
 * }
 */

int find_largest(int a[], int n) {
  int i, max;
  max = *a;
  for (i = 1; i < n; i++)
    if (*++a > max)
      max = *a;
  return max;
}
