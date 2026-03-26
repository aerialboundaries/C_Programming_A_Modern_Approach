#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

bool is_operator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    ;
}
bool is_operand(char ch)
{
    return (ch >= '0' && ch <= '9');
}
bool is_empty(void)
{
    return top == 0;
}
bool is_full(void)
{
    return top == STACK_SIZE;
}
void make_empty(void)
{
    top = 0;
}
void push(int ch)
{
    if (is_operand(ch))
        ch -= '0';
    if (is_full())
        stack_overflow();
    else
        contents[top++] = ch;
}

int pop(void)
{
    if (is_empty()) {
        stack_underflow();
        return 1;
    } else
        return contents[--top];
}

void stack_overflow(void)
{
    printf("Expression is too complex\n");
    exit(EXIT_FAILURE);
}
void stack_underflow(void)
{
    printf("Not enough operands in expression\n");
    exit(EXIT_FAILURE);
}
