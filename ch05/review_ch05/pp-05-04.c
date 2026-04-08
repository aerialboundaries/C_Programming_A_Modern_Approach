/* C Programming A Modern Approach pp5-4.c
 * 2026-04-07 revisit
 *
 * Here's a simplified version of the Beaufort scale, which is useed to estimate
 * wind force:
 *
 * Speed(Knots)         Description
 * Less than 1          Calm
 * 1-3                  Light air
 * 4-27                 Breeze
 * 28-47                Gale
 * 48-63                Storm
 * Above 63             Hurricane
 *
 * Write a aprogram that ask the user to enter a wind speed (in knowts), then
 * displays the corresponding description.
 *
 */
#include <stdio.h>

int main(void) {
  int wspeed;

  printf("Enter a wind speed: ");
  scanf("%d", &wspeed);

  printf("Description: ");

  if (wspeed < 1) {
    printf("Calm\n");
  } else if (wspeed <= 3) {
    printf("Light air\n");
  } else if (wspeed <= 27) {
    printf("Breeze\n");
  } else if (wspeed <= 47) {
    printf("Gale\n");
  } else if (wspeed <= 63) {
    printf("Storm\n");
  } else {
    printf("Hurricane\n");
  }

  return 0;
}
