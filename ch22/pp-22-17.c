/*
Write a program that reads a series of phone numbers from a file and displays
them in a standard format. Each line of the file will contain a single phone
number, but the numbers may be in a variety of formats. You may assume that each
line contains 10 digits, possibly mixed with other characters (which should be
ignored). For example, suppose that the file contains the following lines:

404.817.6900
(215) 686-1776
312-746-6000
877 275 5273
6173434200

The output of the program should have the following appearance:

(404) 817-6900
(215) 686-1776
(312) 746-6000
(877) 275-5273
(617) 343-4200

Have the program obtain the file name from the command line.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 10

int main(int argc, char *argv[])
{
  FILE *in_fp = fopen(argv[1], "r");
  int ch;
  char number[MAX_DIGITS + 1];
  int num_read = 0;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if (in_fp == NULL) {
    fprintf(stderr, "Cannot open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  while ((ch = (getc(in_fp))) != EOF) {

    if (isdigit(ch)) {
      number[num_read] = ch;
      num_read++;

      /* once get 10 digits, output with format */
      if (num_read == MAX_DIGITS) {
        number[num_read] = '\0'; // make number string

        /* write as string */
        printf("(%.3s) %.3s-%.4s\n", number, number + 3, number + 6);
        num_read = 0;
      }
    }
  }

  fclose(in_fp);

  return 0;
}
