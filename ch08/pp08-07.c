/* C Programming A Modern Approach
 * pp08-07.c
 * 2025-11-27
 *
 * Write a program that reads a 5 x 5 array of integers and then prints
 * the row sums and the column sums:
 *
 * Enter row 1: 8 3 9 0 10
 * Enter row 2: 3 5 17 1 1
 * Enter row 3: 2 8 6 23 1
 * Enter row 4: 15 7 3 2 9
 * Enter row 5: 6 14 2 6 0
 *
 * Row totals: 30 27 40 36 28
 * Column totals: 34 37 37 32 21
 */

#include <stdio.h>

#define R 5
#define C 5

int main(void) {

  int a[R][C] = {0}, row_total[R] = {0}, col_total[C] = {0}, i, j;

  for (i = 0; i < R; i++) {
    printf("Enter row %d: ", i + 1);
    for (j = 0; j < C; j++) {
      scanf(" %d", &a[i][j]);
    }
  }

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  printf("Row totals: ");
  for (i = 0; i < 5; i++)
    printf(" %d", row_total[i] += row_total[i]);
  printf("\n");

  printf("Column totals: ");
  for (j = 0; j < 5; j++)
    printf(" %d", col_total[j] += col_total[j]);
  printf("\n");

  return 0;
}
