/* C Programming A Modern Approach
 * ex-12-15.c
 * 2026-02-17
 *
 * Write a loop that prints all temerature readings stored in row i of the
 * temperatures array (see Exercise 14). Use a pointer to visit each element
 * of the row.
 */

#include <stdbool.h>
#include <stdio.h>

#define DAYS 7
#define HOURS 24

void print_row(const int a[DAYS][HOURS], int i);

int main(void) {

  int i = 3;

  int temperatures[7][24] = {// 1日目
                             {15, 14, 13, 12, 12, 13, 15, 17, 19, 21, 22, 23,
                              24, 24, 23, 22, 21, 19, 18, 17, 16, 16, 15, 15},
                             // 2日目
                             {14, 14, 13, 12, 11, 12, 14, 16, 18, 20, 22, 23,
                              25, 25, 24, 23, 21, 20, 19, 17, 16, 15, 15, 14},
                             // 3日目
                             {14, 13, 12, 12, 11, 12, 13, 15, 17, 19, 21, 22,
                              23, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 14},
                             // 4日目
                             {13, 13, 12, 11, 10, 11, 13, 15, 32, 19, 20, 21,
                              22, 22, 21, 20, 19, 18, 17, 16, 15, 14, 14, 13},
                             // 5日目
                             {13, 12, 11, 10, 9,  10, 12, 14, 16, 18, 20, 21,
                              23, 23, 22, 21, 20, 18, 17, 16, 15, 14, 14, 13},
                             // 6日目
                             {13, 12, 12, 11, 11, 12, 13, 15, 17, 19, 21, 22,
                              24, 24, 32, 22, 21, 20, 19, 17, 16, 16, 15, 14},
                             // 7日目
                             {14, 14, 13, 12, 12, 13, 15, 17, 19, 21, 23, 24,
                              25, 26, 25, 24, 22, 21, 19, 18, 17, 16, 16, 15}};

  /* statement */
  print_row(temperatures, i);

  return 0;
}

void print_row(const int a[DAYS][HOURS], int i) {
  const int (*p)[HOURS];
  for (p = &a[0]; p < &a[i]; p++) {
    for (int i = 0; i < HOURS; i++) {
      printf("%d ", (*p)[i]);
    }
    printf("\n");
  }
}
