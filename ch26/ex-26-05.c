/*
Write the following function:

   char *vstrcat (const char *first, ... );

All arguments of vstrcat are assumed to be strings, except for the last
argument, which must be a null pointer (cast to char * type). The function
returns a pointer to a dynamically allocated string containing the concatenation
of the arguments. vstrcat should return a null pointer if not enough memory is
available. Hint: Have vstrcat go through the arguments twice: once to determine
the amount of memory required for the returned string and once to copy the
arguments into the string.
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *vstrcat(const char *first, ...)
{
  va_list ap;
  const char *s;
  size_t total_len = 0;
  char *result;

  if (first == NULL) {
    result = malloc(1);
    if (result != NULL) {
      result[0] = '\0';
    }
    return result;
  }

  // First loop to calculate total memory lenghth
  total_len = strlen(first);

  va_start(ap, first);
  while ((s = va_arg(ap, const char *)) != NULL) {
    total_len += strlen(s);
  }
  va_end(ap);

  // malloc total string length and '\0'
  result = malloc(total_len + 1);
  if (result == NULL) {
    return NULL;
  }

  // 2nd loop to copy and concatenate
  strcpy(result, first);

  va_start(ap, first);
  while ((s = va_arg(ap, const char *)) != NULL) {
    strcat(result, s);
  }

  va_end(ap);

  return result;
}

int main(void)
{
  char *concat;

  concat = vstrcat("This", "is", "a", "pen", NULL);
  if (concat != NULL) {
    printf("%s\n", concat);
    free(concat);
  }

  return 0;
}
