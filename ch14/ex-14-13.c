/* C Programming A Modern Approach
 * ex-14-13.c
 * 2026-03-17
 *
 * (a) Show what the following program will look like after proprecessing.
 * You may ignore any lines added to the program as a result of including
 * the <stdio.h> header.
 */

#include <stdio.h>

#define N 100

void f(void);

int main(void) {
  f();
#ifdef N
#undef N
#endif
  return 0;
}

void f(void) {
#if defined(N)
  printf("N is %d\n", N);
#else
  printf("N is undefeined\n");
#endif
}

/* (b) what will be the output of this program? */
