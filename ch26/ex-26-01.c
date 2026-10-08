/*
Rewrite the max_int function so that, instead of passing the number of
integers as the first argument, we must supply 0 as the last argument.
Hint:_ max_int must have at least one "normal" parameter, so you can't
remove the parameter n. Instead, assume that it represents one of the
numbers to be compared.
*/

#include <stdarg.h>
#include <stdio.h>

int max_int(int n, ...)
{
  va_list ap;
  int current, largest;

  va_start(ap, n);
  largest = n;

  current = va_arg(ap, int);

  while (current != 0) {
    if (current > largest)
      largest = current;
    current = va_arg(ap, int);
  }

  va_end(ap);
  return largest;
}

int main(void)
{

  printf("largest = %d\n", max_int(10, 30, 20, 0));
  printf("largest = %d\n", max_int(-5, -10, 15, -2, 0));

  return 0;
}
