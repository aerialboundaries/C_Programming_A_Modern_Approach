/* C Programming A Modern Approach pp5-4.c
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
  int ws;

  printf("Enter a wind speed: ");
  scanf("%d", &ws);

  if (ws >= 63)
    printf("Hurricane\n");
  else if (ws >= 48)
    printf("Storm\n");
  else if (ws >= 28)
    printf("Gale\n");
  else if (ws >= 4)
    printf("Breeze\n");
  else if (ws >= 1)
    printf("Light air\n");
  else
    printf("Calm\n");

  return 0;
}
