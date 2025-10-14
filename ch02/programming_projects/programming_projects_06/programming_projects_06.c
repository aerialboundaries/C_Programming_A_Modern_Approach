#include <stdio.h>

#define HORNER (((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6)

int x;

int main(void) {
  printf("Enter x as integer: ");
  scanf("%d", &x);
  printf("Answer is : %d", HORNER);

  return 0;
}
