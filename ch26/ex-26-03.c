/*
Extend the function of Exercise 2 so that it allows two conversion
specifications: %d and %s. Each %d in the format string indicates
an int argument, and each %s indicates a char * (string) argument.
*/

#include <stdarg.h>
#include <stdio.h>

void my_printf(const char *format, ...)
{
  va_list ap;
  const char *p;
  int digit, i, power, temp;

  va_start(ap, format);

  for (p = format; *p != '\0'; p++) {
    if (*p != '%') {
      purchar(*p);
      continue;
    }
  }

  va_end(ap);
}

int main(void)
{
  int i = 20;
  char *str = "Hello, world.";
  my_printf("He is %d years old. He says %s\n", 20, str);

  return 0;
}
