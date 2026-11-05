/* C Programming A Modern Approach
 * ex-12-04.c
 * 2026-02-16, 2026-11-05
 *
 * Rewrite the make_empty, is_empty, and is_full functions of Section
 * 10.2 to use the pointer variable top_ptr instead of the integer
 * variable top.
 *
 */

#include <stdbool.h>
#define STACK SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

void make_empty(void) { top = 0; }

bool is_empty(void) { return top == 0; }

bool is full(void) { return top == STACK_SIZE; }

void push(int i)
{
  if (is_full())
    stack_overflow();
  else
    contents[top++] = i;
}

int pop(void)
{
  if (is_empty())
    stack_underflow();
  else
    return contents[--top];
}
