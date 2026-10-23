/* C Programming A Modern Approach pp5-4.c
 * 2026-04-07 revisit
 * 2026-10-23 revisit
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

int main(void)
{
  int wind_speed;

  printf("Enter wind speed: ");
  if (scanf("%d", &wind_speed) != 1) {
    fprintf(stderr, "wrong input\n");
    return 1;
  }

  if (wind_speed < 1)
    printf("Calm\n");
  else if (wind_speed <= 3)
    printf("Light air\n");
  else if (wind_speed <= 27)
    printf("Breeze\n");
  else if (wind_speed <= 47)
    printf("Gale\n");
  else if (wind_speed <= 63)
    printf("Storm\n");
  else
    printf("Hurricane\n");

  return 0;
}
