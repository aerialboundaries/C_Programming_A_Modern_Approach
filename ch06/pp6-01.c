/* C Programming A Modern Approach pp6-01.c
 * 2025-11-6
 *
 * Write a program that finds the largest in a series
 * of numbers entered by the user.  The program must
 * prompt the user to enter number one by one.
 * When the user enters 0 or a negative number, the
 * program must display the largest nonnegative number enterd.
 *
 * Enter a number: 60
 * Enter a number: 38.3
 * Enter a number: 4.89
 * Enter a number: 100.62
 * Enter a number: 75.2295
 * Enter a number: 0
 *
 * The largest number entered was 100.62
 *
 * Notice that the numbers aren't necessarily integers.
 */

// #include <stdio.h>
//
// int main(void) {
//
//   float n = 0.0f, largest = 0.0f;
//
//   do {
//     printf("Enter a number: ");
//     scanf("%f", &n);
//     if (n >= largest) {
//       largest = n;
//     }
//   } while (n > 0);
//   printf("The largest number entered was %f", largest);
//
//   return 0;
// }

#include <stdio.h>

int main(void) {

  float n = 0.0f, largest = 0.0f;
  printf("Enter a number: ");
  scanf("%f", &n);
  if (n > 0) {
    largest = n;
  }

  while (n > 0.0f) {
    printf("Enter a number: ");
    scanf("%f", &n);
    if (n >= largest) {
      largest = n;
    }
  }
  printf("The largest number entered was %f", largest);

  return 0;
}
