/* C Programming A Modern Approach ex6-03.c
 * 2025-10-30
 *
 * What output does the follwoing for statement produce?
 *
 * for(i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
 * printf("%d ", i);
 *
 * My Answer: 5 4 3 2 */

#include <stdio.h>

int main(void) {
  int i, j;
  for (i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
    printf("%d ", i);
}
