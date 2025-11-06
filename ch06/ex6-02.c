/* C Programming A Modern Approach ex6-02.c
 *
 * 2025-10-30
 *
 * What output does the following program fragment produce?
 *
 * i = 9384;
 * do {
 * printf("d ", i);
 * i /= 10;
 * } while (i > 0);
 *
 * My Answer: 9384 938 93 9 */

#include <stdio.h>

int main(void) {
  int i = 9384;
  do {
    printf("%d ", i);
    i /= 10;
  } while (i > 0);
}
