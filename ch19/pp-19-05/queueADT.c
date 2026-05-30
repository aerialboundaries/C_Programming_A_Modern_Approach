/* queueADT.c */

struct queue_type {};

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
