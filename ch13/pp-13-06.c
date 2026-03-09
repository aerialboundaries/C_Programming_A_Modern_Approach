/* C Programming A Modern Approach
 * pp-13-06.c
 * 2026-03-08
 *
 * Improve the planet.c program of Section 13.7 by having it igonre case
 * when comparing command-line arguments with strings in the planets arrayl.
 */

/* Checks planet names */

/* Checks planet names */

#include <ctype.h>
#include <stdio.h>

#define NUM_PLANETS 9

int string_equal(const char *s, const char *t);

int main(int argc, char *argv[]) {
  char *planets[] = {"Mercury", "Venus",  "Earth",   "Mars", "Jupiter",
                     "Saturn",  "Uranus", "Neptune", "Pluto"};

  int i, j;
  char *p, *q;

  for (i = 1; i < argc; i++) {
    for (j = 0; j < NUM_PLANETS; j++) {
      if (string_equal(argv[i], planets[j])) {
        printf("%s is planet %d\n", argv[i], j + 1);
        break;
      }
    }

    if (j == NUM_PLANETS)
      printf("%s is not a planet\n", argv[i]);
  }

  return 0;
}

int string_equal(const char *s, const char *t) {
  int i;

  for (i = 0; toupper(s[i]) == toupper(t[i]); i++)
    if (s[i] == '\0')
      return 1;

  return 0;
}
