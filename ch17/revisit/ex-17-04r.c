/* C_Programming_A_Modern_Approach
 * ex-17-04.c
 * 2026-04-24, 2026-11-24
 *
 * Suppose that the following declarations are in effect:
 * struct point { int x, y; };
 * struct rectangle { struct point upper_left, lower_right; };
 * struct rectangle *p;
 *
 * Assume that we want p to point to a rectangle structure whose upper left
 * corner is at (10, 25) and whose lower right corner is at (20, 15). Write a
 * series of statements that allocate such a structure and initialize it as
 * indicated.
 */

#include <stdio.h>
#include <stdlib.h>

struct point {
  int x, y;
};

struct rectangle {
  struct point upper_left, lower_right;
};

int main(void)
{
  struct rectangle *p;
  p = malloc(sizeof(struct rectangle));
  if (p == NULL)
    return 1;

  p->upper_left.x = 10;
  p->upper_left.y = 25;
  p->lower_right.x = 20;
  p->lower_right.y = 15;
  printf("Upper left: (%d, %d)\n"
         "Lower right: (%d, %d)\n",
         p->upper_left.x, p->upper_left.y, p->lower_right.x, p->lower_right.y);

  free(p);

  return 0;
}
