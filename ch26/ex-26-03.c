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
  const char *p, *str;
  int digit, i, power, temp;

  va_start(ap, format);

  for (p = format; *p != '\0'; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }

    /* check the next char of % */
    p++;

    switch (*p) {
    case 'd':
      i = va_arg(ap, int);
      if (i < 0) {
        putchar('-');
        i = -i;
      }

      temp = i;
      power = 1;
      while (temp > 9) {
        temp /= 10;
        power *= 10;
      }

      do {
        digit = i / power;
        putchar(digit + '0');
        i -= digit * power;
        power /= 10;
      } while (power > 0);
      break;

    case 's':
      str = va_arg(ap, char *);
      while (*str != '\0') {
        putchar(*str);
        str++;
      }
      break;

    default:
      putchar('%');
      if (*p != '\0')
        putchar(*p);
      break;
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
