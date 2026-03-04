/* C Programming A Modern Approach
 * ex-13-14.c
 * 2026-03-03
 *
 * What does the following program print?
 *
 * My Answer:
 * it prints error, because 1st --*p indicates unknown memory
 */
#include <stdio.h>

int main(void) {
  char s[] = "Hsjodi", *p;

  for (p = s; *p; p++)
    --*p;
  puts(s);
  return 0;
}
