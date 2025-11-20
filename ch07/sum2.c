/* C Programming A Modern Approach sum.c
 * 2025/11/12 */

#include <stdio.h>

int main(void) {

  long n, sum = 0;

  printf("This program sums a series of intergers.\n");
  printf("Enter intergers (0 to terminate): ");

  scanf("%ld", &n);
  while (n != 0) {
    sum += n;
    scanf("%ld", &n);
  }
  printf("The sum is: %ld\n", sum);

  return 0;
}
