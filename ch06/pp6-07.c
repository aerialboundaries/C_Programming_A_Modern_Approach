/* C Programming A Modern Approach
 * 2025-11-07
 *
 * Rearrange the square3.c program so that the for loop initializes i,
 * tests i, and increments i. Don't rewrite the prgram; in patcular,
 * don't use any multiplications.
 */

/* C Programming A Modern Approach square3.c
 *
 * Pirints a atable of squares using an odd mothod
 * 2025-10-28
 */

#include <stdio.h>

int main(void) {
  int n, odd, square;

  printf("This program prints a table of squares.\n");
  printf("Enter number of entires in table: ");
  scanf("%d", &n);

  odd = 3;
  for (int i = 1, square = 1; i <= n; odd += 2, ++i) {
    printf("%10d%10d\n", i, square);
    square += odd;
  }
  return 0;
}
