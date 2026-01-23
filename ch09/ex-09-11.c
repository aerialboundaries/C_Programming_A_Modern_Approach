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

#include <ctype.h>
#include <stdio.h>

#define N 9

float compute_GPA(char grades[], int n);

int main(void) {

  char grades[N] = {'A', 'b', 'C', 'd', 'F', 'a', 'B', 'c', 'A'};
  printf("GPA is : %.2f\n", compute_GPA(grades, N));

  return 0;
}

float compute_GPA(char grades[], int n) {
  float sum = 0.0f;
  for (int i = 0; i < n; i++) {
    char g = toupper((unsigned char)grades[i]);

    switch (g) {
    case 'A':
      sum += 4;
      break;
    case 'B':
      sum += 3;
      break;
    case 'C':
      sum += 1;
      break;
    case 'F':
      sum += 0;
      break;
    default:
      break;
    }
  }
  return (n > 0) ? (sum / n) : 0.0f;
}
