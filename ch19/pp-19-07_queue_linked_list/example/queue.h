/* queue.h */
#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int Item;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void insert(Item i);

Item remove_item(void);

#endif
