/* C Programming A odern Approach
 * ex-11-08.c
 * 2026-02-13 2026-11-03
 *
 * Write the following function:
 *
 * int *find_largest(int a[], int n);
 *
 * When passed an array a of length n, the fuction will return a pointer
 * to the array's largest element.
 */

int *find_largest(int a[], int n)
{
  int *largest = &a[0];

  for (int i = 1; i < n; i++) {
    if (a[i] > *largest)
      largest = &a[i];
  }
  return largest;
}
