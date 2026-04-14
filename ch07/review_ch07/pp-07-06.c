/* C Programmming A Modern Approach pp07-06.c
 * 2025-11-19 revisit 2026-04-13
 *
 * Write a program that prints the values of sizeof(int),
 * sizeof(short), sizeof(long), sizeof(float), sizeof(double)
 * and sizeof(long double).
 */

#include <stdio.h>

int main(void) {
  int i = 0;
  int short s = 0;
  long int l = 0;
  float f = 0;
  double d = 0;
  long double ld = 0;

  printf("Size of int: %zu\n", sizeof(i));
  printf("Size of short int: %zu\n", sizeof(s));
  printf("Size of long int: %zu\n", sizeof(l));
  printf("Size of float: %zu\n", sizeof(f));
  printf("Size of double: %zu\n", sizeof(d));
  printf("Size of long double: %zu\n", sizeof(ld));

  return 0;
}
