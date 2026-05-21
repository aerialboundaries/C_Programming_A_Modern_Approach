/* C_Programming_A_Modern_Approach
ex-19-04.c
2026-05-21

(a) Write an implementation of the Stack type, assuming that Stack is a
structure containing a fixed-length array.

(b) Redo the Stack type, this time using a linked-list representation instead of
an array. (Show both stack. h and stack.c.)

*/

// (a) Contents of stack.c file :

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void make_empty(Stack *s)
{
    s->top = 0;
}

bool is_empty(const Stack *s)
{
    return s->top == 0;
}

bool is_full(const Stack *s)
{
    return s->top == STACK_SIZE;
}

void push(Stack *s, int i)
{
    if (is_full(s))
        terminate("Error in push: stack is full.");
    s->contents[s->top++] = i;
}

int pop(Stack *s)
{
    if (is_empty(s))
        terminate("Error in pop: stack is empty.");
    return s->contents[--s->top];
}

// (b) Contents of stack.h file :

#ifndef STACK_H
#define STACK_H

#include <stdbool.h> /* C99 only */

struct node {
    int data;

    struct node *next;
};

typedef struct node *Stack;

void make_empty(Stack *s);
bool is_empty(const Stack *s);
bool is_full(const Stack *s);
void push(Stack *s, int i);
int pop(Stack *s);

#endif

// Contents of stack.c file :

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void make_empty(Stack *s)
{
    while (!is_empty(s))
        pop(s);
}

bool is_empty(const Stack *s)
{
    return *s == NULL;
}

bool is_full(const Stack *s)
{
    return false;
}

void push(Stack *s, int i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in push: stack is full.");

    new_node->data = i;
    new_node->next = *s;
    *s = new_node;
}

int pop(Stack *s)
{
    struct node *old_top;
    int i;

    if (is_empty(s))
        terminate("Error in pop: stack is empty.");

    old_top = *s;
    i = (*s)->data;
    *s = (*s)->next;
    free(old_top);
    return i;
}
