/* queueADT.c */
#include <stdio.h>
#include <stdlib.h>

#include "queueADT.h"

#define QUEUE_SIZE 5

struct queue_type {
  int contents[QUEUE_SIZE];
  int head;
  int tail;
  int size; // control number of elements in queue
};

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

// function to create queue
Queue create(void)
{
  Queue q = malloc(sizeof(struct queue_type));
  if (q == NULL)
    terminate("Error in create: queue could not be crerated.");
  q->head = 0;
  q->tail = 0;
  q->size = 0; // Initially 0
  return q;
}

// function to destroy and free memory
void destroy(Queue q)
{
  free(q);
}

// add item to the last of queue (Insert)
void enqueue(Queue q, Item i)
{
  if (q->size == QUEUE_SIZE)
    terminate("Error in enqueue: queue is full.");
  q->contents[q->tail] = i;
  // Advance tail by 1.  If exceeds last, return to 0;
  q->tail = (q->tail + 1) % QUEUE_SIZE;
  q->size++;
}

// Remove item from top of queue (Remove)
// The oldest item is returned and deleted from queue
Item dequeue(Queue q)
{
  Item i;

  if (is_empty(q))
    terminate("Error in dequeue: queue is empty.");
  i = q->contents[q->head];
  // Advance head by 1, if exceeds last, return to 0
  q->head = (q->head + 1) % QUEUE_SIZE;
  q->size--;

  return i;
}

// peek first item (Return first)
// return the oldest item, but not delete
Item peek_first(Queue q)
{
  if (is_empty(q))
    terminate("Error in peek_first: queue is empty.");
  return q->contents[q->head];
}

// peek the last item (Return last)
// returns the latest item, but not delete
Item peek_last(Queue q)
{
  if (is_empty(q))
    terminate("Error in peek_last: queue is empty.");

  // The last inserted data is 1 before the tail
  int last_idx = (q->tail - 1 + QUEUE_SIZE) % QUEUE_SIZE;
  return q->contents[last_idx];
}

// test if the queue is empty (Test empty)
// if empty returns true, if not false
bool is_empty(Queue q)
{
  return q->size == 0;
}
