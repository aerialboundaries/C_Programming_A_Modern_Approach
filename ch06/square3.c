/* C Programming A Modern Approach square3.c
 *
 * Pirints a atable of squares using an odd mothod
 * 2025-10-28
 */

#include <stdio.h>

int main(void) {
  int i, n, odd, square;

  printf("jhis program prints a table of squares.\n");
  printf("Enter number of entires in table: ");
  scanf("%d", &n);

  i = 1;
  odd = 3;
  for (square = 1; i <= n; odd += 2) {
    printf("%10d%10d\n", i, square);
    ++i;
    square += odd;
  }
  return 0;
}
