/* C Programming A Modern Approach ex4-11.c
 * Show the output produced by each of the following program fragments.
 * Assume that i and j are int variables.
 *
 * (a) i = 5;
 *     j = ++i * 3 -2;
 *     printf("%d %d\n", i, j);
 *
 * (b) i = 5;
 *     j = 3 - 2 * i++;
 *     printf("%d %d\n", i, j);
 *
 * (c) i = 7
 *     j = 3 * i-- + 2;
 *     printf("%d %d\n", i, j);
 *
 * (d) i = 7;
 *     j = 3 + --i * 2;
 *     printf("%d %d\n", i, j);
 *
 * My Answers:
 * (a) 6 16
 * (b) 6 -7
 * (c) 6 23
 * (d) 6 15
 *
 * $ ./a.out
 *(a)  6 16
 *(b)  6 -7
 *(c)  6 23
 *(d)  6 15
 */

#include <stdio.h>

int main(void) {
  int i, j;

  i = 5;
  j = ++i * 3 - 2;
  printf("(a)  %d %d\n", i, j);

  i = 5;
  j = 3 - 2 * i++;
  printf("(b)  %d %d\n", i, j);

  i = 7;
  j = 3 * i-- + 2;
  printf("(c)  %d %d\n", i, j);

  i = 7;
  j = 3 + --i * 2;
  printf("(d)  %d %d\n", i, j);

  return 0;
}
