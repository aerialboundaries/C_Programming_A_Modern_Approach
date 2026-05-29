#ifndef STACK_ADT
#define STACK_ADT

#include <stdbool.h>

typedef int Item;

typedef struct stack_type *Stack;

Stack create(int size);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, Item c);
Item pop(Stack s);

#endif
