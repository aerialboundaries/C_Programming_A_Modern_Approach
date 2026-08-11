/*
Write a program that reads integers from a text file whose name is given as a
command-line argument. Each line of the file may contain any number of integers
(including none) sepa- rated by one or more spaces. Have the program display the
largest number in the file, the smallest number, and the median (the number
closest to the middle if the integers were sorted). If the file contains an even
number of integers, there will be two numbers in the middle; the program should
display their average (rounded down). You may assume that the file contains no
more than 10,000 integers. Hint: Store the integers in an array and then sort
the array.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_INT 10000

int compare_ints(const void *a, const void *b) {
  int arg1 = *(const int *)a;
  int arg2 = *(const int *)b;

  if (arg1 < arg2)
    return -1;
  if (arg1 > arg2)
    return 1;
  return 0;
}

int main(int argc, char *argv[]) {
  FILE *in_fp;
  int integers[MAX_NUM_INT];
  int count = 0;
  int max, min, med;

  if (argc != 2) {
    fprintf(stderr, "Usage %s <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  if ((in_fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Cannot open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  /* store integers into integers array */
  while (count < MAX_NUM_INT && fscanf(in_fp, "%d", &integers[count]) == 1) {
    count++;
  }

  fclose(in_fp);

  /* there is no int in the file */
  if (count == 0) {
    fprintf(stderr, "No integers found in the file.\n");
    exit(EXIT_FAILURE);
  }

  /* qsort integer array */
  qsort(integers, (size_t)count, sizeof(int), compare_ints);

  /* max min */
  min = integers[0];
  max = integers[count - 1];

  /* med */
  if (count % 2 == 1) {
    med = integers[count / 2];
  } else {
    int sum = (integers[count / 2 - 1] + integers[count / 2]);
    if (sum < 0 && sum % 2 != 0) {
      med = (sum / 2) - 1;
    } else {
      med = sum / 2;
    }
  }

  printf("min: %d\n", min);
  printf("max: %d\n", max);
  printf("med: %d\n", med);

  return 0;
}
