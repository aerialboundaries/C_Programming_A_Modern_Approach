/* C Programming A Modern Approach
 * ex-14-08.c
 * 2026-03-17
 *
 * Suppose we want a macro that expands into a string containing the
 * current line number and file name. In other words, we'd like to write
 *
 * const char *str = LINE_FILE;
 *
 * and have it expand into
 *
 * const char *str = "Line 10 of file foo.c";
 *
 * Where foo.c is the file containing the program and 10 is the line on which
 * the invocation of LINE_FILE appears. Warning: This exercise is for experts
 * only. Be sure to read the Q&A section carefully before attempting!
 */
#include <stdio.h>

/* macro with 2 steps to convert number to string */
#define STRINGIZE(x) #x
#define TO_STRING(x) STRINGIZE(x)

/* LINE_FILE */
#define LINE_FILE "Line " TO_STRING(__LINE__) " of file "__FILE__

int main(void) {
  const char *str = LINE_FILE;
  printf("%s\n", str);

  return 0;
}
