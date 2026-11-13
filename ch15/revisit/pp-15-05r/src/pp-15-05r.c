#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

#define N 100
#define MAX_CHAR 100

int main(void)
{
  int stack[N];
  char str[MAX_CHAR];
  int top = 0, o1, o2;
  char *p = str;

  printf("Enter an RPN expression: ");
  if (fgets(str, sizeof(str), stdin) == NULL)
    return 0;
  str[strcspn(str, "\n")] = '\0';

  while (*p) {
    if (*p == ' ') {
      p++;
      continue;
    }

    if (*p == '=') {
      printf("Value of expression: %d\n", pop(stack, &top));
      return 0;
    }

    if (isdigit(*p)) {
      push(stack, &top, N, *p - '0');
    } else {

      switch (*p) {
      case '+':
        o1 = pop(stack, &top);
        o2 = pop(stack, &top);
        push(stack, &top, N, o2 + o1);
        break;

      case '-':
        o1 = pop(stack, &top);
        o2 = pop(stack, &top);
        push(stack, &top, N, o2 - o1);
        break;

      case '*':
        o1 = pop(stack, &top);
        o2 = pop(stack, &top);
        push(stack, &top, N, o2 * o1);
        break;

      case '/':
        o1 = pop(stack, &top);
        o2 = pop(stack, &top);
        if (o1 == 0) {
          fprintf(stderr, "division by 0\n");
          exit(EXIT_FAILURE);
        }
        push(stack, &top, N, o2 / o1);
        break;

      default:
        exit(EXIT_SUCCESS);
      }
    }
    p++;
  }

  return 0;
}
