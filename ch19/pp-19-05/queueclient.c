/* queueclient.c */
#include <stdio.h>

#include "queueADT.h"

int main(void)
{
  Queue q1, q2;
  int n;

  q1 = create();
  q2 = create();

  // add data to q1
  printf("--- Testing q1 ---\n");
  enqueue(q1, 10);
  enqueue(q1, 20);
  enqueue(q1, 30);

  printf("q1 peek_first: %d\n", peek_first(q1)); // 10
  printf("q1 peek_last: %d\n", peek_last(q1));   // 30

  // Check removing by FIFO
  n = dequeue(q1);
  printf("Dequeued %d from q1\n", n); // 10
  n = dequeue(q1);
  printf("Dequeued %d from q1\n", n); // 20

  // Test adding data to q2
  printf("--- Testing q2 ---\n");
  enqueue(q2, 400);
  enqueue(q2, 500);

  if (!is_empty(q1))
    printf("q1 is not empty\n");

  printf("Dequeued %d from q2\n", dequeue(q2)); // 400
  printf("Dequeued %d from q2\n", dequeue(q2)); // 500

  if (is_empty(q2))
    printf("q1 is empty\n");

  // free memory
  destroy(q1);
  destroy(q2);

  printf("\nAll queue operations completed successfully!\n");

  return 0;
}
