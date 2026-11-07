/* C Programming A Modern Approach
 * pp-12-06.c
 * 2026-02-25, 2026-11-07
 *
 * Modify the qsort.c program of Section 9.6 so that low, high and middle are
 * pointers to array elements rather than integers. The split function will need
 * to return a pointer, not an integer.
 */

/* Sorts an array of integers using Quicksort algorithm */

#include <stdio.h>

#define N 10

void quicksort(int a[], int *low, int *high);
int *split(int a[], int *low, int *high);

int main(void)
{
  int a[N] = { 3, 14, 22, 9, 66, 33, 100, 6, 65, 333 };
  int *low = &a[0], *high = &a[N - 1];
  quicksort(a, low, high);

  int i;
  for (i = 0; i < N; i++) {
    printf("%4d", a[i]);
  }

  putchar('\n');

  return 0;
}

void quicksort(int a[], int *low, int *high)
{
  int *middle;
  if (low >= high)
    return;

  middle = split(a, low, high);

  quicksort(a, low, middle - 1);
  quicksort(a, middle + 1, high);
}

int *split(int a[], int *low, int *high)
{
  int part_element = *low;

  for (;;) {
    while (low < high && part_element <= *high)
      high--;
    if (low >= high)
      break;
    *low++ = *high;

    while (low < high && *low <= part_element)
      low++;
    if (low >= high)
      break;
    *high-- = *low;
  }

  *high = part_element;
  return high;
}
