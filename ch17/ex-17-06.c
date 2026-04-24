/* C_Programming_A_Modern_Approach
 * ex-17-06.c
 * 2026-04-24
 *
 * Modify the delete_from_list function so that it uses only one pointer
 * variable instead of two (cur and prev).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************** My Answer ************************************/
struct node *delete_from_list(struct node *list, int n)
{
    struct node *cur;

    // 1. if list is null
    if (list == NULL)
        return NULL;

    // 2. to delete the first node
    if (list->value == n) {
        cur = list; // store the delete target
        list = list->next;
        free(cur);
        return list;
    }

    // 3. other

    for (cur = list; cur->next != NULL && cur->next->value != n;
         cur = cur->next)
        ;

    if (cur->next == NULL)
        return list; // n was not found
    else {
        struct node *temp = cur->next;
        cur->next = cur->next->next; // n is in some other node
        free(temp);
    }
    return list;
}

/*****************************************************************************/

int main(void)
{
    return 0;
}
