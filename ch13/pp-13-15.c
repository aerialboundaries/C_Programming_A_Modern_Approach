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
operato#include <stdbool.h> #include <ctype.h> #include <stdio.h> #include
<stdlib.h>

#define STACK_SIZE 100

/* --- プロトタイプ宣言 --- */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void stack_overflow(void);

void stack_underflow(void);
void push(int i);
int pop(void);
int evaluate_RPN_expression(const char *expression);

/* --- 外部変数 --- */
int contents[STACK_SIZE];
int top = 0;

/* --- main関数 --- */
int main(void) {
  char ch;
  char expression[100];
  int i;

  for (;;) {
    printf("Enter an RPN expression: ");
    i = 0;
    for (;;) {
      if (scanf(" %c", &ch) != 1)
        break;

      if (!isdigit((unsigned char)ch) && ch != '+' && ch != '-' && ch != '*' &&
          ch != '/' && ch != '=') {
        return 0;
      }

      expression[i++] = ch;

      if (ch == '=') {

        expression[i] = '\0';

        printf("Value of expression: %d\n",
               evaluate_RPN_expression(expression));
        break;
      }
    }
  }
  return 0;
}

/* --- 関数の定義（中身） --- */

int evaluate_RPN_expression(const char *expression) {
  int op1, op2;
  make_empty();

  while (*expression) {

    if (isdigit((unsigned char)*expression)) {
      push(*expression - '0');
    } else if (*expression == '+') {

      push(pop() + pop());
    } else if (*expression == '-') {
      op2 = pop();
      op1 = pop();
      push(op1 - op2);
    } else if (*expression == '*') {
      push(pop() * pop());

    } else if (*expression == '/') {

      op2 = pop();
      op1 = pop();
      push(op1 / op2);
    } else if (*expression == '=') {
      return pop();
    }
    expression++;
  }
  return 0;
}

void make_empty(void) { top = 0; }
bool is_empty(void) { return top == 0; }
bool is_full(void) { return top == STACK_SIZE; }

