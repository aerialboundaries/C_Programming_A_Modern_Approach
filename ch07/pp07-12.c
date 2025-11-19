/* C Programming A Modern Approach pp07-12.c
 * 2025-11-19
 *
 * Write a program that evaluates an expression:
 *
 * Enter an expression: 1+2.5*3
 * Value of expression: 10.5
 *
 * The operands in the expression are floating-point numbers;
 * the operators are +, -, *, and /. The expression is evaluated
 * from left to right (no operator takes precedence over any
 * other operator). */

#include <stdio.h>

int main(void) {

  float f = 0.0f;
  float result = 0.0f;
  char op, ch;

  printf("Enter a expression: ");
  scanf("%f", &result); // initial number

  while (getchar() != '\n') {
    scanf(" %c%f", &op, &f);

    switch (op) {
    case '+':
      result += f;
      break;
    case '-':
      result -= f;
      break;
    case '*':
      result *= f;
      break;
    case '/':
      result /= f;
      break;
    default:
      printf("Invalid operator\n");
      return 1;
    }
    // while ((ch = getchar()) != '\n' && ch != EOF)
    /* clear buffer */;
  }

  printf("Value of expression: %4.2f", result);

  return 0;
}
