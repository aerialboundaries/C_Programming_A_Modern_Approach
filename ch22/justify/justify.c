/* pp-22-15 2026-08-10 */
/* Formats a file of text */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(int argc, char *argv[])
{
  /* check command line */
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <input_file_name> <output_file_name>\n",
            argv[0]);
    return EXIT_FAILURE;
  }

  /* open input file and output file */
  FILE *in_fp = fopen(argv[1], "r");
  if (in_fp == NULL) {
    fprintf(stderr, "Cannot open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  FILE *out_fp = fopen(argv[2], "w");
  if (out_fp == NULL) {
    fprintf(stderr, "Cannot open %s\n", argv[2]);
    fclose(in_fp);
    exit(EXIT_FAILURE);
  }

  char word[MAX_WORD_LEN + 2];
  int word_len;

  clear_line();
  for (;;) {
    read_word(word, MAX_WORD_LEN + 1, in_fp);
    word_len = strlen(word);
    if (word_len == 0) {
      flush_line(out_fp);
      break;
    }
    if (word_len > MAX_WORD_LEN)
      word[MAX_WORD_LEN] = '*';
    if (word_len + 1 > space_remaining()) {
      write_line(out_fp);
      clear_line();
    }
    add_word(word);
  }
  fclose(in_fp);
  fclose(out_fp);
  return 0;
}
