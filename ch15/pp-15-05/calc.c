/* C Programming A Modern Approach
 * pp-10-06.c
 * 2026-02-11 modified 2026-03-26
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

#include "stack.h"

#define STACK_SIZE 100

void calc(char ch);

int main(void)
{
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

void calc(char ch)
{
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
