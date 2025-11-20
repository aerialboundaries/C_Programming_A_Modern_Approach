/* C Programnming A Modern Approach pp07-15.c
 * 2025-11-20
 *
 * Write a program that computes the factorial of a positive integer:
 * Enter a positive integer: 6
 * Factoryal of 6: 720
 *
 * (a) Use a short variable to store the value of the factorial.
 * What is the largest value of n for which the program correctory prints
 * the facotorial of n?
 * (b) Rpeat part(a), using an int variable instead.
 * (c) Repeat part(a) using a long varialble instead.
 * (d) Repeat part(a) using a long long varialble instead.
 * (e) Repeat part(a) using a float varialble instead.
 * (f) Repeat part(a) using a double varialble instead.
 * (g) Repeat part(a) using a long double varialble instead.
 *
 * In cases (e) - (g), the program will display a close approximation
 * of the factoryal, not necessarily the exact value.
 */

#include <stdio.h>

int main(void) {

  int n;
  long double factorial = 1;

  printf("Enter a positive integer: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    factorial *= i;
  }

  printf("Factorial of %d: %Lg", n, factorial);

  return 0;
}

/* My Answer
 * (a) n = 7: Factorial = 5040
 * (b) n = 12: Factorial = 479001600
 * (c) n = 20: Factorial = 243290200817664000
 * (d) n = 20: Factorial = 243290200817664000
 * (e) n = 34: Factorial = 295232822996533287161359432338880069632.000000
 * (f) n = 170: Factorial = 7.25742e+306
 * (g) n = 1754: Factorial = 1.97926e+4930
 */
