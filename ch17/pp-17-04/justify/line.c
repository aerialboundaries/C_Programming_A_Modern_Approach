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
#include "line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 60

// char line[MAX_LINE_LEN + 1];
struct node {
  char *word;
  struct node *next;
};

struct node *line = NULL;
struct node *last = NULL;

int line_len = 0;
int num_words = 0;

void clear_line(void) {
  struct node *temp;
  while (line != NULL) {
    temp = line;
    line = line->next;
    free(temp->word);
    free(temp);
  }
  last = NULL;
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word) {
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    fprintf(stderr, "Error: malloc failed in add_word\n");
    exit(EXIT_FAILURE);
  }

  // copy words
  new_node->word = malloc(strlen(word) + 1);
  if (new_node->word == NULL)
    exit(EXIT_FAILURE);
  strcpy(new_node->word, word);
  new_node->next = NULL;

  // add node to the last of line
  if (line == NULL) {
    line = new_node;
  } else {
    last->next = new_node;
  }
  last = new_node;

  line_len += strlen(word);
  num_words++;
}

int space_remaining(void) { return MAX_LINE_LEN - line_len; }

void write_line(void) {
  int extra_spaces, spaces_to_insert, i;
  struct node *p = line;

  extra_spaces = MAX_LINE_LEN - line_len;

  while (p != NULL) {
    printf("%s", p->word);

    if (num_words > 1) {
      // calculate space between words
      spaces_to_insert = extra_spaces / (num_words - 1);
      for (i = 1; i <= spaces_to_insert + 1; i++) {
        putchar(' ');
      }
      extra_spaces -= spaces_to_insert;
    }
    num_words--;
    p = p->next;
  }
  putchar('\n');
  clear_line();
}

void flush_line(void) {
  struct node *p = line;
  while (p != NULL) {
    printf("%s", p->word);
    if (p->next != NULL)
      putchar(' ');
    p = p->next;
  }
  putchar('\n');
  clear_line();
}
