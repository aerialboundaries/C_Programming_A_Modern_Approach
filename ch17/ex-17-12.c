/* C Programming A Modern Approach
 * ex-17-12.c
 * 2026-04-28
 *
 * Write the following function:
 * struct node *find_last (struct node *list, int n) ;
 * The list parameter points to a linked list. The function should return a pointer to the last
 * node that contains n; it should return NULL if n doesn't appear in the list. Assume that the
 * node structure is the one defined in Section 17.5.
 */

struct node *find_last (struct node *list, int n)
{
  struct node *p, *last_found = NULL;
  
  for (p = list; p != NULL; p = p->next) {
    if (p->value == n)
      last_found = p;
  }
  return last_found;
}
