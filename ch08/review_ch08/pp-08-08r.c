/* C Programming A Modern Approach
 * pp08-08.c
 * 2025-11-27
 *
 * Modify Programming Project 7 so that it prompts for five quiz grades for
 * each five students, then computes the total socore and average score
 * for each student, and the average socre, high score and low score for
 * each quiz. */

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

#define NUM_STUDENT 5
#define NUM_QUIZ 5

int main(void) {

  int a[NUM_STUDENT][NUM_QUIZ] = {0}, student_total[NUM_QUIZ] = {0},
      quiz_total[NUM_STUDENT] = {0}, i, j;
  int high[NUM_QUIZ], low[NUM_QUIZ];
  double avg_quiz[NUM_QUIZ];

  for (i = 0; i < NUM_STUDENT; i++) {
    printf("Enter grades of stduent %d: ", i + 1);
    for (j = 0; j < NUM_QUIZ; j++) {
      scanf(" %d", &a[i][j]);
      student_total[i] += a[i][j];
      quiz_total[j] += a[i][j];
    }
  }

  printf("\n");

  for (i = 0; i < 5; i++)
    printf("student %d :  Total Score %d Average Score %.2f\n", i + 1,
           student_total[i], (double)student_total[i] / NUM_QUIZ);
  printf("\n");

  for (j = 0; j < 5; j++) {
    avg_quiz[j] = (double)quiz_total[j] / NUM_STUDENT;
    low[j] = high[j] = a[0][j];
  }

  for (j = 0; j < 5; j++) {
    for (i = 1; i < NUM_STUDENT; i++) {
      low[j] = a[i][j] < low[j] ? a[i][j] : low[j];
      high[j] = a[i][j] > high[j] ? a[i][j] : high[j];
    }
  }

  for (j = 0; j < NUM_QUIZ; j++)
    printf("Quiz %d : Average %.2f High score %d Low score %d\n", j + 1,
           avg_quiz[j], high[j], low[j]);

  printf("\n");

  return 0;
}
