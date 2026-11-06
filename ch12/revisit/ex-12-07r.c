/* C Programming A Modern Approach
 * ex-12-07.c
 * 2026-02-16, 2026-11-05
 *
 * Write the following function:
 *
 * bool search(const int a[], int n, int key);
 *
 * a is an array to be serarched, n is the number of elements in the array,
 * and key is the search key. search should return true if key matches some
 * element of a, and false if it doesn't. Use pointer arithmetic - not
 * subscripting - to visit array elements.
 *
 */

#include <stdbool.h>
#include <stdio.h>

#define N 5

bool search(const int a[], int n, int key);

int main(void)
{
  int a[N] = { 12, 65, 22, 999, 3 };

  printf("Search result: %s\n", search(a, N, 999) ? "true" : "false");

  return 0;
}

bool search(const int a[], int n, int key)
{
  const int *p;

  for (p = a; p < a + n; p++) {
    if (*p == key) {
      return true;
    }
  }
  return false;
}
