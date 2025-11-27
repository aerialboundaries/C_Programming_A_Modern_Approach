/* C Programming A Modern Approach
 * pp08-04.c
 * 2022-11-26
 *
 * Modify the reverse.c program of Section 8.1 to use the expression
 * (int) (sizeof(a) / sizeof(a[0]))  (or a macro with this value)
 * for array length. */

#include <stdio.h>

#define N 10
#define SIZE_OF_ARRAY (int)(sizeof(a) / sizeof(a[0]))

int main(void) {

  int a[N], i;

  printf("Enter %d numbers: ", N);
  for (i = 0; i < N; i++)
    scanf("%d", &a[i]);

  printf("In reverse order: ");
  for (i = SIZE_OF_ARRAY - 1; i >= 0; i--)
    printf(" %d", a[i]);
  printf("\n");

  return 0;
}
