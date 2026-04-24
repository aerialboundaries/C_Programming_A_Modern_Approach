/* C_Programming_A_Modern_Approach
 * ex-17-07.c
 * 2026-04-24
 *
 * The following loop is supposed to delete all nodes from a linked list and
 * release the memory that they occupy. Unfortunately, the loop is incorrect.
 * Explain what's wrong with it and show how to fix the bug.
 *
 * for (p = first; p != NULL; p = p->next)
 *   free (p);
 *
 *
 * KN's Answer
 * The first call of free will release the space for the first node in the list,
 * making p a dangling pointer. Executing p = p->next to advance to the next
 * node will have an undefined effect. Here's a correct way to write the loop,
 * using a temporary pointer that points to the node being deleted:
 *
 * struct node *temp;
 *
 * p = first;
 * while (p != NULL) {
 *   temp = p;
 *   p = p->next;
 *   free(temp);
 * }
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************** My Answer ************************************/

/*****************************************************************************/

int main(void)
{
    return 0;
}
