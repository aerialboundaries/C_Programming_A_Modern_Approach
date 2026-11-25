#include <stdio.h>
#include <stdlib.h>

#include "operate.h"
#include "stack.h"

void plus(void)
{
  int a = pop();
  int b = pop();
  push(b + a);
}

void minus(void)
{
  int a = pop();
  int b = pop();
  push(b - a);
}

void multi(void)
{
  int a = pop();
  int b = pop();
  push(b * a);
}

void divi(void)
{
  int a = pop();
  int b = pop();
  if (a == 0) {
    fprintf(stderr, "Error: Div/0\n");
    exit(EXIT_FAILURE);
  }
  push(b / a);
}
