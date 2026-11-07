/* C Programming A Modern Approach
 * pp-12-07.c
 * 2026-02-25, 2026-11-07
 *
 * Modify the maxmin.c program of Section 11.4 so that max_min fuction uses a
 * pointer instead of integer to keep track of the current position in the
 * array.
 */

/**************************************************************************
 * Finds the largest and smallest elements in an array                     *
 **************************************************************************/

#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);

int main(void)
{
  int b[N], i, big, small;

  printf("Enter %d numbers: ", N);
  for (i = 0; i < N; i++)
    scanf("%d", &b[i]);

  max_min(b, N, &big, &small);

  printf("Largest: %d\n", big);
  printf("Smallest: %d\n", small);

  return 0;
}

void max_min(int a[], int n, int *max, int *min)
{
  int *cur = a;

  *max = *min = *cur;
  for (; cur < a + n; cur++) {
    if (*cur > *max)
      *max = *cur;
    else if (*cur < *min)
      *min = *cur;
  }
}
