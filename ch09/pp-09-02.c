/* C Programming A Modern Approach pp5-5.c
 *
 * In one state, single residents are subject to the following income tax:
 *
 * Income         Amount of tax
 * Not over $750  1% of income
 * $750-$2,250    $7.50   plus 2% of amount over $750
 * $2,250-$3,750  $37.50  plus 3% of amount over $2,250
 * $3,750-%5,250  $82.50  plus 4% of amount over $3,750
 * $5,250-$7,000  $142.50 plus 5% of amount over $5,250
 * Over $7,000    $230.00 plus 6% of amount over $7,000
 *
 * Write a program that asks the user to enter the amount of taxable income,
 * then displays the tax due.
 *
 * Modify Programming Project 5 from chapter 5 so that it uses
 * a function to compute the amount of income tax. When passed an
 * amount of taxable income, the function will return the tax due. */

#include <stdio.h>

double calculate_tax(double income);

int main(void) {
  double income;

  printf("Enter Income: ");
  scanf("%lf", &income);

  printf("Tax due = %.2f", calculate_tax(income));

  return 0;
}

double calculate_tax(double income) {

  if (income < 750)
    return income * 0.01;
  else if (income < 2250)
    return 7.5 + (income - 750) * .02;
  else if (income < 3750)
    return 37.5 + (income - 2250) * .03;
  else if (income < 5250)
    return 82.5 + (income - 3750) * .04;
  else if (income < 7000)
    return 142.5 + (income - 5250) * .05;
  else
    return 230 + (income - 7000) * .06;
}
