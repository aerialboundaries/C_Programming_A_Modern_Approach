#include <stdio.h>

#include "word.h"

int read_char(FILE *in_fp)
{
  int ch = getc(in_fp);

  if (ch == '\n' || ch == '\t')
    return ' ';
  return ch;
}

void read_word(char *word, int len, FILE *in_fp)
{
  int ch, pos = 0;

  while ((ch = read_char(in_fp)) == ' ')
    ;
  while (ch != ' ' && ch != EOF) {
    if (pos < len)
      word[pos++] = ch;
    ch = read_char(in_fp);
  }
  word[pos] = '\0';
}
