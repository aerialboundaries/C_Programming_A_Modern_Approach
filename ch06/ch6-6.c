/* C Programming A Modern Approach ex6-6.c
 * 2025-11-5
 *
 * Translate the program fragment of Exercise 1 into a single
 * for statement.
 */

#include <stdio.h>

int main(void) {
  for (int i = 1; i <= 128; i *= 2)
    printf("%d ", i);

  return 0;
}
