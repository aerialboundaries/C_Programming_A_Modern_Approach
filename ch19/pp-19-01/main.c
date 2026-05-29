/* C Programming A Modern Approach
 * pp-19-01.c
 * 2026-05-29
 *
 * Modify Programming Project 1 from Chapter 10 so that it uses the stack ADT
 * described in Section 19.4. You may use any of the implementations of the ADT
 * described in that section.
 */

/* C Programming A Modern Approach
 * pp-10-01.c
 * 2026-02-04
 *
 * Modify the stack example of Section 10.2 so that it stores characters
 * instead of integers. Next, add a main function that asks the user to
 * enter a series of parentheses and / or braces, then indicates whether
 * or not they're properly nested:
 *
 * Enter parentheses and/or braces: ((){}{()})
 * Parentheses/braces are nested properly
 *
 * Hint: As the program reads characters, have it push each left parenthesis
 * or left brace. When it reads a right parentheses or brace, have it
 * pop the stack and check that the item popped is a matching parentheses
 * or brace. (If not, the parentheses/brace aren't nested properly.)
 * When the program reads the new-line character, have it check whether
 * the stack is empty; if so, the parentheses/braces are matched.
 * If the stack isn't empty (or if stack_underflow is ever called),
 * the parentheses/braces aren't matched. If stack_overflow is called,
 * have the program prit the message Stack overflow and terminate immediately.*/

// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
//
// #define STACK_SIZE 100
//
// /* external variables */
// char contents[STACK_SIZE];
// int top = 0;
//
// void make_empty(void) { top = 0; }
//
// bool is_empty(void) { return top == 0; }
//
// bool is_full(void) { return top == STACK_SIZE; }
//
// void stack_overflow(void) {
//   printf("Stack Overflow\n");
//   exit(EXIT_FAILURE);
// }
//
// void push(char ch) {
//   if (is_full())
//     stack_overflow();
//   else
//     contents[top++] = ch;
// }
//
// char pop(void) {
//   if (is_empty()) {
//     /* in case right parentheses is more than left */
//     printf("Parentheses/braces aren't nested properly.\n");
//     return 1;
//   }
//   else
//     return contents[--top];
// }
//
// int main(void) {
//   int ch;
//   make_empty();
//
//   printf("Enter parentheses and/or braces: ");
//
//   while ((ch = getchar()) != '\n') {
//     switch (ch) {
//     case '(':
//     case '{':
//       push(ch);
//       break;
//     case ')':
//       if (pop() != '(') {
//         printf("Parentheses/braces aren't nested properly.\n");
//         exit(EXIT_SUCCESS);
//       } else
//         break;
//
//     case '}':
//       if (pop() != '{') {
//         printf("Parentheses/braces aren't nested properly.\n");
//         exit(EXIT_SUCCESS);
//       } else
//         break;
//
//     default:
//       printf("Wrong input\n");
//       exit(EXIT_FAILURE);
//     }
//   }
//   if (is_empty())
//     printf("Parentheses/braces are nested properly.\n");
//   else
//     printf("Parentheses/braces are'nt nested properly.\n");
//
//   return 0;
// }

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stackADT.h"

int main(void)
{
    int ch;
    Stack s1;
    s1 = create();

    printf("Enter parentheses and/or braces: ");

    while ((ch = getchar()) != '\n') {
        switch (ch) {
        case '(':
        case '{':
            push(s1, ch);
            break;
        case ')':
            if (pop(s1) != '(') {
                printf("Parentheses/braces aren't nested properly.\n");
                exit(EXIT_SUCCESS);
            } else
                break;

        case '}':
            if (pop(s1) != '{') {
                printf("Parentheses/braces aren't nested properly.\n");
                exit(EXIT_SUCCESS);
            } else
                break;

        default:
            printf("Wrong input\n");
            exit(EXIT_FAILURE);
        }
    }
    if (is_empty(s1))
        printf("Parentheses/braces are nested properly.\n");
    else
        printf("Parentheses/braces are'nt nested properly.\n");

    return 0;
}
