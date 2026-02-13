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
  *largest = *second_largest = a[0];

  int temp;

  for (int i = 1; i < n; i++) {
    if (*largest < a[i]) {
      temp = *largest;
      *largest = a[i];
      *second_largest = temp;
    }
  }
}
