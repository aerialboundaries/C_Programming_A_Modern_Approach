/*
Write a statement that randomly assigns one of the numbers 7, 11, 15, or 19 to
the variable n.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  srand((unsigned)time(NULL));
  int index = rand() % 4;
  int numbers[4] = { 7, 11, 15, 19 };
  int result = numbers[index];
  printf("%d\n", result);

  return 0;
}
