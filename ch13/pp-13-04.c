/* C Programming A Modern Approach
 * pp-13-04.c
 * 2026-03-06
 *
 * Write a program named reverse.c that echos its command-line arguments
 * in reverse order. Running the program by typing
 *
 * reverse void and null
 *
 * should produce the following output:
 *
 * null and void
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
  int i;
  for (i = argc - 1; i > 0; i--)
    printf("%s ", argv[i]);
  printf("\n");
}
