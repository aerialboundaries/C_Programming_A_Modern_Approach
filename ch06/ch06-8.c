/* C Programming A Modern Approach ex6-8.c
 * 2025-11-04
 *
 * What output does the following for statement produce?
 *
 * for (i = 10; i >= 1; i /= 2)
 *   printf("%d ", i++);
 *
 * My Answer: 5 3 2 1  -- Wrong
 * Correct  : 10 5 3 1 infinit loop
 */

#include <stdio.h>

int main(void) {
  for (int i = 10; i >= 1; i /= 2)
    printf("%d ", i++);

  return 0;
}
