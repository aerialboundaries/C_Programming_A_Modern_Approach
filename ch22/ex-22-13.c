// Write the following function:
//
// int line_length(const char *filename, int n);
//
// The function should return the length of line n in the text file whose name
// is filename (assuming that the first line in the file is line 1). If the line
// doesn't exist, the function should return 0.
//
// My Answer
#include <stdio.h>
#include <string.h>

int line_length(const char *filename, int n);

int main(void)
{
  printf("line length is : %d\n", line_length("test.txt", 3));

  return 0;
}

int line_length(const char *filename, int n)
{
  if (n <= 0) {
    return 0;
  }

  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return 0;
  }

  int current_line = 1;
  int length = 0;
  int ch;

  while ((ch = fgetc(fp)) != EOF) {
    if (current_line == n) {
      if (ch == '\n') {
        break;
      }
      length++;
    } else if (ch == '\n') {
      current_line++;
    }
  }

  fclose(fp);

  if (current_line < n) {
    return 0;
  }

  return length;
}
