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

#define STUDENTS 5
#define QUIZ 5

int main(void)
{
  int matrix[STUDENTS][QUIZ] = { 0 };
  int ch, student_total = 0, quiz_total = 0, quiz_high = 0, quiz_low = 0;
  double student_avg, quiz_avg;

  for (int i = 0; i < STUDENTS; i++) {
    printf("Enter student %d's grade: ", i + 1);
    for (int j = 0; j < QUIZ; j++) {
      scanf("%d", &matrix[i][j]);
    }
    while ((ch = getchar()) != '\n' && ch != EOF)
      ; // delete '\n'
  }
  printf("\n");

  for (int i = 0; i < STUDENTS; i++) {
    for (int j = 0; j < QUIZ; j++)
      student_total += matrix[i][j];
    student_avg = (double)student_total / QUIZ;

    printf("Student %d's total score   : %4d\n"
           "             average score : %4.2f\n\n",
           i + 1, student_total, student_avg);
    student_total = 0; // reset for the next student
  }

  for (int j = 0; j < QUIZ; j++) {
    quiz_total = 0;
    // initialize with the 1st students grade
    quiz_low = matrix[0][j];
    quiz_high = matrix[0][j];

    for (int i = 0; i < STUDENTS; i++) {
      quiz_total += matrix[i][j];
      if (matrix[i][j] < quiz_low)
        quiz_low = matrix[i][j];
      if (matrix[i][j] > quiz_high)
        quiz_high = matrix[i][j];
    }
    quiz_avg = (double)quiz_total / QUIZ;
    printf("Quiz %d's average score : %4.2f\n"
           "          high score    : %4d"
           "          low score     : %4d\n",
           j + 1, quiz_avg, quiz_high, quiz_low);
    quiz_total = 0;
  }

  return 0;
}
