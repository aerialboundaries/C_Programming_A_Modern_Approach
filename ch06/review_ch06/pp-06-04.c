/* C Programming A Modern Approach pp6-4.c
 * 2025-11-7 revisit 2026-04-08 2026-10-26
 *
 * Add a loop to the broker.c program of Section 5.2 so that the user
 * can enter more than one trade and the program will calculate the
 * commission on each. The program should terminate when the user
 * enters 0 as the trade value:
 *
 * Enter value of trade: 30000
 * commission: $166.00
 *
 * Enter value of trade 20000
 * commission: $144.00
 *
 * Enter value of trade: 0
 */

/* Calculates a broker's commission */

#include <stdio.h>

int main(void)
{
  float commission, value;
  char next_char;

  for (;;) {
    printf("Enter value of trade: ");
    for (;;) {
      if (scanf("%f", &value) != 1) {
        fprintf(stderr, "value should be only 1 number. Please re-enter.\n");
        while (getchar() != '\n')
          ;
        continue;
      }

      next_char = getchar();
      if (next_char != '\n') {
        fprintf(stderr, "value should be only 1 number. Please re-enter.\n");
        while (next_char != '\n' && next_char != EOF) {
          next_char = getchar();
        }
        continue;
      }
      break;
    };

    if (value == 0)
      return 0;

    if (value < 2500.00f)
      commission = 30.00f + .017f * value;
    else if (value < 6250.00f)
      commission = 56.00f + .0066f * value;
    else if (value < 20000.00f)
      commission = 76.00f + .0034f * value;
    else if (value < 50000.00f)
      commission = 100.00f + .0022f * value;
    else if (value < 500000.00f)
      commission = 155.00f + .0011f * value;
    else
      commission = 255.00f + .0009f * value;

    if (commission < 39.00f)
      commission = 39.00f;

    printf("commission: $%.2f\n\n", commission);
  }

  return 0;
}
