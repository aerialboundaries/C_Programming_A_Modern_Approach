/*
Write a function that returns a random double value d in the range 0.0 ≤d < 1.0.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double rd_double(void) { return ((double)rand() / ((double)RAND_MAX + 1.0)); }

int main(void)
{
  srand((unsigned)time(NULL));
  printf("%f\n", rd_double());

  return 0;
}
