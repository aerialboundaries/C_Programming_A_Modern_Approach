#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef struct queue_type *Queue;
typedef int Item;

Queue create(void);
void destroy(Queue q);
bool is_empty(Queue q);
bool is_full(Queue q);
void make_empty(Queue q);
void enqueue(Queue q, Item i);
Item dequeue(Queue q);
Item peek_head(Queue q);
Item peek_tail(Queue q);

#endif
