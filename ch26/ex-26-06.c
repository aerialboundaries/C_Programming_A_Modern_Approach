/*
Write the following function:

   char *max_pair(int num_pairs, ... );

The arguments of max_pair are assumed to be "pairs" of integers and strings;
the value of num_pairs indicates how many pairs will follow.
(A pair consists of an int argument followed by a char * argument).
The function searches the integers to find the largest one;
it then returns the string argument that follows it. Consider the following
call:

   max_pair(5, 180, "Seinfeld", 180, "I Love Lucy",
   39, "The Honeymooners", 210, "All in the Family",
   86, "The Sopranos")

The largest int argument is 210, so the function returns "All in the Family",
which follows it in the argument list.
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

char *max_pair(int num_pairs, ...)
{
  if (num_pairs <= 0)
    return NULL;

  va_list ap;
  va_start(ap, num_pairs);

  // initialize with the 1st pair
  int max_num = va_arg(ap, int);
  char *max_str = va_arg(ap, char *);

  // compare the rest
  for (int i = 1; i < num_pairs; i++) {
    int current_num = va_arg(ap, int);
    char *current_str = va_arg(ap, char *);

    if (current_num > max_num) {
      max_num = current_num;
      max_str = current_str;
    }
  }

  va_end(ap);

  return max_str;
}

int main(void)
{
  char *result;

  result =
      max_pair(5, 180, "Seinfeld", 180, "I Love Lucy", 39, "The Honeymooners",
               210, "All in the Family", 86, "The Sopranos");

  if (result != NULL)
    printf("%s\n", result);

  return 0;
}
