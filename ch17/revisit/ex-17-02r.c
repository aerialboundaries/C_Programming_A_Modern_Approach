/* C_Programming_A_Modern_Approach
 * ex-17-02.c
 * 2026-04-23, 2026-11-22
 *
 * Write a function named duplicate that uses dynamic storage allocation to
 * create a copy of a string. For example, the call p = duplicate(str); would
 * allocate space for a string of the same length as str, copy the contents of
 * str into the new string, and return a pointer to it. Have duplicate return a
 * null pointer if the memory allocation fails.
 */

#include <stdlib.h>
#include <string.h>

void *duplicate(const char *s)
{
  char *tmp = malloc(strlen(s) + 1);
  if (tmp == NULL) {
    return NULL;
  }

  strcpy(tmp, s);
  return tmp;
}

int main(void) { return 0; }
