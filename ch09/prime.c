/* C Programming A Modern Approach
 * prime.c Tests whether a number is prime
 * 2026-01-08
 */

#include <stdbool.h>
#include <stdio.h>

bool is_prime(int n) {
  int divisor;

  if (n <= 1)
    return false;
  for (divisor = 2; divisor * divisor <= n; divisor++)
    if (n % divisor == 0)
      return false;
  return true;
}

int main(void) {
  int n;

  printf("Enter a number: ");
  scanf("%d", &n);
  if (is_prime(n))
    printf("Prime\n");
  else
    printf("Not Prime");

  return 0;
}
