#include <stdio.h>

#define TAX_RATE (1 + 0.05f)

float amount;

int main(void) {
  printf("input amount: ");
  scanf("%f", &amount);
  printf("The amount with Tax : %4.2f\n", amount * TAX_RATE);

  return 0;
}
