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
 * Section 10.2 into your program. Use scanf(" %c", &ch) to read the operators
 * and operands. */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

bool is_operator(char ch);
bool is_operand(char ch);
bool is_empty(void);
bool is_full(void);
void make_empty(void);
void push(int ch);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);
void calc(char ch);

int main(void) {
  char ch;
  make_empty();
  for (;;) {
    printf("Enter an RPN expression: ");
    for (;;) {
      scanf(" %c", &ch);
      if (!is_operator(ch) && !is_operand(ch) && ch != '=')
        exit(EXIT_SUCCESS);
      else
        calc(ch);
      if (ch == '=')
        break;
    }
  }

  return 0;
}

bool is_operator(char ch) {
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
  ;
}
bool is_operand(char ch) { return (ch >= '0' && ch <= '9'); }
bool is_empty(void) { return top == 0; }
bool is_full(void) { return top == STACK_SIZE; }
void make_empty(void) { top = 0; }
void push(int ch) {
  if (is_operand(ch))
    ch -= '0';
  if (is_full())
    stack_overflow();
  else
    contents[top++] = ch;
}

int pop(void) {
  if (is_empty()) {
    stack_underflow();
    return 1;
  } else
    return contents[--top];
}

void stack_overflow(void) {
  printf("Expression is too complex\n");
  exit(EXIT_FAILURE);
}
void stack_underflow(void) {
  printf("Not enough operands in expression\n");
  exit(EXIT_FAILURE);
}

void calc(char ch) {
  int op1, op2;

  if (is_operand(ch))
    push(ch);

  if (is_operator(ch)) {
    op2 = pop();
    op1 = pop();
  }

  switch (ch) {
  case '+':
    push(op1 + op2);
    break;
  case '-':
    push(op1 - op2);
    break;
  case '*':
    push(op1 * op2);
    break;
  case '/':
    push(op1 / op2);
    break;
  case '=':
    printf("Value of expression: %d\n", pop());
    make_empty();
    break;
  default:
    break;
  }
  return;
}
