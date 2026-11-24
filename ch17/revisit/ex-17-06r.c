/* C_Programming_A_Modern_Approach
 * ex-17-06.c
 * 2026-04-24, 2026-11-24
 *
 * Modify the delete_from_list function so that it uses only one pointer
 * variable instead of two (cur and prev).
 */

#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

struct node *delete_from_list(struct node *list, int n)
{
  struct node *cur;

  // 1. if list is null
  if (list == NULL)
    return NULL;

  // 2. to delete the first node
  if (list->value == n) {
    cur = list; // store delete target
    list = list->next;
    free(cur);
    return list;
  }

  // 3. other
  for (cur = list; cur->next != NULL && cur->next->value != n; cur = cur->next)
    ;

  if (cur->next == NULL)
    return list; // n was not found
  else {
    struct node *temp = cur->next; // store delete target
    cur->next = cur->next->next;   // n is in some other node
    free(temp);
  }
  return list;
}
