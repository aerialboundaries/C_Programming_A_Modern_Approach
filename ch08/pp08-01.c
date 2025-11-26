/* C Programming A Modern Approach
 * pp08-01.c
 * 2025-11-25
 *
 * Modify the repdigit.c program of Section 8.1 so that it shows
 * which digits (if any) were repeated:
 *
 * Enter a number : 939577
 * Repeated digit(s): 7 9 */

/*C Programming A Modern Approach repdigit.c
 * 2025-11-20
 */

#include <stdbool.h>
#include <stdio.h>

int main(void) {

  int digit_seen[10] = {0};
  bool is_repeat = false;
  int digit, i;
  long n;

  printf("Enter a number: ");
  scanf("%ld", &n);

  while (n > 0) {
    digit = n % 10;
    digit_seen[digit]++;
    if (digit_seen[digit] > 1) {
      is_repeat = true;
    }
    n /= 10;
  }

  if (is_repeat) {
    printf("Repeated digit(s) ");
    for (i = 0; i < 10; i++) {
      if (digit_seen[i] > 1)
        printf("%d ", i);
    }
  } else {
    printf("No repeated digit\n");
  }
  return 0;
}
