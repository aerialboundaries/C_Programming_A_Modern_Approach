#include <stdio.h>
#include <stdlib.h>

#include "queueADT.h"

struct node {
  Item data;
  struct node *next;
};

struct queue_type {
  struct node *head;
  struct node *tail;
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
  q->head = q->tail = NULL;
  q->size = 0;

  return q;
}

void destroy(Queue q)
{
  make_empty(q);
  free(q);
}

bool is_empty(Queue q)
{
  return q->size == 0;
}

bool is_full(Queue q)
{
  (void)q;
  return false;
}

void make_empty(Queue q)
{
  while (!is_empty(q))
    dequeue(q);
}

void enqueue(Queue q, Item i)
{
  if (is_full(q))
    terminate("Error in enqueue: queue is full.");
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL)
    terminate("Error in enqueue: queue is full.");
  new_node->data = i;
  new_node->next = NULL;

  if (is_empty(q)) {
    q->head = new_node;
  } else {
    q->tail->next = new_node;
  }
  q->tail = new_node;
  q->size++;
}

Item dequeue(Queue q)
{
  if (is_empty(q))
    terminate("Error in dequeue: queue is empty.");
  struct node *old_node = q->head;
  Item i = old_node->data;

  q->head = old_node->next;
  if (q->head == NULL)
    q->tail = NULL;

  free(old_node);
  q->size--;
  return i;
}

Item peek_head(Queue q)
{
  if (is_empty(q))
    terminate("Error in peek_head: queue is empty.");
  return q->head->data;
}

Item peek_tail(Queue q)
{
  if (is_empty(q))
    terminate("Error in peek_tail: queue is empty.");

  return q->tail->data;
}
