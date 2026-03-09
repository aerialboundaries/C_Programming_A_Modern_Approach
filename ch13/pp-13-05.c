/* C Programming A Modern Approach
 * pp-13-05.c
 * 2026-03-06
 *
 * Write a propgram named sum.c that adds up its command-line arguments,
 * which are assumed to be integers. Running the progaram by typin
 * sum 8 24 62
 * shoudl produce the following output;
 * Total: 94
 *
 * Hint Use the atoi function to convert each comman-line argument fron
 * storing to inter form.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int sum = 0;
  for (int i = 1; i < argc; i++)
    sum += atoi(argv[i]);

  printf("Total: %d\n", sum);

  return 0;
}
