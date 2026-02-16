/* C Programming A Modern Approach
 * ex-12-04.c
 * 2026-02-16
 *
 * Rewrite the make_empty, is_empty, and is_full functions of Section
 * 10.2 to use the pointer variable top_ptr instead of the integer
 * variable top.
 *
 */

#include <stdbool.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int *top_ptr = &contents[0];

void make_empty(void) { top_ptr = &contents[0]; }

bool is_empty(void) { return top_ptr == &contents[0]; }

bool is_full(void) { return top_ptr == &contents[STACK_SIZE]; }
