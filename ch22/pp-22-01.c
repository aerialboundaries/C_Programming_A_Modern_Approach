// Extend the canopen. c program of Section 22.2 so that the user may put any
// number of file names on the command line:
//
// canopen foo bar baz
//
// The program should print a separate can be opened or can't be opened message
// for each file. Have the program terminate with status EXIT_FAILURE if one or
// more of the files can't be opened.

/* Checks whether a file can be opended for reading */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  int error = 0; // flag for error

  if (argc < 2) {
    printf("usage: cannopen filename\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++) {
    if ((fp = fopen(argv[i], "r")) == NULL) {
      printf("%s can't be opened\n", argv[i]);
      error = 1; // record error
      exit(EXIT_FAILURE);
    } else {
      printf("%s can be opened\n", argv[i]);
      fclose(fp);
    }
  }

  // After loop, quit with EXIT_FAILURE if there are errors.
  if (error) {
    exit(EXIT_FAILURE);
  }

  return 0;
}
