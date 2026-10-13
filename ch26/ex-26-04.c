/*
Write a function named display that takes any number of arguments. The first
argument must be an integer. The remaining arguments will be strings.
The first argument specifies how many strings the call contains. The function
will print the strings on a single line, with adjacent strings separated by
one space. For example, the call

   display(4, "Special", "Agent", "Dale", "Cooper");

   will produce the following output:

   Special Agent Dale Cooper
*/

#include <stdarg.h>
#include <stdio.h>

void display(int n, ...)
{
  if (n <= 0) {
    putchar('\n');
    return;
  }

  int i;
  const char *str;

  va_list ap;

  va_start(ap, n);

  for (i = 0; i < n; i++) {
    str = va_arg(ap, char *);

    if (i > 0) {
      putchar(' ');
    }

    fputs(str, stdout);
  }

  va_end(ap);
  printf("\n");
}

int main(void)
{
  display(4, "Special", "Agent", "Dale", "Cooper");

  return 0;
}
