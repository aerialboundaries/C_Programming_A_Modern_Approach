/* C Programming A Modern Approach pp7-01.c
 * 2025-11-16
 *
 * The square2.c program of Section 6.3 will fail (usually by printing
 * strange answers) if i * i exceeds the maximum int value. Run the
 * program and determie the smallest value of n that causes failure.
 * Try changing the type of i to short and running the program again.
 * (Don't forget to update the conversion specifications in the call
 * of printf!) Then try long. From these experiments, what can you
 * conclude about the number of bits used to store integer types on
 * your machine? */

// /* C Programming A Modern Approach square.c
//  * 2015-10-26
//  */
//
// #include <stdio.h>
//
// int main(void) {
//
//   int i, n;
//
//   printf("This program prints a table of squares.\n");
//   scanf("%d", &n);
//
//   i = 1;
//   while (i <= n) {
//     printf("%10d%10d\n", i, i * i);
//     i++;
//   }
//
//   return 0;
// }

#include <stdio.h>

int main(void) {

  long i;
  long n;

  printf("This program prints a table of squares.\n");
  scanf("%ld", &n);

  i = 1;
  while (i <= n) {
    printf("%10ld%30ld\n", i, i * i);
    i++;
  }

  return 0;
}

// My Answer:
// int: 46341 gives an error -2147479015
// short: 183 gives an error -32412
// ling:
