/* C Programming A Modern Approach
 * pp-09-01.c
 * 2026-01-27
 *
 * Write a program that asks the user to enter a series of integers (which
 * it stores in an array), then sorts the integers by calling the function
 * selection_sort. When given an array with n elements, selection_sort
 * must do the following:
 * 1. Search the array to find the largest element, then move it to the
 *    last position in the array.
 * 2. Call itself recursively to sort the first n-1 elements of the array.
 */

#include <stdio.h>

#define N 10

void selection_sort(int a[], int n);

int main(void) {
  int a[N];
  printf("Enter %d numbers: ", N);

  for (int i = 0; i < N; i++)
    scanf("%d", &a[i]);

  selection_sort(a, N);

  printf("Sorted array: ");

  for (int i = 0; i < N; i++)
    printf("%d ", a[i]);

  printf("\n");

  return 0;
}

void selection_sort(int a[], int n) {
  if (n <= 1)
    return;

  int max_index = 0;

  for (int i = 1; i < n; i++) {
    if (a[i] > a[max_index]) {
      max_index = i;
    }
  }

  int temp = a[max_index];
  a[max_index] = a[n - 1];
  a[n - 1] = temp;

  selection_sort(a, n - 1);
}
