/* C Programming A Modern Approach
 * ex-09-10.c
 * 2026-01-22
 *
 * Write functions that return the following values. (Assume that a and n
 * are parameters, where a is an array of int values and n is the length
 * fo the array.)
 *
 * (a) The largest element in a.
 * (b) The average of all elements in a.
 * (c) The number of positive elements in a.
 *
 */

#include <stdio.h>

#define N 10

int largest(int a[], int n);
double average(int a[], int n);
int number_of_positive(int a[], int n);

int main(void) {

  int a[N] = {2, -29, 103, 50, -3, -29, 789, 73, 0, 13};
  int n = N;
  printf("Largest: %d\n:", largest(a, n));
  printf("Average: %.2f\n", average(a, n));
  printf("Number of positive: %d\n", number_of_positive(a, n));

  return 0;
}

int largest(int a[], int n) {
  int largest = a[0];
  for (int i = 1; i < n; i++)
    if (a[i] >= largest)
      largest = a[i];
  return largest;
}

double average(int a[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += a[i];
  return (double)sum / n;
}

int number_of_positive(int a[], int n) {
  int count = 0;
  for (int i = 0; i < n; i++)
    if (a[i] > 0)
      count++;
  return count;
}
