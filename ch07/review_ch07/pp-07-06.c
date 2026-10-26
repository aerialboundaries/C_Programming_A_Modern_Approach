/* C Programmming A Modern Approach pp07-06.c
 * 2025-11-19 revisit 2026-04-13 2026-10-26
 *
 * Write a program that prints the values of sizeof(int),
 * sizeof(short), sizeof(long), sizeof(float), sizeof(double)
 * and sizeof(long double).
 */

#include <stdio.h>

int main(void)
{
  printf("Sizeof(int): %zu\n", sizeof(int));
  printf("Sizeof(short): %zu\n", sizeof(short));
  printf("Sizeof(long): %zu\n", sizeof(long));
  printf("Sizeof(float): %zu\n", sizeof(float));
  printf("Sizeof(double): %zu\n", sizeof(double));
  printf("Sizeof(long double): %zu\n", sizeof(long double));

  return 0;
}
