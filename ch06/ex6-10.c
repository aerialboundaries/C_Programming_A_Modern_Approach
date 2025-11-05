/* C Programming A Modern Approach ex6-10
 * 2025-11-05
 *
 * Show how to replace a continue statement by an equivalent goto statement.
 *
 */

// #include <stdio.h>
//
// int main(void) {
//   int i = 0, n = 0, sum = 0;
//   while (n < 10) {
//     printf("Enter a number: ");
//     scanf("%d", &i);
//     if (i == 0)
//       continue;
//     sum += i;
//     n++;
//     /* continue jumps here */
//   }
//   printf("The sum is %d\n", sum);
//   return 0;
// }
//
#include <stdio.h>

int main(void) {
  int i = 0, n = 0, sum = 0;
  while (n < 10) {
    printf("Enter a number: ");
    scanf("%d", &i);
    if (i == 0)
      /* continue; */
      goto done;
    sum += i;
    n++;
    /* continue jumps here */
  done:
  }
  printf("The sum is %d\n", sum);
  return 0;
}
