/* C Programming A Modern Approach ex4-8.c
 *
 * Q: Would the upc.c program still work if the expression 9 - ((tatal -1) % 10)
 * were replaced by (10 - (total % 10)) % 10?
 *
 * My Answer : It would work, because upc.c does not check if the check digit is
 * 0-9.
 */

#include <stdio.h>

int main(void) {
  int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, first_sum, second_sum, total;

  printf("Enter the first (singlel) digit: ");
  scanf("%1d", &d);
  printf("Enter forst group of five digits: ");
  scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
  printf("Enter the second group of five digits: ");
  scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);
  first_sum = d + i2 + i4 + j1 + j3 + j5;
  second_sum = i1 + i3 + i5 + j2 + j4;
  total = first_sum * 3 + second_sum;
  printf("Check digit : %d\n", (10 - (total % 10)) % 10);

  return 0;
}
