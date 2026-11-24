#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

Stack *top;

void make_empty(void)
{
  while (!is_empty()) {
    (void)pop();
  }
}

int is_empty(void) { return top == NULL; }

void push(int i)
{
  Stack *new_node = malloc(sizeof *new_node);
  if (new_node == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  new_node->content = i;
  new_node->next = top;
  top = new_node;
}

int pop(void)
{
  if (!is_empty()) {
    fprintf(stderr, "Error: popped with empty stack.\n");
    exit(EXIT_FAILURE);
  }

  Stack *old_top = top;
  int value = old_top->content;
  top = old_top;
  free(old_top);

  return value;
}
