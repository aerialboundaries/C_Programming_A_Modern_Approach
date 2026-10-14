/*
Convert the following calls of atoi, atol, and atoll into calls of strtol,
strtol, and strtoll, respectively. (a) atoi (str) (b) atol (str) (c) atoll(str)
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char *str = "1000";
  int i;
  long l;
  long long ll;

  //(a)
  i = (int)strtol(str, NULL, 10);
  //(b)
  l = strtol(str, NULL, 10);
  //(c)
  ll = strtoll(str, NULL, 10);

  printf("%d %ld %lld\n", i, l, ll);

  return 0;
}
