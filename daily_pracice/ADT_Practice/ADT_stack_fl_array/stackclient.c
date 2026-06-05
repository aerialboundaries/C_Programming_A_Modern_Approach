#include <stdio.h>

#include "stackADT.h"

int main(void)
{
  Stack s1 = create();
  Stack s2 = create();

  push(s1, 10);
  push(s1, 20);
  push(s1, 30);
  push(s2, 300);
  push(s2, 400);
  push(s2, 500);

  printf("Popped from s1 %d\n", pop(s1));

  while (!is_empty(s1)) {
    printf("Printing rest of s1: %d\n", pop(s1));
  }

  destroy(s1);

  printf("Popped from s2 %d\n", pop(s2));
  make_empty(s2);
  if (is_empty(s2))
    printf("s2 is empty.\n");
  else
    printf("s2 is not empty\n");

  destroy(s2);

  return 0;
}
