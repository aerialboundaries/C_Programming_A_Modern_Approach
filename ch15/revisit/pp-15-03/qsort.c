#include <stdio.h>

#include "quicksort.h"

#define N 5

int main(void)
{
  int a[N] = { 54, 32, 299, 15, 508 };

  quicksort(a, 0, N - 1);

  for (int i = 0; i < N; i++)
    printf("%d ", a[i]);

  return 0;
}
