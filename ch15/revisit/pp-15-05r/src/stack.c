#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void make_empty(int *top) { *top = 0; }

bool is_empty(int top) { return top == 0; }

bool is_full(int top, int n) { return top >= n; }

void push(int a[], int *top, int n, int i)
{
  if (is_full(*top, n))
    stack_overflow();
  a[(*top)++] = i;
}

int pop(int a[], int *top)
{
  if (is_empty(*top))
    stack_underflow();
  return a[--(*top)];
}

void stack_overflow(void)
{
  fprintf(stderr, "Stack overflow\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
  fprintf(stderr, "Stack underflow\n");
  exit(EXIT_FAILURE);
}
