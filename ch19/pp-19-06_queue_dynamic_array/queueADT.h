// Modify Programming Project 5 so that the items in a queue are stored in a
// dynamically allocated array whose length is passed to the create function.

#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef struct queue_type *Queue;
typedef int Item;

Queue create(int size);
void destroy(Queue q);
bool is_empty(Queue q);
bool is_full(Queue q);
void enqueue(Queue q, Item i);
Item dequeue(Queue q);
Item peek_first(Queue q);
Item peek_last(Queue q);

#endif
