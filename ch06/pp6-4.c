/* C Programming A Modern Approach pp6-4.c
 * 2025-11-7
 *
 * Add a loop to the broker.c program of Section 5.2 so that the user
 * can enter more than one trade and the program will calculate the
 * commission on each. The program should terminate when the user
 * enters 0 as the trade value:
 *
 * Enter value of trade: 30000
 * Commision: $166l00
 *
 * Enter value of trade 20000
 * Commision: $144.00
 *
 * Enter value of trade: 0
 */

/* C Programming A Modern Approach Ch-5 exmample
 * Calculates a broker's commision */

#include <stdio.h>

int main(void) {
  float commision, value;

  for (;;) {
    printf("Enter value of trade: ");
    scanf("%f", &value);
    if (value == 0)
      break;

    if (value < 2500.00f)
      commision = 30.00f + .017f * value;
    else if (value < 6250.00f)
      commision = 56.00f + .0066f * value;
    else if (value < 20000.00f)
      commision = 76.00f + .0034f * value;
    else if (value < 50000.00f)
      commision = 100.00f + .0022f * value;
    else if (value < 500000.00f)
      commision = 155.00f + .0011f * value;
    else
      commision = 255.00f + .0009f * value;

    if (commision < 39.00f)
      commision = 39.00f;

    printf("Commision: $%.f\n", commision);
  }
  return 0;
}
