/* C Programming A Modern Approach pp7-01.c
 * 2025-11-16 revisited 2026-04-12
 *
 * The square2.c program of Section 6.3 will fail (usually by printing
 * strange answers) if i * i exceeds the maximum int value. Run the
 * program and determie the smallest value of n that causes failure.
 * Try changing the type of i to short and running the program again.
 * (Don't forget to update the conversion specifications in the call
 * of printf!) Then try long. From these experiments, what can you
 * conclude about the number of bits used to store integer types on
 * your machine? */

/* C Programming A Modern Approach square2.c
 * 2025-10-28
 */

#include <stdio.h>

int main(void) {
  int i, n;

  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++)
    printf("%10d%10d\n", i, i * i);

  return 0;
}
