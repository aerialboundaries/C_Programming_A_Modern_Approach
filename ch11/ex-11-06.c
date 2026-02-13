/* C Programming A Modern Approach
 * ex-11-06.c
 * 2022-02-12
 *
 * Write the following function:
 *
 * void find_two_largest(int a[], int n, int *largest, int *second_largest);
 *
 * When passed an array a of length n, the function will search for its
 * largest and second-largest elements, storing them in the variables pointed
 * to by largest and secon_largest, respectively.
 */

void find_two_largest(int a[], int n, int *largest, int *second_largest) {
  int i;

  if (a[0] > a[1]) {
    *largest = a[0];
    *second_largest = a[1];
  } else {
    *largest = a[1];
    *second_largest = a[0];
  }

  for (i = 2; i < n; i++)
    if (a[i] > *largest) {
      *second_largest = *largest;
      *largest = a[i];
    } else if (a[i] > *second_largest)
      *second_largest = a[i];
}
