/* C_Programming_A_Modern_Approach
 * ex-17-02.c
 * 2026-04-23
 *
 * Write a function named duplicate that uses dynamic storage allocation to
 * create a copy of a string. For example, the call p = duplicate(str); would
 * allocate space for a string of the same length as str, copy the contents of
 * str into the new string, and return a pointer to it. Have duplicate return a
 * null pointer if the memory allocation fails.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************** My Answer ************************************/

void *duplicate(const char *s)
{
    char *temp = malloc(strlen(s) + 1);
    if (temp == NULL) {
        return NULL;
    }

    strcpy(temp, s);
    return temp;
}

/*****************************************************************************/

int main(void)
{
    return 0;
}
