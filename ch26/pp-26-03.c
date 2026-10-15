/*
Write a program that uses the clock function to measure how long it takes qsort
to sort an array of 1000 integers that are originally in reverse order. Run the
program for arrays of 10000 and 100000 integers as well.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

int compare_ints(const void *p, const void *q) { return *(int *)p - *(int *)q; }

int main(void)
{
  int a[N];
  clock_t start_clock;

  for (int i = 0; i < N; i++)
    a[i] = N - i;

  start_clock = clock();
  qsort(a, N, sizeof(a[0]), compare_ints);
  printf("Time used to sort %d integers: %g sec.\n", N,
         (clock() - start_clock) / (double)CLOCKS_PER_SEC);

  return 0;
}
