/*
Modify the stackADT2. c file of Section 19.4 so that it uses assert to test for errors
instead of using if statements. (Note that the terminate function is no longer necessary
and can be removed.)

My Answer:

#include <stdio.h>
#include <stdlib.h>

#include "stackADT2.h"

struct stack_type {
  Item *contents;
  int top;
  int size;
};

Stack create(int size) {
  Stack s = malloc(sizeof(struct stack_type));
  assert (s != NULL);
  s->contents = malloc(size * sizeof(Item));
  assert (s->contents != NULL) ;
  
  s->top = 0;
  s->size = size;
  return s;
}

void destroy(Stack s) {
  free(s->contents);
  free(s);
}

void make_empty(Stack s) { s->top = 0; }

bool is_empty(Stack s) { return s->top == 0; }

bool is_full(Stack s) { return s->top == s->size; }

void push(Stack s, int i) {
  assert(!is_full(s));
  s->contents[s->top++] = i;
}

int pop(Stack s) {
  assert (!is_empty(s));
  return s->contents[--s->top];
}
 
 */
