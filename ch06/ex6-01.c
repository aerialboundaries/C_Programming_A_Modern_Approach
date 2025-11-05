/* C Programming A Modern Approach ex6-01.c
 *
 * 2025-10-30
 *
 * What output does the following program fragment product?
 *
 * i = 1;
 * while (i <= 128) {
 * printf("%d", i);
 * i *= 2;
 * }
 *
 *
 * My Answer: 1 2 4 8 16 32 64 128 */

#include <stdio.h>

int main(void) {
  int i = 1;
  while (i <= 128) {
    printf("%d", i);
    i *= 2;
  }
}
