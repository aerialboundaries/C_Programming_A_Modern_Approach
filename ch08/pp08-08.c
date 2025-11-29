/* C Programming A Modern Approach
 * pp08-08.c
 * 2025-11-27
 *
 * Modify Programming Project 7 so that it prompts for five quiz grades for
 * each five students, then computes the total socore and average score
 * for each student, and the average socre, high score and low score for
 * each quiz. */

#include <stdio.h>

#define R 5
#define C 5

int main(void) {

  int a[R][C] = {0}, row_total[R] = {0}, col_total[C] = {0}, h_score[C],
      l_score[C], i, j;

  for (i = 0; i < R; i++) {
    printf("Enter row %d: ", i + 1);
    for (j = 0; j < C; j++) {
      scanf(" %d", &a[i][j]);
      row_total[i] += a[i][j];
      col_total[j] += a[i][j];
      if (i == 0) {
        h_score[j] = a[i][j];
        l_score[j] = a[i][j];
      } else {
        if (h_score[j] < a[i][j])
          h_score[j] = a[i][j];
        if (l_score[j] > a[i][j])
          l_score[j] = a[i][j];
      }
    }
  }

  printf("\nBy Student\n");
  for (i = 0; i < R; i++) {
    printf("Student %d: ", i + 1);
    printf("Total Score: %d Average score %4.2f\n", row_total[i],
           (double)row_total[i] / C);
  }

  printf("\nBy Grade\n");

  for (j = 0; j < C; j++) {
    printf("Grade %d: High %4d Low %4d Avg %4.2f\n", j + 1, h_score[j],
           l_score[j], (double)col_total[j] / R);
  }

  return 0;
}
