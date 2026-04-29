/* C Programming A Modern Approach
 * ex-17-14.c
 * 2026-04-29
 *
 * Modify the delete_from_list function (Section 17.5) so that its first
parameter has
 * type struct node ** (a pointer to a pointer to the first node in a list) and
its return type is
 * void. delete from list must modify its first argument to point to the list
after the
 * desired node has been deleted.

struct node *delete_from_list (struct node *list, int n)
{
struct node *cur, *prev;

  for (cur = list, prev = NULL;
  cur != NULL && cur->value != n;
  prev = cur, cur = cur->next)

  if (cur == NULL)
    return list;  // n was not found
  if (prev == NULL)
    list = list->next;  // n is in the first node
  else
    prev->next = cur->next; // n is in some other node
  free (cur);
  return list;

 */

void delete_from_list(struct node **list, int n)
{
    struct node *cur, *prev;

    for (cur = *list, prev = NULL; cur != NULL && cur->value != n;
         prev = cur, cur = cur->next)
        ;

    if (cur == NULL)
        return; // n was not found
    if (prev == NULL)
        // *list（呼び出し元のポインタ変数の中身）を直接書き換える
        *list = (*list)->next; // n is in the first node
    else
        prev->next = cur->next; // n is in some other node
    free(cur);
}
