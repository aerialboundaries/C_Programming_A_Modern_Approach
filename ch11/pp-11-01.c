/**************************************************************************
 * C Programming A Modern Approach                                         *
 * pp-11-01.c                                                              *
 * 2026-02-13                                                              *
 *                                                                         *
 * Modify Programming Project 7 from Chapter 2 so that it includes the     *
 * following function:                                                     *
 *                                                                         *
 * void pay_amount (int dollars, int *twenties, int *tens, int *fives,     *
 * int *ones);                                                             *
 *                                                                         *
 * The function determines the smallest number of $20, $10, $5, and $1     *
 * bills necessary to pay the amount represented by the dollars parameter  *
 * The twenties parameter points to a variable in which the function will  *
 * store the number of $20 bills required. The tens, fives, and ones,      *
 * parameters are similar.                                                 *
 **************************************************************************/

#include <stdio.h>
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void) {
  int bill20;
  int bill10;
  int bill5;
  int bill1;
  int amount;

  printf("Enter amount: ");
  scanf("%d", &amount);

  pay_amount(amount, &bill20, &bill10, &bill5, &bill1);

  printf("$20 bills: %d\n $10 bills: %d\n  $5 bills: %d\n  $1 bills: %d\n",
         bill20, bill10, bill5, bill1);
  return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
  *twenties = dollars / 20;
  *ones = dollars - *twenties * 20;
  *tens = *ones / 10;
  *ones = *ones - *tens * 10;
  *fives = *ones / 5;
  *ones = *ones - *fives * 5;
}
