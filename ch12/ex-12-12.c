/* C Programming A Modern Approach
 * ex-12-12.c
 * 2026-02-17
 *
 * Write the following function:
 * void find_two_largest(const int *a, int n, int *largest, int
 * *second_largest);
 *
 * a points to an array of length n. The function searches the array for its
 * largest and second largest elements, storing then in the variables pointed to
 * by largest and second_largenst, respectively. Use pointer arithmetic --not
 * subscripting-- to visit array elements.
 */

void find_two_largest(const int *a, int n, int *largest, int *second_largest) {
  // In case elements < 2
  if (n < 2) {
    if (n == 1)
      *largest = *second_largest = *a;
    return;
  }

  const int *p = a;

  if (*p > *(p + 1)) {
    *largest = *p;
    *second_largest = *(p + 1);
  } else {
    *largest = *(p + 1);
    *second_largest = *p;
  }

  for (p = a + 2; p < a + n; p++) {
    if (*p > *largest) {
      *second_largest = *largest;
      *largest = *p;
    } else if (*p > *second_largest)
      *second_largest = *p;
  }
}
