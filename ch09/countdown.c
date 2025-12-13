/* C Programming A Modern Approach
 * countdown.c
 * 2025-12-12 */

/* Prints a count down */

#include <stdio.h>

void print_count(int n) { printf("T minus %d and countiing\n", n); }

int main(void) {
  int i;

  for (i = 10; i > 0; --i)
    print_count(i);

  return 0;
}
