/* C Programming A Modern Approach ex4-13.c
 *
 * Q: Only one of the expressions ++i and i++ is exactly the same as (i += 1);
 *    which is it?  Justify your answer.
 *
 * My Answer:  ++i
 *
 * K.N.King Answer
 * The expression ++i is equivalent to (i += 1).
 * The value of both expressions is i after the increment has been performed.
 *
 * $ ./a.out
 * ++i : 2
 * i++ : 1
 * (i += 1) : 2
 */

#include <stdio.h>

int main(void) {
  int i = 1;
  printf("++i : %d\n", ++i);

  i = 1;
  printf("i++ : %d\n", i++);

  i = 1;
  printf("(i += 1) : %d\n", i += 1);

  return 0;
}
