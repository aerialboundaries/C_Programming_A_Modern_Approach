/* C Programming A Modern Approach
 * ex-14-01.c
 * 2026-03-15
 *
 * Write paarameterized macros that complete the following values.
 * (a) The cube of x.
 * (b) The remainder when n is divided by 4.
 * (c) 1 if the product of x and y is less than 100, 0 otherwise.
 * Do you macros always word? If not, describe what armements would make them
 * fail.
 */

#include <stdio.h>

#define CUBE(x) ((x) * (x) * (x))                  //(a)
#define REMAINDER4(x) ((x) % 4)                    //(b)
#define PRODUCT(x, y) (((x) * (y)) <= 100 ? 1 : 0) // (c)

int main(void) {
  int x = 9, y = 12;
  printf("(a) %d\n", CUBE(x));
  printf("(b) %d\n", REMAINDER4(x));
  printf("(c) %d\n", PRODUCT(x, y));

  return 0;
}

// ++など副作用のある式でマクロを使うと意図しない結果になる。すべて危ない。
