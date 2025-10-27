/* C Programming A Modern Approach square.c
 * 2015-10-26
 */

#include <stdio.h>

int main(void) {

  int i, n;

  printf("This program prints a table of squares.\n");
  scanf("%d", &n);

  i = 1;
  while (i <= n) {
    printf("%10d%10d\n", i, i * i);
    i++;
  }

  return 0;
}
