/* C Programming A modern Approach ex4-15.c
 * Q: Give the values of i and j after each of the following exressionstatements
 * has been execued. (Assume that i has the value 1 initially and j has the
 * value 2.)
 *
 *    (a) i += j;
 *    (b) i--;
 *    (c) i * j / i;
 *    (d) i % ++j;
 *
 * My Answers:
 *    (a) printf("i += j : %d %d\n", 3, 2);
 *    (b) printf("i-- : %d %d\n", 3, 2);
 *    (c) printf("i * j / i : %d %d\n", 2, 2);
 *    (d) printf("i % ++j : %d\n", 2, 0);

 $ ./a.out
i += j : 3 2
i-- : 2 2
i * j / i : 2 2
i % ++j : 2 3*
 *
 */
#include <stdio.h>

int main(void) {
  int i = 1, j = 2;
  i += j;
  printf("i += j : %d %d\n", i, j);
  i--;
  printf("i-- : %d %d\n", i, j);
  i *j / i;
  printf("i * j / i : %d %d\n", i, j);
  i % ++j;
  printf("i %% ++j : %d %d\n", i, j);

  return 0;
}
