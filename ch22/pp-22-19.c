/*
(a) Write a program that converts a Windows text file to a UNIX text file. (See Section 22.1
for a discussion of the differences between Windows and UNIX text files.)

(b) Write a program that converts a UNIX text file to a Windows text file.

In each case, have the program obtain the names of both files from the command line. Hint:
Open the input file in "rb" mode and the output file in "wb" mode.
*/

// 2026-08-12

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define CR '\x0d'
#define LF '\x0a'
#define CTRLZ '\x1a'

static void win_to_unix(FILE *in_fp, FILE *out_fp) {
  int ch;
  while ((ch = getc(in_fp)) != EOF) {
    if (ch != CR && ch != CTRLZ) {
      putc(ch, out_fp);
    }
  }
}

static void unix_to_win(FILE *in_fp, FILE *out_fp) {
  int ch;
  while ((ch = getc(in_fp)) != EOF) {
    if (ch == LF) {
      putc(CR, out_fp);
    }
    putc(ch, out_fp);
  }
}

int main(int argc, char *argv[]) {
  FILE *in_fp, *out_fp;
  int opt;
  int flag_a = 0, flag_b = 0;

  while ((opt = getopt(argc, argv, "ab")) != -1) {
    switch (opt) {
    case 'a':
      flag_a = 1;
      break;
    case 'b':
      flag_b = 1;
      break;
    case '?':
      fprintf(stderr,
              "Usage: %s [-a] [-b] [input_filename] [output_filename]\n",
              argv[0]);
      return EXIT_FAILURE;
    default:
      break;
    }
  }

  if ((flag_a && flag_b) || (!flag_a && !flag_b)) {
    fprintf(stderr,
            "Error: Specify either -a (Win to UNIX) or -b (UNIX to WIN).\n");
    return EXIT_FAILURE;
  }

  if (argc - optind < 2) {
    fprintf(stderr, "Usage: %s [-a|-b] [input_filename] [output_filename]\n",
            argv[0]);
    return EXIT_FAILURE;
  }

  in_fp = fopen(argv[optind], "rb");
  if (in_fp == NULL) {
    fprintf(stderr, "Cannot open %s.\n", argv[optind]);
    exit(EXIT_FAILURE);
  }

  out_fp = fopen(argv[optind + 1], "wb");
  if (out_fp == NULL) {
    fprintf(stderr, "Cannot open %s.\n", argv[optind + 1]);
    fclose(in_fp);
    exit(EXIT_FAILURE);
  }

  /* windows to unix */
  if (flag_a) {
    win_to_unix(in_fp, out_fp);
  } else if (flag_b) {
    unix_to_win(in_fp, out_fp);
  }

  fclose(in_fp);
  fclose(out_fp);

  return 0;
}
