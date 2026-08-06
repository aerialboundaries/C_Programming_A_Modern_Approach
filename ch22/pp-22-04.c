// (a) Write a program that counts the number of characters in a text file.
// (b) Write a program that counts the number of words in a text file. (A "word"
// is any sequence of non-white-space characters.)
// (c) Write a program that counts the number of lines in a text file. Have each
// program obtain the file name from the command line.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ch_count(FILE *fp);
int word_count(FILE *fp);
int line_count(FILE *fp);

int main(int argc, char *argv[])
{
  int opt;
  int do_a = 0, do_b = 0, do_c = 0;

  while ((opt = getopt(argc, argv, "abc")) != -1) {
    switch (opt) {
    case 'a':
      do_a = 1;
      break;
    case 'b':
      do_b = 1;
      break;
    case 'c':
      do_c = 1;
      break;
    default:
      exit(EXIT_FAILURE);
    }
  }

  for (int i = optind; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
      perror(argv[i]);
      continue;
    }
    printf("--- File: %s ---\n", argv[i]);
    if (do_a)
      printf("Characters : %d\n", ch_count(fp)), rewind(fp);
    if (do_b)
      printf("Words : %d\n", word_count(fp)), rewind(fp);
    if (do_c)
      printf("Lines : %d\n", line_count(fp));

    fclose(fp);
  }

  return 0;
}

int ch_count(FILE *fp)
{
  int ch, num_ch = 0;
  while ((ch = getc(fp)) != EOF)
    num_ch++;
  return num_ch;
}

int word_count(FILE *fp)
{

  int ch, num_word = 0, in_word = 0;
  while ((ch = getc(fp)) != EOF) {
    if (isspace(ch)) {
      in_word = 0;
    } else if (!in_word) {
      in_word = 1;
      num_word++;
    }
  }
  return num_word;
}

int line_count(FILE *fp)
{
  int ch, num_line = 0;
  while ((ch = getc(fp)) != EOF) {
    if (ch == '\n')
      num_line++;
  }
  return num_line;
}
