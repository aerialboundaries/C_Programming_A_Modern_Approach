#include <stdio.h>
#include <stdlib.h>

#include "queueADT.h"

struct node {
  Item i;
  int head;
  int tail;
  int size;
  struct node *next;
};

struct queue_type {
  struct node *top;
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
  q->top = NULL;

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
  return q->size == q->max_size;
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
  q->tail = (q->tail + 1) % q->max_size;
  q->size++;
}

Item dequeue(Queue q)
{
  Item i;
  if (is_empty(q))
    terminate("Error in dequeue: queue is empty.");
  i = q->contents[q->head];
  q->head = (q->head + 1) % q->max_size;
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

  int last_idx = (q->tail - 1 + q->max_size) % q->max_size;
  return q->contents[last_idx];
}
