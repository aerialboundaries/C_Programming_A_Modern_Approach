#include <stdio.h>

#define COEFFICIENT (4.0f / 3.0f)
#define PI 3.14f

float radius;

int main(void) {
  printf("input the radius: ");
  scanf("%f", &radius);
  printf("Answer : %.2f\n", radius * radius * radius * COEFFICIENT * PI);
  return 0;
}
