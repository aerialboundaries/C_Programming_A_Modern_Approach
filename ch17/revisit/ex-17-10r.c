/* C Programming A Modern Approach
 * ex-17-10.c
 * 2026-04-28
 *
 * Modify the print_part function of Section 16.2 so that its parameter is a
 * pointer to a part structure. Use the - > operator in your answer.
 */

#include <stdio.h>
typedef struct part {
  int number;
  char name[10];
  int on_hand;
} Part;

void print_part(struct part *p)
{
  printf("Part number: %d\n", p->number);
  printf("Part name: %s\n", p->name);
  printf("Quantity on hand: %d\n", p->on_hand);
}

int main(void)
{
  Part p1 = { 528, "Disk drive", 10 };
  print_part(&p1);
}
