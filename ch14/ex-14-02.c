/* C Programming A Modern Approach
 * ex-14-02.c
 * 2026-03-15
 *
 * Write a macle NELEMS(a) that computes the number of elements in a
 * one-dimensional array a. Hint See the discussionof the sizeof operator in
 * Section 8.1.
 */
#include <stdio.h>

#define NELEMS(a) (sizeof(a) / sizeof(a[0]))

int main(void) {
  int a[] = {1, 2, 3, 4, 5};
  printf("size of array: %d", (unsigned int)NELEMS(a));
}
