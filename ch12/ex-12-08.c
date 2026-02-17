/* C Programming A Modern Approach
 * ex-12-08.c
 * 2026-02-16
 *
 * Rewrite the following function to use pointer arithmetic instead of array
 * subscripting. (In other words, eliminate the valiralble i and all usees of
 * the
 * [] operator.) Make as few changes as possible.
 *
 * void sotre_zeros(int a[], int n)
 * {
 * int i;
 * for (i = 0; i < n; i++)
 *   a[i] = 0;
 * }
 *
 */
void sotre_zeros(int *a, int n) {
  int *p;
  for (p = a; p < a + n; p++)
    *p = 0;
}
