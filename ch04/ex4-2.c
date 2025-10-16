/*
 * C Programming A Modern Approach ex4-2.c
 *
 * Q: If i and j are positive integers, does (-i)/j always have the same value
 * as -(i/j)?  Justify your answer.
 *
 * My answer : Yes
 *
 * KN's answer :  Not in C89. Suppose that i is 9 and j is 7. The value of
 * (-i)/j could be either –1 or –2, depending on the implementation. On the
 * other hand, the value of -(i/j) is always –1, regardless of the
 * implementation. In C99, on the other hand, the value of (-i)/j must be equal
 * to the value of -(i/j).
 *
 */

#include <stdio.h>

int main(void) {
  int i, j;
  i = 9;
  j = 3;

  printf("(-i)/j : %d\n", (-i) / j);
  printf("-(i/j) : %d\n", -(i / j));

  return 0;
}
