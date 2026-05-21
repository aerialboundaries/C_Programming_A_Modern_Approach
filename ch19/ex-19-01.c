/* C_Programming_A_Modern_Approach
ex-19-01.c
2026-05-19

A queue is similar to a stack, except that items are added at one end but
removed from the other in a FIFO (first-in, first-out) fashion. Operations on a
queue might include:
  Inserting an item at the end of the queue
  Removing an item from the beginning of the queue
  Returning the first item in the queue (without changing the queue)
  Returning the last item in the queue (without changing the queue)
  Testing whether the queue is empty
Write an interface for a queue module in the form of a header file named
queue.h.
*/

/* queue.h */
#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

// data type to store in queue
typedef int Item;

// incomplete declaration of queue structure
typedef struct queue_type *Queue;

// function to create queue
Queue create(void);

// function to destroy and free memory
void destroy(Queue q);

// add item to the last of queue (Insert)
void enqueue(Queue q, Item i);

// Remove item from top of queue (Remove)
// The oldest item is returned and deleted from queue
Item dequeue(Queue q);

// peek first item (Return first)
// return the oldest item, but not delete
Item peek_first(Queue q);

// peek the last item (Return last)
// returns the latest item, but not delete
Item peek_last(Queue q);

// test if the queue is empty (Test empty)
// if empty returns true, if not false
bool is_empty(Queue q);

#endif