void stack_overflow(void) {
  printf("Expression is too complex\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void) {
  printf("Not enough operands in expression\n");
  exit(EXIT_FAILURE);
}

void push(int i) {
  if (is_full())
    stack_overflow();

  else
    contents[top++] = i;
}

int pop(void) {
  if (is_empty()) {
    stack_underflow();
    return 0;
  }
  return contents[--top];
}
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

          /* --- プロトタイプ宣言 --- */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void stack_overflow(void);

void stack_underflow(void);
void push(int i);
int pop(void);
int evaluate_RPN_expression(const char *expression);

/* --- 外部変数 --- */
int contents[STACK_SIZE];
int top = 0;

/* --- main関数 --- */
int main(void) {
  char ch;
  char expression[100];
  int i;

  for (;;) {
    printf("Enter an RPN expression: ");
    i = 0;
    for (;;) {
      if (scanf(" %c", &ch) != 1)
        break;

      if (!isdigit((unsigned char)ch) && ch != '+' && ch != '-' && ch != '*' &&
          ch != '/' && ch != '=') {
        return 0;
      }

      expression[i++] = ch;

      if (ch == '=') {

        expression[i] = '\0';

        printf("Value of expression: %d\n",
               evaluate_RPN_expression(expression));
        break;
      }
    }
  }
  return 0;
}

/* --- 関数の定義（中身） --- */

int evaluate_RPN_expression(const char *expression) {
  int op1, op2;
  make_empty();

  while (*expression) {

    if (isdigit((unsigned char)*expression)) {
      push(*expression - '0');
    } else if (*expression == '+') {

      push(pop() + pop());
    } else if (*expression == '-') {
      op2 = pop();
      op1 = pop();
      push(op1 - op2);
    } else if (*expression == '*') {
      push(pop() * pop());

    } else if (*expression == '/') {

      op2 = pop();
      op1 = pop();
      push(op1 / op2);
    } else if (*expression == '=') {
      return pop();
    }
    expression++;
  }
  return 0;
}

void make_empty(void) { top = 0; }
bool is_empty(void) { return top == 0; }
bool is_full(void) { return top == STACK_SIZE; }

void stack_overflow(void) {
  printf("Expression is too complex\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void) {
  printf("Not enough operands in expression\n");
  exit(EXIT_FAILURE);
}

void push(int i) {
  if (is_full())
    stack_overflow();

  else
    contents[top++] = i;
}

int pop(void) {
  if (is_empty()) {
    stack_underflow();
    return 0;
  }
  return contents[--top];
}
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

          /* --- プロトタイプ宣言 --- */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void stack_overflow(void);

void stack_underflow(void);
void push(int i);
int pop(void);
int evaluate_RPN_expression(const char *expression);

/* --- 外部変数 --- */
int contents[STACK_SIZE];
int top = 0;

/* --- main関数 --- */
int main(void) {
  char ch;
  char expression[100];
  int i;

  for (;;) {
    printf("Enter an RPN expression: ");
    i = 0;
    for (;;) {
      if (scanf(" %c", &ch) != 1)
        break;

      if (!isdigit((unsigned char)ch) && ch != '+' && ch != '-' && ch != '*' &&
          ch != '/' && ch != '=') {
        return 0;
      }

      expression[i++] = ch;

      if (ch == '=') {

        expression[i] = '\0';

        printf("Value of expression: %d\n",
               evaluate_RPN_expression(expression));
        break;
      }
    }
  }
  return 0;
}

/* --- 関数の定義（中身） --- */

int evaluate_RPN_expression(const char *expression) {
  int op1, op2;
  make_empty();

  while (*expression) {

    if (isdigit((unsigned char)*expression)) {
      push(*expression - '0');
    } else if (*expression == '+') {

      push(pop() + pop());
    } else if (*expression == '-') {
      op2 = pop();
      op1 = pop();
      push(op1 - op2);
    } else if (*expression == '*') {
      push(pop() * pop());

    } else if (*expression == '/') {

      op2 = pop();
      op1 = pop();
      push(op1 / op2);
    } else if (*expression == '=') {
      return pop();
    }
    expression++;
  }
  return 0;
}

void make_empty(void) { top = 0; }
bool is_empty(void) { return top == 0; }
bool is_full(void) { return top == STACK_SIZE; }

void stack_overflow(void) {
  printf("Expression is too complex\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void) {
  printf("Not enough operands in expression\n");
  exit(EXIT_FAILURE);
}

void push(int i) {
  if (is_full())
    stack_overflow();

  else
    contents[top++] = i;
}

int pop(void) {
  if (is_empty()) {
    stack_underflow();
    return 0;
  }
  return contents[--top];
}
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

          /* --- プロトタイプ宣言 --- */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void stack_overflow(void);

void stack_underflow(void);
void push(int i);
int pop(void);
int evaluate_RPN_expression(const char *expression);

/* --- 外部変数 --- */
int contents[STACK_SIZE];
int top = 0;

/* --- main関数 --- */
int main(void) {
  char ch;
  char expression[100];
  int i;

  for (;;) {
    printf("Enter an RPN expression: ");
    i = 0;
    for (;;) {
      if (scanf(" %c", &ch) != 1)
        break;

      if (!isdigit((unsigned char)ch) && ch != '+' && ch != '-' && ch != '*' &&
          ch != '/' && ch != '=') {
        return 0;
      }

      expression[i++] = ch;

      if (ch == '=') {

        expression[i] = '\0';

        printf("Value of expression: %d\n",
               evaluate_RPN_expression(expression));
        break;
      }
    }
  }
  return 0;
}

/* --- 関数の定義（中身） --- */

int evaluate_RPN_expression(const char *expression) {
  int op1, op2;
  make_empty();

  while (*expression) {

    if (isdigit((unsigned char)*expression)) {
      push(*expression - '0');
    } else if (*expression == '+') {

      push(pop() + pop());
    } else if (*expression == '-') {
      op2 = pop();
      op1 = pop();
      push(op1 - op2);
    } else if (*expression == '*') {
      push(pop() * pop());

    } else if (*expression == '/') {

      op2 = pop();
      op1 = pop();
      push(op1 / op2);
    } else if (*expression == '=') {
      return pop();
    }
    expression++;
  }
  return 0;
}

void make_empty(void) { top = 0; }
bool is_empty(void) { return top == 0; }
bool is_full(void) { return top == STACK_SIZE; }

void stack_overflow(void) {
  printf("Expression is too complex\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void) {
  printf("Not enough operands in expression\n");
  exit(EXIT_FAILURE);
}

void push(int i) {
  if (is_full())
    stack_overflow();

  else
    contents[top++] = i;
}

int pop(void) {
  if (is_empty()) {
    stack_underflow();
    return 0;
  }
  return contents[--top];
}
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

          /* --- プロトタイプ宣言 --- */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void stack_overflow(void);

void stack_underflow(void);
void push(int i);
int pop(void);
int evaluate_RPN_expression(const char *expression);

/* --- 外部変数 --- */
int contents[STACK_SIZE];
int top = 0;

/* --- main関数 --- */
int main(void) {
  char ch;
  char expression[100];
  int i;

  for (;;) {
    printf("Enter an RPN expression: ");
    i = 0;
    for (;;) {
      if (scanf(" %c", &ch) != 1)
        break;

      if (!isdigit((unsigned char)ch) && ch != '+' && ch != '-' && ch != '*' &&
          ch != '/' && ch != '=') {
        return 0;
      }

      expression[i++] = ch;

      if (ch == '=') {

        expression[i] = '\0';

        printf("Value of expression: %d\n",
               evaluate_RPN_expression(expression));
        break;
      }
    }
  }
  return 0;
}

/* --- 関数の定義（中身） --- */

int evaluate_RPN_expression(const char *expression) {
  int op1, op2;
  make_empty();

  while (*expression) {

    if (isdigit((unsigned char)*expression)) {
      push(*expression - '0');
    } else if (*expression == '+') {

      push(pop() + pop());
    } else if (*expression == '-') {
      op2 = pop();
      op1 = pop();
      push(op1 - op2);
    } else if (*expression == '*') {
      push(pop() * pop());

    } else if (*expression == '/') {

      op2 = pop();
      op1 = pop();
      push(op1 / op2);
    } else if (*expression == '=') {
      return pop();
    }
    expression++;
  }
  return 0;
}

void make_empty(void) { top = 0; }
bool is_empty(void) { return top == 0; }
bool is_full(void) { return top == STACK_SIZE; }

void stack_overflow(void) {
  printf("Expression is too complex\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void) {
  printf("Not enough operands in expression\n");
  exit(EXIT_FAILURE);
}

void push(int i) {
  if (is_full())
    stack_overflow();

  else
    contents[top++] = i;
}

int pop(void) {
  if (is_empty()) {
    stack_underflow();
    return 0;
  }
  return contents[--top];
}
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

          /* --- プロトタイプ宣言 --- */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void stack_overflow(void);

void stack_underflow(void);
void push(int i);
int pop(void);
int evaluate_RPN_expression(const char *expression);

/* --- 外部変数 --- */
int contents[STACK_SIZE];
int top = 0;

/* --- main関数 --- */
int main(void) {
  char ch;
  char expression[100];
  int i;

  for (;;) {
    printf("Enter an RPN expression: ");
    i = 0;
    for (;;) {
      if (scanf(" %c", &ch) != 1)
        break;

      if (!isdigit((unsigned char)ch) && ch != '+' && ch != '-' && ch != '*' &&
          ch != '/' && ch != '=') {
        return 0;
      }

      expression[i++] = ch;

      if (ch == '=') {

        expression[i] = '\0';

        printf("Value of expression: %d\n",
               evaluate_RPN_expression(expression));
        break;
      }
    }
  }
  return 0;
}

/* --- 関数の定義（中身） --- */

int evaluate_RPN_expression(const char *expression) {
  int op1, op2;
  make_empty();

  while (*expression) {

    if (isdigit((unsigned char)*expression)) {
      push(*expression - '0');
    } else if (*expression == '+') {

      push(pop() + pop());
    } else if (*expression == '-') {
      op2 = pop();
      op1 = pop();
      push(op1 - op2);
    } else if (*expression == '*') {
      push(pop() * pop());

    } else if (*expression == '/') {

      op2 = pop();
      op1 = pop();
      push(op1 / op2);
    } else if (*expression == '=') {
      return pop();
    }
    expression++;
  }
  return 0;
}

void make_empty(void) { top = 0; }
bool is_empty(void) { return top == 0; }
bool is_full(void) { return top == STACK_SIZE; }

void stack_overflow(void) {
  printf("Expression is too complex\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void) {
  printf("Not enough operands in expression\n");
  exit(EXIT_FAILURE);
}

void push(int i) {
  if (is_full())
    stack_overflow();

  else
    contents[top++] = i;
}

int pop(void) {
  if (is_empty()) {
    stack_underflow();
    return 0;
  }
  return contents[--top];
}
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

          /* --- プロトタイプ宣言 --- */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void stack_overflow(void);

void stack_underflow(void);
void push(int i);
int pop(void);
int evaluate_RPN_expression(const char *expression);

/* --- 外部変数 --- */
int contents[STACK_SIZE];
int top = 0;

/* --- main関数 --- */
int main(void) {
  char ch;
  char expression[100];
  int i;

  for (;;) {
    printf("Enter an RPN expression: ");
    i = 0;
    for (;;) {
      if (scanf(" %c", &ch) != 1)
        break;

      if (!isdigit((unsigned char)ch) && ch != '+' && ch != '-' && ch != '*' &&
          ch != '/' && ch != '=') {
        return 0;
      }

      expression[i++] = ch;

      if (ch == '=') {

        expression[i] = '\0';

        printf("Value of expression: %d\n",
               evaluate_RPN_expression(expression));
        break;
      }
    }
  }
  return 0;
}

/* --- 関数の定義（中身） --- */

int evaluate_RPN_expression(const char *expression) {
  int op1, op2;
  make_empty();

  while (*expression) {

    if (isdigit((unsigned char)*expression)) {
      push(*expression - '0');
    } else if (*expression == '+') {

      push(pop() + pop());
    } else if (*expression == '-') {
      op2 = pop();
      op1 = pop();
      push(op1 - op2);
    } else if (*expression == '*') {
      push(pop() * pop());

    } else if (*expression == '/') {

      op2 = pop();
      op1 = pop();
      push(op1 / op2);
    } else if (*expression == '=') {
      return pop();
    }
    expression++;
  }
  return 0;
}

void make_empty(void) { top = 0; }
bool is_empty(void) { return top == 0; }
bool is_full(void) { return top == STACK_SIZE; }

void stack_overflow(void) {
  printf("Expression is too complex\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void) {
  printf("Not enough operands in expression\n");
  exit(EXIT_FAILURE);
}

void push(int i) {
  if (is_full())
    stack_overflow();

  else
    contents[top++] = i;
}

int pop(void) {
  if (is_empty()) {
    stack_underflow();
    return 0;
  }
  return contents[--top];
}
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

          /* --- プロトタイプ宣言 --- */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void stack_overflow(void);

void stack_underflow(void);
void push(int i);
int pop(void);
int evaluate_RPN_expression(const char *expression);

/* --- 外部変数 --- */
int contents[STACK_SIZE];
int top = 0;

/* --- main関数 --- */
int main(void) {
  char ch;
  char expression[100];
  int i;

  for (;;) {
    printf("Enter an RPN expression: ");
    i = 0;
    for (;;) {
      if (scanf(" %c", &ch) != 1)
        break;

      if (!isdigit((unsigned char)ch) && ch != '+' && ch != '-' && ch != '*' &&
          ch != '/' && ch != '=') {
        return 0;
      }

      expression[i++] = ch;

      if (ch == '=') {

        expression[i] = '\0';

        printf("Value of expression: %d\n",
               evaluate_RPN_expression(expression));
        break;
      }
    }
  }
  return 0;
}

/* --- 関数の定義（中身） --- */

int evaluate_RPN_expression(const char *expression) {
  int op1, op2;
  make_empty();

  while (*expression) {

    if (isdigit((unsigned char)*expression)) {
      push(*expression - '0');
    } else if (*expression == '+') {

      push(pop() + pop());
    } else if (*expression == '-') {
      op2 = pop();
      op1 = pop();
      push(op1 - op2);
    } else if (*expression == '*') {
      push(pop() * pop());

    } else if (*expression == '/') {

      op2 = pop();
      op1 = pop();
      push(op1 / op2);
    } else if (*expression == '=') {
      return pop();
    }
    expression++;
  }
  return 0;
}

void make_empty(void) { top = 0; }
bool is_empty(void) { return top == 0; }
bool is_full(void) { return top == STACK_SIZE; }

void stack_overflow(void) {
  printf("Expression is too complex\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void) {
  printf("Not enough operands in expression\n");
  exit(EXIT_FAILURE);
}

void push(int i) {
  if (is_full())
    stack_overflow();

  else
    contents[top++] = i;
}

int pop(void) {
  if (is_empty()) {
    stack_underflow();
    return 0;
  }
  return contents[--top];
}
rs *and operands.* /

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

    /* --- プロトタイプ宣言 --- */
    void make_empty(void);
bool is_empty(void);
bool is_full(void);
void stack_overflow(void);

void stack_underflow(void);
void push(int i);
int pop(void);
int evaluate_RPN_expression(const char *expression);

/* --- 外部変数 --- */
int contents[STACK_SIZE];
int top = 0;

/* --- main関数 --- */
int main(void) {
  char ch;
  char expression[100];
  int i;

  for (;;) {
    printf("Enter an RPN expression: ");
    i = 0;
    for (;;) {
      if (scanf(" %c", &ch) != 1)
        break;

      if (!isdigit((unsigned char)ch) && ch != '+' && ch != '-' && ch != '*' &&
          ch != '/' && ch != '=') {
        return 0;
      }

      expression[i++] = ch;

      if (ch == '=') {

        expression[i] = '\0';

        printf("Value of expression: %d\n",
               evaluate_RPN_expression(expression));
        break;
      }
    }
  }
  return 0;
}

/* --- 関数の定義（中身） --- */

int evaluate_RPN_expression(const char *expression) {
  int op1, op2;
  make_empty();

  while (*expression) {

    if (isdigit((unsigned char)*expression)) {
      push(*expression - '0');
    } else if (*expression == '+') {

      push(pop() + pop());
    } else if (*expression == '-') {
      op2 = pop();
      op1 = pop();
      push(op1 - op2);
    } else if (*expression == '*') {
      push(pop() * pop());

    } else if (*expression == '/') {

      op2 = pop();
      op1 = pop();
      push(op1 / op2);
    } else if (*expression == '=') {
      return pop();
    }
    expression++;
  }
  return 0;
}

void make_empty(void) { top = 0; }
bool is_empty(void) { return top == 0; }
bool is_full(void) { return top == STACK_SIZE; }

void stack_overflow(void) {
  printf("Expression is too complex\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void) {
  printf("Not enough operands in expression\n");
  exit(EXIT_FAILURE);
}

void push(int i) {
  if (is_full())
    stack_overflow();

  else
    contents[top++] = i;
}

int pop(void) {
  if (is_empty()) {
    stack_underflow();
    return 0;
  }
  return contents[--top];
}
