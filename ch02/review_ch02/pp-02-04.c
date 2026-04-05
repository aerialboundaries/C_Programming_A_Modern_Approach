/* C_Programming_A_Modern_Approach****************************************
 * pp-02-04.c
 * 2026-04-04
 *
 * Write a program that asks the user to enter a dollars-and-cents
 * amount, then displays the amount with 5% tax added:
 *
 * Enter an amount: 100.00
 * With tax added: $105.00
 * **********************************************************************/
#include <stdio.h>

double calctax(double amount);

int main(void) {
  double amount;

  printf("Enter an amount: ");
  scanf("%lf", &amount);
  printf("With tax added: $%.2f\n", calctax(amount));

  return 0;
}

double calctax(double amount) { return (amount * 1.05); }
