/* C Programming A Modern Approach ex4-11.c
 *
 * Q: Show the output produced by each of the following program fragments.
 * Assume the i, j, and k are int variables.
 *
 * (a) i = 1;
 * printf("%d ", i++ - 1);
 * printf("%d", i);
 *
 * (b) i = 10; j = 5;
 * printf("%d ", i++ - ++j);
 * printf("%d %d", i, j);
 *
 * (c) i =7; j = 8;
 * printf("%d ", i++ - --j);
 * printf("%d %d", i, j);
 *
 * (d) i = 3; j = 4; k = 5;
 * printf("%d ", i++ - j++ + --k);
 * printf("%d %d %d", i, j, k);
 *
 *
 * My Answers:
 * (a)  0
 *      2
 *
 * (b)  4
 *      11 6
 *
 * (c)  0
 *      8 7
 *
 * (d)  3
 *      4 5 4
 *
 *
 *  compliled Answer
 * (a)     0
 *         2
 *
 * (b)     4
 *        11 6
 *
 * (c)     0
 *         8 7
 *
 * (d)     3
 *         4 5 4
 *
 */

#include <stdio.h>

int main(void) {
  int i, j, k;

  i = 1;
  printf("(a)\t%d \n", i++ - 1);
  printf("\t%d\n", i);

  i = 10;
  j = 5;
  printf("(b)\t%d \n", i++ - ++j);
  printf("\t%d %d\n", i, j);

  i = 7;
  j = 8;
  printf("(c)\t%d \n", i++ - --j);
  printf("\t%d %d\n", i, j);

  i = 3;
  j = 4;
  k = 5;
  printf("(d)\t%d \n", i++ - j++ + --k);
  printf("\t%d %d %d\n", i, j, k);

  return 0;
}
