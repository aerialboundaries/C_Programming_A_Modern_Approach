#include <ctype.h>
#include <stdbool.h>

#include "stack.h"
#include "token.h"

int parse_input(char ch)
{
  if (isdigit(ch)) {
    push(ch - '\0');
  }

  switch (ch) {
  case '+':
    return PLUS;
  case '-':
    return MINUS;
  case '*':
    return MULTI;
  case '/':
    return DIV;
  case '=':
    return EQ;
  default:
    return OTHER;
  }
}
