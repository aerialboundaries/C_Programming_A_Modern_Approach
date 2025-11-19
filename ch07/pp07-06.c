/* C Programmming A Modern Approach pp07-06.c
 * 2025-11-19
 *
 * Write a program that prints the values of sizeof(int),
 * sizeof(short), sizeof(long), sizeof(float), sizeof(double)
 * and sizeof(long double).
 */

#include <stdio.h>

int main(void) {
  printf("size of int: %zu\n", sizeof(int));
  printf("size of short: %zu\n", sizeof(short));
  printf("size of long: %zu\n", sizeof(long));
  printf("size of float: %zu\n", sizeof(float));
  printf("size of double: %zu\n", sizeof(double));
  printf("size of long double: %zu\n", sizeof(long double));
  return 0;
}
