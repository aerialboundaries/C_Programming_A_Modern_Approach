/* C Programming A Modern Approach
 * ex-09-11.c
 * 2026-01-22
 *
 * Write the following function:
 * float compute_GPA(char grades[], int n);
 * The grades array will contain letter grades (A, B, C, D, or F, either
 * upper-case or lower case); n is length of the array. The function should
 * return the average of the grades (assume that A=4, B=3, C=2, D=1, and F = 0).
 */

#include <stdio.h>

#define N 9
#define A 4
#define B 3
#define C 2
#define D 1
#define F 0

float compute_GPA(char grades[], int n);

int main(void) {

  char grades[N] = {C, A, B, D, F, C, A, B, D};
  printf("GPA is : %.2f", compute_GPA(grades, N));

  return 0;
}

float compute_GPA(char grades[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += grades[i];
  }
  return (float)sum / N;
}
