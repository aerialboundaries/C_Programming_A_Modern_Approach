#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "operate.h"
#include "stack.h"
#include "token.h"

extern Stack *top;

void input(void)
{
  char str[BUFFER];

  printf("Enter RPN Expression: ");
  if (fgets(str, sizeof(str), stdin) == NULL) {
    putchar('\n');
    exit(EXIT_SUCCESS);
  }
  str[strcspn(str, "\n")] = '0';

  size_t len = strlen(str);

  for (size_t i = 0; i < len; i++) {
    parse_input(str[i]);
  }
}

void parse_input(char ch)
{
  void (*operation[])(void) = { plus, minus, multi, divi };
  unsigned char uch = (unsigned char)ch;

  if (isspace(uch)) {
    return;
  }

  if (isdigit(uch)) {
    push(ch - '0');
    return;
  }

  switch (ch) {
  case '+':
    (*operation[PLUS])();
    break;
  case '-':
    (*operation[MINUS])();
    break;
  case '*':
    (*operation[MULTI])();
    break;
  case '/':
    (*operation[DIV])();
    break;
  case '=':
    if (is_empty()) {
      fprintf(stderr, "Error: stack is empty.\n");
      exit(EXIT_FAILURE);
    }
    printf("%d\n", top->content);
    break;
  default:
    fprintf(stderr, "not a command. exiting.\n");
    exit(EXIT_FAILURE);
  }
}
