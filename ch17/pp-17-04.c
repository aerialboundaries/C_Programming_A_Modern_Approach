/* C Programming A Modern Approach
 * pp-17-03.c
 * 2026-04-30
 *
 * Modify the justify program of Section 15.3 by rewriting the line.c file so
 * that it stores the current line in a linked list. Each node in the list will
 * store a single word. The line array will be replaced by a variable that
 * points to the node containing the first word. This variable will store a null
 * pointer whenever the line is empty.
 */

#include <stdio.h>
#include <string.h>

#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;

void clear_line(void) {
  line[0] = '\0';
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word) {
  if (num_words > 0) {
    line[line_len] = ' ';
    line[line_len + 1] = '\0';
    line_len++;
  }
  strcat(line, word);
  line_len += strlen(word);
  num_words++;
}

int space_remaining(void) { return MAX_LINE_LEN - line_len; }

void write_line(void) {
  int extra_spaces, spaces_to_insert, i, j;

  extra_spaces = MAX_LINE_LEN - line_len;
  for (i = 0; i < line_len; i++) {
    if (line[i] != ' ')
      putchar(line[i]);
    else {
      spaces_to_insert = extra_spaces / (num_words - 1);
      for (j = 1; j <= spaces_to_insert + 1; j++)
        putchar(' ');
      extra_spaces -= spaces_to_insert;
      num_words--;
    }
  }
  putchar('\n');
}

void flush_line(void) {
  if (line_len > 0)
    puts(line);
}
