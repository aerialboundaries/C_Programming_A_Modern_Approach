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

void stackoverflow(void);
void stackunderflow(void);

int evaluate_RPN_expression(const char *expression)
{
  int stack[MAX_STACK];
  int *top_ptr = stack;
  int o1, o2;

  while (*expression != '\0') {
    char ch = *expression++;

    if (isspace((unsigned char)ch)) {
      continue;
    }

    if (isdigit((unsigned char)ch)) {
      if (top_ptr == stack + MAX_STACK) {
        stackoverflow();
      }

      *top_ptr++ = ch - '0';
    } else {
      if (top_ptr - stack < 2) {
        stackunderflow();
      }

      o1 = *--top_ptr;
      o2 = *--top_ptr;

      switch (ch) {
      case '+':
        *top_ptr++ = o2 + o1;
        break;
      case '-':
        *top_ptr++ = o2 - o1;
        break;
      case '*':
        *top_ptr++ = o2 * o1;
        break;
      case '/':
        if (o1 == 0) {
          fprintf(stderr, "division by zero\n");
          exit(EXIT_FAILURE);
        }
        *top_ptr++ = o2 / o1;
        break;
      default:
        fprintf(stderr, "invalid expression\n");
        exit(EXIT_FAILURE);
      }
    }
  }

  if (top_ptr - stack != 1) {
    fprintf(stderr, "invalid expression\n");
    exit(EXIT_FAILURE);
  }

  return *--top_ptr;
}

int main(void)
{
  char expression[256];

  for (;;) {
    printf("Enter an RPN expression: ");

    if (fgets(expression, sizeof(expression), stdin) == NULL) {
      break;
    }

    if (expression[0] == 'q') {
      break;
    }

    printf("Value of expression: %d\n", evaluate_RPN_expression(expression));
  }

  return 0;
}

void stackoverflow(void)
{
  fprintf(stderr, "Expression is too complex\n");
  exit(EXIT_FAILURE);
}

void stackunderflow(void)
{
  fprintf(stderr, "Not enough operands in expression\n");
  exit(EXIT_FAILURE);
}
