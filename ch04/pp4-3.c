/* C Programming A Modern Approach pp4-3.c
 *
 * Q: Rewrite the program in Programming Project 2
 * so that it prints the reversal of a three-digit
 * number without using arithmetic to split the
 * number into digits.
 * Hint: See the upc.c program of Sction 4.1.
 *
 */

#include <stdio.h>

int main(void) {
  int i1, i2, i3;
  printf("Enter a three-digt number: ");
  scanf("%1d%1d%1d", &i1, &i2, &i3);
  printf("%d%d%d\n", i3, i2, i1);

  return 0;
}
