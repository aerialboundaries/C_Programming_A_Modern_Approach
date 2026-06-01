#include <stdio.h>
#include <stdlib.h>

#include "queueADT.h"

struct queue_type {
  Item *contents;
  int head;
  int tail;
  int size; // elements in current queue
  int max;  // max elements
};

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Queue create(int size)
{
  Queue q = malloc(sizeof(struct queue_type));
  if (q == NULL)
    terminate("Error in create: queue could not be created.");
  q->contents = malloc(size * sizeof(Item));
  if (q->contents == NULL) {
    free(q);
    terminate("Error in create: queue could not be created.");
  }
  q->head = 0;
  q->tail = 0;
  q->size = 0; // size is 0 after create
  q->max = size;

  return q;
}

void destroy(Queue q)
{
  free(q->contents);
  free(q);
}

bool is_empty(Queue q)
{
  return q->size == 0;
}

bool is_full(Queue q)
{
  return q->size == q->max;
}

void enqueue(Queue q, Item i)
{
  if (is_full(q))
    terminate("Error in enqueue: queue is full.");

  // store date into current tail
  q->contents[q->tail] = i;

  // Advance tail by 1,if exceeds last, return to 0
  q->tail = (q->tail + 1) % q->max;

  // increment size by 1
  q->size++;
}

Item dequeue(Queue q)
{
  Item i;

  if (is_empty(q))
    terminate("Error in dequeue: queue is empty.");

  // remove date from current head
  i = q->contents[q->head];

  // Advance head by 1. If exceeds last, return to 0.
  q->head = (q->head + 1) % q->max;

  // decrease size by 1
  q->size--;

  return i;
}

Item peek_first(Queue q)
{
  if (is_empty(q))
    terminate("Error in peek_first: queue is empty.");
  return q->contents[q->head];
}

Item peek_last(Queue q)
{
  if (is_empty(q))
    terminate("Error in peek_last: queue is empty.");

  // tail points the place to put the data next time.
  // So, the last inserted data is 1 before tail.
  // In order not to be minus, add q->max and %
  int last_idx = (q->tail - 1 + q->max) % q->max;
  return q->contents[last_idx];
}
