/*****************************************************************************
 * C Programming A Modern Approac                                            *
 * ex08-03.c                                                                 *
 * 2025-11-22                                                                *
 *
 * Write a declaration of an array named weekend containing seven bool       *
 * values. Include an initializer that makees the first and last values      *
 * true; all other values should be false.                                   *
 *                                                                           *
 ****************************************************************************/

#include <stdbool.h>
#include <stdio.h>

int main(void) {

  bool weekend[7] = {true, false, [6] = true};

  for (int i = 0; i <= 6; i++)
    printf("%d\n", weekend[i]);

  return 0;
}
