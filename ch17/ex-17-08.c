/* C_Programming_A_Modern_Approach
 * ex-17-08.c
 * 2026-04-24
 *
 * Section 15.2 describes a file, stack.c, that provides functions for storing
 * integers in a stack. In that section, the stack was implemented as an array.
 * Modify stack.c so that a stack is now stored as a linked list. Replace the
 * contents and top variables by a single variable that points to the first node
 * in the list (the "top" of the stack). Write the functions in stack.c so that
 * they use this pointer. Remove the is_full function, instead having push
 * return either true (if memory was available to create a node) or false (if
 * not).
 *
 *
 */

// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
//
// #define STACK_SIZE 100
//
// /* external variables */
// // int contents[STACK_SIZE];
// // int top = 0;
// struct node {
//     int x;
//     struct node *next;
// };
//
// struct node *first = NULL; // point to first
//
// /* prototypes */
// bool is_empty(struct node *list);
// // bool is_full(void);
// void make_empty(struct node *list);
// bool push(struct node **list, int ch);
// struct node *pop(struct node **list);
// bool is_operator(char ch);
// bool is_operand(char ch);
// void stack_overflow(void);
// void stack_underflow(void);
//
// bool is_operator(char ch)
// {
//     return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
//     ;
// }
// bool is_operand(char ch)
// {
//     return (ch >= '0' && ch <= '9');
// }
// bool is_empty(struct node *list)
// {
//     // return top == 0;
//     return list == 0;
// }
// // bool is_full(void)
// // {
// //     return top == STACK_SIZE;
// // }
// void make_empty(struct node *list)
// {
//     // top = 0;
//     list = NULL;
// }
// bool push(struct node **list, int ch)
// {
//     struct node *new_node;
//
//     if (is_operand(ch))
//         ch -= '0';
//
//     if ((new_node = malloc(sizeof(struct node))) == NULL)
//         // stack_overflow();
//         return false;
//     else {
//         new_node->x = ch;
//         new_node->next = *list;
//         *list = new_node;
//         return true;
//     }
// }
//
// struct node *pop(struct node **list)
// {
//   struct node *cur, *prev;
//
//     if (is_empty(*list)) {
//         // stack_underflow();
//         return false;
//     } else {
//       for (cur = *list, prev = NULL; cur != NULL; cur = cur->next, prev =
//       cur)
//           ;
//       *list = cur;
//       cur = prev;
//       return *list;
//       free(cur);
//     }
// }
//
// void stack_overflow(void)
// {
//     printf("Expression is too complex\n");
//     exit(EXIT_FAILURE);
// }
// void stack_underflow(void)
// {
//     printf("Not enough operands in expression\n");
//     exit(EXIT_FAILURE);
// }

/* KN's Answer */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

struct node {
  int value;
  struct node *next;
};

struct node *top = NULL;

void make_empty(void) {
  struct node *temp;

  while (top != NULL) {
    temp = top;
    top = top->next;
    free(temp);
  }
}

bool is_empty(void) { return top == NULL; }

bool push(int i)

{
  struct node *new_node;

  new_node = malloc(sizeof(struct node));
  if (new_node == NULL)
    return false;

  new_node->value = i;
  new_node->next = top;
  top = new_node;

  return true;
}

int pop(void)

{
  struct node *temp;
  int i;

  if (is_empty()) {
    printf("*** Stack underflow; program terminated. ***\n");
    exit(EXIT_FAILURE);
  }

  i = top->value;
  temp = top;
  top = top->next;
  free(temp);

  return i;
}
