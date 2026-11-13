#include "quicksort.h"

void quicksort(int a[], int low, int high)
{
  if (low >= high)
    return;

  int middle;
  middle = split(a, low, high);

  quicksort(a, low, middle - 1);
  quicksort(a, middle + 1, high);
}

int split(int a[], int low, int high)
{

  int pivot = a[low];

  for (;;) {
    while (low < high && a[high] >= pivot) {
      high--;
    }
    if (low >= high)
      break;

    a[low++] = a[high];

    while (low < high && a[low] <= pivot) {
      low++;
    }
    if (low >= high)
      break;

    a[high--] = a[low];
  }
  a[high] = pivot;
  return high;
}
