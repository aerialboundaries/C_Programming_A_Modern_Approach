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
#include <stdio.h>
#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int *top_ptr = contents;

void make_empty(void) { top_ptr = contents; }

bool is_empty(void) { return top_ptr == contents; }

bool is_full(void) { return top_ptr == contents + STACK_SIZE; }

void push(int i)
{
  if (is_full())
    stack_overflow();
  else
    *top_ptr++ = i;
}

int pop(void)
{
  if (is_empty())
    stack_underflow();
  else
    return --*top_ptr;
}

int main(void)
{
  make_empty();

  push(10);
  push(20);
  push(30);

  printf("Popped: %d\n", pop());
  printf("Popped: %d\n", pop());

  return 0;
}
