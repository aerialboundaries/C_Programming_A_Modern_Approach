/* C Programming A Modern Approach pp07-07.c
 * 2025-11-19
 *
 * Modify Programming Project 6 from Chapter 3 so that the user
 * may add, subtract, multiply, or divide two factions (by
 * entering either +, -, *, or / between the fractions).
 */

/* Modify the addfrac.c program of Section 3.2 so that the user enters both
 * faractions at the same time, separated bya plus sing;
 *
 * Enter two fractions separated by a plus sign: 5/6+3/4
 * The sum is 38/24
 */

// #include <stdio.h>
//
// int main(void) {
//   int num1, denom1, num2, denom2;
//   printf("Enter two franctions separated by a plus sign (ex:5/6+3/4): ");
//   scanf("%d/%d+%d/%d", &num1, &denom1, &num2, &denom2);
//   printf("The sum is %d/%d\n", num1 * denom2 + num2 * denom1, denom1 *
//   denom2);
//
//   return 0;
// }

#include <stdio.h>

int main(void) {
  int num1, denom1, num2, denom2;
  char operator;
  printf("Enter two franctions separated by a +,-,*,/: ");
  scanf("%d/%d %c %d/%d", &num1, &denom1, &operator, &num2, &denom2);

  switch (operator) {
  case '+':
    printf("The answer is %d/%d\n", num1 * denom2 + num2 * denom1,
           denom1 * denom2);
    break;
  case '-':
    printf("The answer is %d/%d\n", num1 * denom2 - num2 * denom1,
           denom1 * denom2);
    break;
  case '*':
    printf("The answer is %d/%d\n", num1 * num2, denom1 * denom2);
    break;
  case '/':
    printf("The answer is %d/%d\n", num1 * denom2, num2 * denom1);
    break;
  default:
    printf("Invalid operator\n");
    break;
  }

  return 0;
}
