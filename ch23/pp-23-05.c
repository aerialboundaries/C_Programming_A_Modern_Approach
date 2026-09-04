/*
Suppose that money is deposited into a savings account and left for t years. Assume that the
annual interest rate is r and that interest is compounded continuously. The formula A(t) =
Pe"t can be used to calculate the final value of the account, where P is the original amount
deposited. For example, $1000 left on deposit for 10 years at 6% interest would be worth
$1000×e:06x10=$1000xe6=$1000x1.8221188=$1,822.12. Write a program that dis-
plays the result of this calculation after prompting the user to enter the original amount
deposited, the interest rate, and the number of years.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  double amount, original, rate, years;
  printf("input original amount, rate, years (1000 0.06 10): ");
  if (scanf("%lf %lf %lf", &original, &rate, &years) != 3) {
    fprintf(stderr, "wrong input\n");
    exit(EXIT_FAILURE);
  }

  amount = original * exp(rate * years);
  printf("Total amount : %4.2f\n", amount);

  return 0;
}
