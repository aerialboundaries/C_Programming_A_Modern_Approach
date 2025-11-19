#include <stdio.h>

int main(void) {
  float result, f;
  char op;

  printf("Enter an expression: ");

  if (scanf("%f", &result) != 1) {
    printf("Invalid input\n");
    return 1;
  }

  // バッファクリアは不要！

  while (scanf(" %c%f", &op, &f) == 2) {
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
  }

  printf("Value of expression: %g\n", result);
  return 0;
}
