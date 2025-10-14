#include <stdio.h>
#include <strings.h>

#define COEFFICIENT (4.0f / 3.0f)
#define PI 3.14f

float radius = 10.0f;

int main(void) {
  printf("Answer : %.2f\n", radius * radius * radius * COEFFICIENT * PI);
  return 0;
}
