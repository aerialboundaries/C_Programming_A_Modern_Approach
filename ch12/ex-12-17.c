/* C Programming A Modern Approach
 * ex-12-17.c
 * 2026-02-18
 *
 * Rewrite the following function to use pointer arithmetic instead of
 * of array subscripting. (In other words, eliminate the variables
 * i and j and all uses of the [] operator.) Use a single loop instead
 * of nested loops.
 *
 * int sum_two_dimensional_array (const int a[][LEN], int n)
 * {
 *    int i, j, sum = 0;
 *    for (i = 0; i < n; i++)
 *      for (j = 0; j < LEN; j++)
 *         sum += a[i][j];
 *    return sum;
 * }
 *
 */
#include <stdio.h>

#define LEN 5

int sum_two_dimensional_array(const int a[][LEN], int n);

int main(void) {
  int a[][LEN] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};

  printf("Sum of elements: %d\n", sum_two_dimensional_array(a, 3));

  return 0;
}

int sum_two_dimensional_array(const int a[][LEN], int n) {
  int i, j, sum = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < LEN; j++)
      sum += a[i][j];
  return sum;
}
