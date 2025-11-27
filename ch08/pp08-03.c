/* C Programming A Modern Approach
 * pp08-03.c
 * 2025-11-26
 *
 * Modify the repdigit.c program of Section 8.1 so that the user can enter
 * more thatn one number to be tested for repeated digits. The program should
 * terminate when the user enters a number that's less than or equal to 0.
 */

#include <stdbool.h>
#include <stdio.h>

int main(void) {

  bool digit_seen[10] = {false};
  int digit;
  long n = 1;

  while (n > 0) {
    printf("Enter a number: ");
    scanf("%ld", &n);
    if (n <= 0)
      return 0;

    while (n > 0) {
      digit = n % 10;
      if (digit_seen[digit])
        break;
      digit_seen[digit] = true;
      n /= 10;
    }

    if (n > 0)
      printf("Repeated digit\n");
    else
      printf("No repeated digit\n");

    for (int i = 0; i < 10; i++)
      digit_seen[i] = false;
    n = 1;
  }

  return 0;
}
