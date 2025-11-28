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

  int a[R][C] = {0}, row_total[R] = {0}, col_total[C] = {0}, h_score[R],
      l_score[R], i, j;
  double avg_score[C] = {0.0f}, g_avg_score[R] = {0.0f};

  for (i = 0; i < R; i++) {
    printf("Enter row %d: ", i + 1);
    for (j = 0; j < C; j++) {
      scanf(" %d", &a[i][j]);
    }
  }

  //   for (i = 0; i < 5; i++) {
  //     for (j = 0; j < 5; j++) {
  //       printf("%d ", a[i][j]);
  //     }
  //     printf("\n");
  //   }

  for (i = 0; i < R; i++) {
    row_total[i] += a[i][j];
    printf("Student %d:\n", i + 1);
    printf("Total Score: %d Average score %4.2f\n", row_total[i],
           (double)row_total[i] / C);
  }

  for (i = 0; i < R; i++) {
    for (j = 0; j < C; j++) {
      col_total[j] += a[i][j];
      if (a[i][j] > h_score[i])
        h_score[j] = a[i][j];
      if (a[i][j] < l_score[j])
        l_score[j] = a[i][j];
    }
    g_avg_score[j] = (double)col_total[j] / R;
  }

  for (j = 0; j < C; j++) {
    printf("G %d", j);
    printf("\n");
  }

  return 0;
}
