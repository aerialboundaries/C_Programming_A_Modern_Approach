#ifndef STACK_H
#define STACK_H

bool is_empty(void);
bool is_full(void);
void make_empty(void);
void push(int ch);
int pop(void);
bool is_operator(char ch);
bool is_operand(char ch);
void stack_overflow(void);
void stack_underflow(void);

#endif
