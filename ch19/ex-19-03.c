/* C_Programming_A_Modern_Approach
ex-19-03.c
2026-05-19

(a) Write an array based implementation of the queue module described in
Exercise 1. Use three integers to keep track of the queue's status, with one
integer storing the position of the first empty slot in the array (used when an
item is inserted), the second storing the position of the next item to be
removed, and the third storing the number of items in the queue. An insertion or
removal that would cause either of the first two integers to be incremented past
the end of the array should instead reset the variable to zero, thus causing it
to "wrap around" to the beginning of the array.

(b) Write a linked-list implementation of the queue module described in
Exercise 1. Use two pointers, one pointing to the first node in the list and the
other pointing to the last node. When an item is inserted into the queue, add it
to the end of the list. When an item is removed from the queue, delete the first
node in the list.

*/

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

/* queue_array.c */
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

#define QUEUE_SIZE 100

static Item contents[QUEUE_SIZE];
static int first_empty = 0;
static int next_item = 0;
static int num_items = 0;

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void make_empty(void)
{
    first_empty = 0;
    next_item = 0;
    num_items = 0;
}

bool is_empty(void)
{
    return num_items == 0;
}

bool is_full(void)
{
    return num_items == QUEUE_SIZE;
}

void insert(Item i)
{
    if (is_full()) {
        terminate("Error in insert: queue is full.");
    }

    contents[first_empty] = i;

    // wrap around if exceeds the last of array
    first_empty++;
    if (first_empty == QUEUE_SIZE) {
        first_empty = 0;
    }

    num_items++;
}

Item remove_item(void)
{
    Item i;

    if (is_empty()) {
        terminate("Error in remove_item: queue is empty.");
    }

    i = contents[next_item];

    // wrap around
    next_item++;
    if (next_item == QUEUE_SIZE) {
        next_item = 0;
    }

    num_items--;
    return i;
}

/* (b) implimentation by linked list */
/* queue_list.c */
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

struct node {
    Item data;
    struct node *next;
};

static struct node *head = NULL;
static struct node *tail = NULL;

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void make_empty(void)
{
    while (!is_empty()) {
        remove_item();
    }
}

bool is_empty(void)
{
    return head == NULL;
}

bool is_full(void)
{
    return false;
}

void insert(Item i)
{
    struce node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        terminate("Error in insert: queue is full.");
    }

    new_node->date = i;
    new_node->next = NULL;

    if (is_empty()) {
        // if data exists put to the last and update tail pointer
        tail->next = new_node;
        tail = new_node;
    }
}

Item remove_item(void)
{
    struct node *old_head;
    Item i;

    if (is_empty()) {
        terminate("Error in remove_item: queue is empty.");
    }
    old_head = head;
    i = head->data;
    head = head->next;

    // if queue is empty as a result of removing head, make tail pointer NULL
    if (head == NULL) {
        tail = NULL;
    }

    free(old_head);
    return i;
}

/* main.c */
#include <stdio.h>

#include "queue.h"

int main(void)
{
    printf("--- Queue Test Start ---\n");

    insert(10);
    insert(20);
    insert(30);

    // Output should be 10 and 20
    printf("Removed %d\n", remove_item());
    printf("Removed %d\n", remove_item());

    insert(40);
    insert(50);

    // Remove all the rest
    while (!is_empty()) {
        printf("Removed remaining: %d\n", remove_item());
    }

    rturn 0;
}
