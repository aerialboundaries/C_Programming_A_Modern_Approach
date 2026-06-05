#include <stdio.h>

#include "queueADT.h"

int main(void)
{
  Queue q1 = create();
  Queue q2 = create();

  enqueue(q1, 10);
  enqueue(q1, 20);
  enqueue(q1, 30);
  enqueue(q1, 40);
  enqueue(q1, 50);

  printf("dequeue from q1: %d\n", dequeue(q1));
  printf("dequeue from q1: %d\n", dequeue(q1));
  printf("dequeue from q1: %d\n", dequeue(q1));
  printf("peek_head from q1: %d\n", peek_head(q1));
  printf("peek tail from q1: %d\n", peek_tail(q1));

  printf("q1 is %s\n", is_empty(q1) ? "empty." : "not empty");

  make_empty(q1);
  printf("q1 is %s\n", is_empty(q1) ? "empty." : "not empty");

  enqueue(q2, 500);
  enqueue(q2, 600);
  enqueue(q2, 700);
  printf("peek_head from q2: %d\n", peek_head(q2));
  printf("peek tail from q2: %d\n", peek_tail(q2));

  printf("dequeue from q2: %d\n", dequeue(q2));
  printf("dequeue from q2: %d\n", dequeue(q2));
  printf("dequeue from q2: %d\n", dequeue(q2));

  printf("q2 is %s\n", is_empty(q2) ? "empty." : "not empty");

  destroy(q1);
  destroy(q2);

  return 0;
}
