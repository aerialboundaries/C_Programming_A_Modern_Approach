/* C Programming A Modern Approach pp07-03.c
 * 2025-11-17
 *
 * Niduft the sum2.c program Section 7.1 to sum a series of double values.
 */

#include <stdio.h>

int main(void) {

  double n, sum = 0;

  printf("This program sums a series of intergers.\n");
  printf("Enter intergers (0 to terminate): ");

  scanf("%lf", &n);
  while (n != 0) {
    sum += n;
    scanf("%lf", &n);
  }
  printf("The sum is: %.2f\n", sum);

  return 0;
}
