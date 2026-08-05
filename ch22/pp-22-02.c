// Write a program that converts all letters in a file to upper case.
// (Characters other than letters shouldn't be changed.) The program should
// obtain the file name from the command line and write its output to stdout.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s filename.\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE *fp;
  int ch;

  if ((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  while ((ch = getc(fp)) != EOF) {
    putchar(toupper(ch));
  }
  fclose(fp);

  return 0;
}
