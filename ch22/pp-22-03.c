// Write a program named fcat that "concatenates" any number of files by writing
// them to standard output, one after the other, with no break between files.
// For example, the following command will display the files f1.c,f2.c, and f3.c
// on the screen:
//
// fcat f1.c f2.c f3.c
//
// fcat should issue an error message if any file can't be opened. Hint: Since
// it has no more than one file open at a time, fcat needs only a single file
// pointer variable. Once it's fin- ished with a file, fcat can use the same
// variable when it opens the next file.

// 2026-08-05

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  int ch;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s filenames\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    fp = fopen(argv[i], "r");
    if (fp == NULL) {
      fprintf(stderr, "cannot open %s\n", argv[i]);
      continue;
    }

    while ((ch = getc(fp)) != EOF) {
      putchar(ch);
    }
    fclose(fp);
  }

  return 0;
}
