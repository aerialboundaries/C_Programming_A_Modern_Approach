/* C Programming A Modern Approach
 * ex-14-07.c
 * 2026-03-17
 *
 * Let GENERIC_MAX be the following marcro:
 * #define GENERIC_MAX(type)              \
 * type type##_max(type x, type y)        \
 * {                                      \
 * return x > y ? x : y;                  \
 * }
 *
 * (a) Show the preprocessor's expansion of GENERIC_MAX(long).
 * (b) Explain why GENERIC_MAX doesn't work for basic types such as
 * unsigned long.
 * (c) Describe a technique that would allow us to use GENERIC_MAX
 * with basic types such as unsigned long. Hint: Don't change the
 * definition of GENERIC_MAX.
 */

#include <stdio.h>

#define GENERIC_MAX(type)                                                      \
  type type##_max(type x, type y) { return x > y ? x : y; }

typedef unsigned long ulong;

GENERIC_MAX(ulong)

int main(void) {
  printf("%ld\n", ulong_max(20, 30));

  return 0;
}

/*
 * (a) long long_max(long x, long y) {return x > y ? x: y;}
 * (b) it is expanded to unsigned long unsigned long_max(typex, type y)..
 *      the function name has space in it.
 * (c) typedef unsigned long ulong GENERIC_MAX(ulong));
 */
