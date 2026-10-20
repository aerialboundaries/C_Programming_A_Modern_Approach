/* C Programming A Modern Approach
 * ex-14-15.c
 * 2026-03-18
 *
 * Suppose that a program needs to display messages in either English,
 * French, or Spanish. Using conditional compilation, write a program
 * fragment that displays one of the following three messages, depending
 * on whether or not the specifined macro is defined:
 *
 * Insert Disk 1        (If ENGLISH is defined)
 * Inserez Le Disque 1  (if FRENCH is defined)
 * Inserte El Disco 1   (if SPANISH is defined)
 */

#include <stdio.h>

#define SPANISH

int main(void) {
#ifdef ENGLISH
  printf("Insert Disk 1\n");
#elif defined FRENCH
  printf("Inserez Le Disque 1\n");
#elif defined SPANISH
  printf("Inserte El Disco 1\n");
#endif

  return 0;
}
