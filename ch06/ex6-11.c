/* C Programming A Modern Approach ex6-11.c
 * 2025-11-05
 *
 * What output does the following program fragent produce?
 *
 * sum = 0;
 * for (i = 0; i < 10; i++) {
 * if (i % 2)
 * continue;
 * sum += 1;
 * }
 * printf("%d\n", sum);
 *
 * My Answer: 5
 */

#include <stdio.h>

int main(void) {
  int i = 0, sum = 0;
  for (i = 0; i < 10; i++) {
    if (i % 2)
      continue;
    sum += 1;
  }
  printf("%d\n", sum);
}
