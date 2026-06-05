#include <stdio.h>

#include "stackADT.h"

int main(void)
{
  Stack s1 = create(10), s2 = create(5);
  push(s1, 10);
  push(s1, 20);
  push(s1, 20);
  printf("Popped from s1: %d\n", pop(s1));
  printf("Popped from s1: %d\n", pop(s1));
  printf("Popped from s1: %d\n", pop(s1));
  if (is_empty(s1))
    printf("s1 is empty.\n");

  push(s2, 100);
  push(s2, 200);
  push(s2, 300);
  printf("Popped from s2: %d\n", pop(s2));
  printf("Popped from s2: %d\n", pop(s2));

  if (is_empty(s2))
    printf("s2 is empty.\n");
  else
    printf("s2 is not empty.\n");

  destroy(s1);
  destroy(s2);

  return 0;
}
