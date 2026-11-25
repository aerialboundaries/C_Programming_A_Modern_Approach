#ifndef STACK_H
#define STACK_H

typedef struct stack {
  int content;
  struct stack *next;
} Stack;

void make_empty(void);
int is_empty(void);
void push(int i);
int pop(void);

#endif /* STACK_H */
