/* C Programming A Modern Approach
 * pp-13-15.c
 * 2026-03-10
 *
 * Modify Programming Project 6 from Chapter 10 so that it includes the
 * following function:
 *
 * int evaluate_RPN_expression(const char *expression);
 *
 * The function returns the value of the RPN expression pointed to by
 * expression.
 */

/* C Programming A Modern Approach
 * pp-10-06.c
 * 2026-02-11
 *
 * Some calculators (notably those from Hewlett-Packard) use a system of
 * writing mathematical expressions konwn as Reverse Polish Notation (RPN).
 * In this notation, operators are placed after their operands.
 * For example, 1 + 2 would be written 1 2 + in RPN, and 1 + 2 * 3 would
 * be written 1 2 3 * +. RPN expressions can easily be evaluated using a
 * stack. The algorithm invlolves reading the operators and oprands in an
 * expression from left to right, performing the following actions:
 *
 * When an operand is encountered, push it onto the stack.
 * when an operator is encoundtered, pop its operands from the stack,
 * perform the operation of those operands, and then push the result
 * onto the stack.
 *
 * Write a program that evaluates RPN expressions. The operands will be
 * single-digit integers. The operators are +, -, *, /, and =.
 * The = operator causes the top stack item to be displayed; afterwards,
 * the stack is cleared and the user is prompted to enter another expression.
 * The process continues untill the user enters a character that is not
 * an operator or operand:
 *
 * Enter an RPN expression: 1 2 3 * + =
 * Value of expression: 7
 * Enter an RPN expression: 5 8 * 4 9 - / =
 * value of expression: -8
 * Enter an RPN expression: q
 *
 * If the stack overflows, the program will display the message Expression
 * is too complex and terminate. If the stack underflows (because of an
 * expression such as 1 2 + +), the program will display the message Not enough
 * operands in expression and terminate. Hints: Incorporate the stack code from
 * Section 10.2 into your program. Use scanf(" %c", &ch) to read the
 * operator and operand.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 100

void make_empty(int *stack, int *top_ptr);
bool is_empty(int *stack, int *top_ptr);
bool is_full(int *stack, int *top_ptr);
void push(int *top_ptr, char ch);
int pop(int *top_ptr);
void stackoverflow(void);
void stackunderflow(void);

int main(void)
{
  int stack[MAX_STACK];
  int *top_ptr = stack;
  char ch;
  int o1, o2;

  for (;;) {
    printf("Enter an RPN expression: ");
    make_empty(stack, top_ptr);

    while (scanf(" %c", &ch)) {

      switch (ch) {
      case '+':
        o1 = pop(--top_ptr);
        if (is_empty(stack, top_ptr)) {
          stackunderflow();
        }
        o2 = pop(--top_ptr);
        if (is_empty(stack, top_ptr)) {
          stackunderflow();
        }
        push(top_ptr++, o2 + o1);
        break;
      case '-':
        o1 = pop(--top_ptr);
        if (is_empty(stack, top_ptr)) {
          stackunderflow();
        }
        o2 = pop(--top_ptr);
        if (is_empty(stack, top_ptr)) {
          stackunderflow();
        }
        push(top_ptr++, o2 - o1);
        break;
      case '*':
        o1 = pop(--top_ptr);
        if (is_empty(stack, top_ptr)) {
          stackunderflow();
        }
        o2 = pop(--top_ptr);
        if (is_empty(stack, top_ptr)) {
          stackunderflow();
        }
        push(top_ptr++, o2 * o1);
        break;
      case '/':
        o1 = pop(--top_ptr);
        if (is_empty(stack, top_ptr)) {
          stackunderflow();
        }
        o2 = pop(--top_ptr);
        if (is_empty(stack, top_ptr)) {
          stackunderflow();
        }
        push(top_ptr++, o2 / o1);
        break;
      case '=':
        break;
      default:
        if (isdigit(ch)) {
          if (is_full(stack, top_ptr)) {
            stackoverflow();
          }
          push(top_ptr++, ch - '0');
          break;
        } else
          exit(EXIT_SUCCESS);
      }

      if (ch == '=') {
        printf("%d\n", pop(--top_ptr));
        break;
      }
    }
  }

  return 0;
}

void make_empty(int stack[], int *top_ptr) { top_ptr = stack; }

bool is_empty(int stack[], int *top_ptr) { return (top_ptr < stack); }

bool is_full(int stack[], int *top_ptr)
{
  return (top_ptr == stack + MAX_STACK);
}

void push(int *top_ptr, char ch) { *top_ptr++ = ch; }

int pop(int *top_ptr) { return *top_ptr; }

void stackoverflow(void)
{
  fprintf(stderr, "stack overflow\n");
  exit(EXIT_FAILURE);
}

void stackunderflow(void)
{
  fprintf(stderr, "stack underflow\n");
  exit(EXIT_FAILURE);
}
