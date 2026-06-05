#include <stdio.h>
#include <stdlib.h>

#include "queueADT.h"

#define QUEUE_SIZE 10

struct queue_type {
  Item contents[QUEUE_SIZE];
  int head;
  int tail;
  int size;
};

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Queue create(void)
{
  Queue q = malloc(sizeof(struct queue_type));
  if (q == NULL)
    terminate("Error in create: queue could not be created.");
  q->head = q->tail = 0;
  q->size = 0;
  return q;
}

void destroy(Queue q)
{
  free(q);
}

bool is_empty(Queue q)
{
  return q->size == 0;
}

bool is_full(Queue q)
{
  return q->size == QUEUE_SIZE;
}

void make_empty(Queue q)
{
  q->head = q->tail = 0;
  q->size = 0;
}

void enqueue(Queue q, Item i)
{
  if (is_full(q))
    terminate("Error in enqueue: queue is full.");
  q->contents[q->tail] = i;
  q->tail = (q->tail + 1) % QUEUE_SIZE;
  q->size++;
}

Item dequeue(Queue q)
{
  Item i;
  if (is_empty(q))
    terminate("Error in dequeue: queue is empty.");
  i = q->contents[q->head];
  q->head = (q->head + 1) % QUEUE_SIZE;
  q->size--;
  return i;
}

Item peek_head(Queue q)
{
  if (is_empty(q))
    terminate("Error in peek_head: queue is empty.");
  return q->contents[q->head];
}

Item peek_tail(Queue q)
{
  if (is_empty(q))
    terminate("Error in peek_tail: queue is empty.");

  int last_idx = (q->tail - 1 + QUEUE_SIZE) % QUEUE_SIZE;
  return q->contents[last_idx];
}
