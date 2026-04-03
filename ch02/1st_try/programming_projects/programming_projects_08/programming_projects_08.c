#include <stdio.h>

float amount_of_loan;
float interest_rate;
float monthly_rate;
float monthly_payment;
float balance_after_first_payment;
float balance_after_second_payment;
float balance_after_third_payment;

int main(void) {
  printf("Enter amount of loan: ");
  scanf("%f", &amount_of_loan);
  printf("Enter interest rate: ");
  scanf("%f", &interest_rate);
  printf("Enter monthly payment: ");
  scanf("%f", &monthly_payment);
  monthly_rate = interest_rate / 100 / 12 + 1;

  balance_after_first_payment = amount_of_loan * monthly_rate - monthly_payment;
  balance_after_second_payment =
      balance_after_first_payment * monthly_rate - monthly_payment;
  balance_after_third_payment =
      balance_after_second_payment * monthly_rate - monthly_payment;
  printf("Balance remaining after first payment: $%.2f\n",
         balance_after_first_payment);
  printf("Balance remaining after second payment: $%.2f\n",
         balance_after_second_payment);
  printf("Balance remaining after third payment: $%.2f\n",
         balance_after_third_payment);

  return 0;
}
