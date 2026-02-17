/* C Programming A Modern Approach
 * ex-12-07.c
 * 2026-02-16
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

bool search(const int a[], int n, int key) {
  const int *p;
  for (p = a; p < a + n; p++)
    if (*p == key)
      return true;

  return false;
}
