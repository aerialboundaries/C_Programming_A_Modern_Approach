/* C Programming A Modern Approach pp6-06.c
 * 2025-11-07
 *
 * WWrite a program that prompts the suer to enter a number n,
 * then prints all even squiares between 1 and n. For example,
 * if the user enters 100, the proguram should print the following:
 *
 * 4
 * 16
 * 36
 * 64
 * 100
 */

#include <stdio.h>

int main(void) {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  for (int i = 2; i * i <= n; i += 2) {
    printf("%d\n", i * i);
  }
  return 0;
}
