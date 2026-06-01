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
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    terminate("Error in insert: queue is full.");
  }

  new_node->data = i;
  new_node->next = NULL;

  if (is_empty()) {
    // キューが空なら、最初のノードが先頭かつ末尾になります
    head = new_node;
    tail = new_node;
  } else {

    // すでにデータがあるなら、現在の末尾の後ろに繋いで、tailを更新します
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

  // 要素を取り出した結果、キューが空になったら、tailもNULLに戻します
  if (head == NULL) {
    tail = NULL;
  }

  free(old_head);
  return i;
}
