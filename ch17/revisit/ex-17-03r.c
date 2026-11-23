/* C_Programming_A_Modern_Approach
 * ex-17-03.c
 * 2026-04-23
 *
 * Write the following function:
 * int *create_array(int n, int initial_value);
 * The function should return a pointer to a dynamically allocated int array
 * with n members, each of which is initialized to initial_value. The return
 * value should be NULL if the array can't be allocated.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************** My Answer ************************************/

int *create_array(int n, int initial_value)
{
    int *p = malloc(n * sizeof(int));
    if (p == NULL)
        return NULL;

    for (int i = 0; i < n; i++) {
        p[i] = initial_value;
    }
    return p;
}

/*****************************************************************************/

int main(void)
{
    return 0;
}
