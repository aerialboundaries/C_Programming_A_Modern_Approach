/*
Write a program that tests whether your compiler's "" (native) locale is the same as its "C"
locale.
*/

/* fixed length array 
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  // 1. get "C" locale's name
  char *c_loc_orig = setlocale(LC_ALL, "C");
  if (c_loc_orig == NULL) {
    fprintf(stderr, "Failed to set C locale.\n");
    return EXIT_FAILURE;
  }

  // copy "C" locale for fear it should be overwritten
  char c_loc[256];
  strncpy(c_loc, c_loc_orig, sizeof(c_loc) - 1);
  c_loc[sizeof(c_loc) - 1] = '\0';

  // 2. native "" locale's name
  char *native_loc = setlocale(LC_ALL, "");
  if (native_loc == NULL) {
    fprintf(stderr, "Failed to set native locale.\n");
    return EXIT_FAILURE;
  }

  // 3. compare locale
  if (strcmp(c_loc, native_loc) == 0) {
    printf("The native locale is the same as the \"C\" locale: %s\n",
           native_loc);
  } else {
    printf("The native locale is different from the \"C\" locale.\n");
    printf("  \"C\" locale   : %s\n", c_loc);
    printf("  Native locale: %s\n", native_loc);
  }

  return EXIT_SUCCESS;
}
*/

/* universal solution */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// impliment my_strdup by c99
char *my_strdup(const char *s) {
  if (s == NULL) {
    return NULL;
  }

  // secure 1 byte for '\0'
  size_t len = strlen(s) + 1;
  char *dup = malloc(len);

  if (dup != NULL) {
    memcpy(dup, s, len); // strcpy(dup, s) will do
  }

  return dup;
}

int main(void) {
  char *str = my_strdup("Hello, C99");
  if (str == NULL) {
    return EXIT_FAILURE;
  }

  printf("%s\n", str);

  free(str);
  return EXIT_SUCCESS;
}
