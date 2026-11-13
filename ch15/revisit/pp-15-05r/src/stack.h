#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

void make_empty(int *top);
bool is_empty(int top);
bool is_full(int top, int n);
void push(int a[], int *top, int n, int i);
int pop(int a[], int *top);
void stack_overflow(void);
void stack_underflow(void);

#endif
