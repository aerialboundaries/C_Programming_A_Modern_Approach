/* C Programming A Modern Approach pp6-09.c
 * 2025-11-08
 *
 * Programming Project 8 in Chapter 2 asked you to write a program that
 * calculates the remaining balance on a loan after the first, second,
 * and third monthly payments. Modify the program so that it also asks the
 * user to enter the number of payments and then displays the balance
 * remainning after each of these payments.
 */

#include <stdio.h>

float amount_of_loan;
float interest_rate;
float monthly_rate;
float monthly_payment;
int payment_times;
float balance;

int main(void) {
  printf("Enter amount of loan: ");
  scanf("%f", &amount_of_loan);
  printf("Enter interest rate: ");
  scanf("%f", &interest_rate);
  printf("Enter monthly payment: ");
  scanf("%f", &monthly_payment);
  printf("Enter payment times: ");
  scanf("%i", &payment_times);
  monthly_rate = interest_rate / 100 / 12 + 1;
  balance = amount_of_loan;

  for (int i = 1; i <= payment_times; i++) {
    balance = balance * monthly_rate - (monthly_payment);
    printf("Balance remaining after payment: %d: $%.2f\n", i, balance);
  }
  return 0;
}
