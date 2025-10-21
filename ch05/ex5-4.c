/* C Programming A Modern Approach ex5-4.c
 *
 * Write a single expression whose value is either -1, 0 or +1, depending on
 * whether i is less than, equal to, or greather than j, reepectively.
 *
 * The Answer : (i > j) - (i < j)
 */

#include <stdio.h>

int main(void) {
  int i, j;

  i = 1;
  j = 2; // i < j
  printf("i < j: i = %d, j = %d, value = %d\n", i, j, (i > j) - (i < j));

  i = 2;
  j = 1; // i > j
  printf("i > j: i = %d, j = %d, value = %d\n", i, j, (i > j) - (i < j));

  i = 1;
  j = 1; // i == j
  printf("i == j: i = %d, j = %d, value = %d\n", i, j, (i > j) - (i < j));

  return 0;
}
