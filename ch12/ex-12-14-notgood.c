/* C Programming A Modern Approach
 * ex-12-14.c
 * 2026-02-17
 *
 * Assume that the following array contains a week's worth of hourly temeprature
 * readings, with each row containing the readings for one day:
 *
 * int temperatures[7][24];
 *
 * Write a statement that uses the search function (see Exercise 7) to search
 * the entire temperatures array for the value 32.
 */
#include <stdbool.h>
#include <stdio.h>

void search(int n, const int a[][n], int key);

int main(void) {

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

  search(24, temperatures, 32);

  return 0;
}

void search(int n, const int a[][n], int key) {
  const int (*p)[n];
  for (p = &a[0]; p < &a[7]; p++) {
    for (int i = 0; i < 24; i++)
      if ((*p)[i] == key)
        printf("%d ", true);
      else
        printf("%d ", false);

    printf("\n");
  }
}
