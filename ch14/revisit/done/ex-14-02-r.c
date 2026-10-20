/* C Programming A Modern Approach
 * ex-14-02.c
 * 2026-03-15
 *
 * Write a macro NELEMS(a) that computes the number of elements in a
 * one-dimensional array a. Hint See the discussionof the sizeof operator in
 * Section 8.1.
 */

#include <stdio.h>

#define NELEMS(a) ((int)(sizeof(a) / sizeof(a[0])))

int main(void)
{
  int a[] = { 1, 2, 3, 4, 5 };
  printf("Number of elements = %d\n", NELEMS(a));

  return 0;
}
