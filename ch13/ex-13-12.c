/* C Programming A Modern Approach
 * ex-13-12.c
 * 2026-03-03
 *
 * Write the following function:
 * void get_extension(const char *file_name, char *extension);
 *
 * file_name points to a string containing a file name. The function should
 * store the extension on the file name in the string pointed to by extension.
 * For example, if the file name is "memo.txt", the function will store "txt"
 * in the string pointed to by extension. If the file name doesn't have an
 * extension, the function should store an empty string (a single null
 * character) in the string pointed to by extension. Keep the function as simple
 * as possible by having it use the strlen and strcpy functions.
 */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

void get_extension(const char *file_name, char *extension);

int main(void) {
  char file_name1[80] = {"memo.txt"};
  char file_name2[80] = {"memo2"};
  char extension[4];

  get_extension(file_name1, extension);
  printf("file: %s's extension: %s\n", file_name1, extension);

  get_extension(file_name2, extension);
  printf("file: %s's extension: %s\n", file_name2, extension);

  return 0;
}

void get_extension(const char *file_name, char *extension) {
  size_t n;
  strcpy(extension, "\0");

  for (n = 0; n < strlen(file_name); n++)
    if (file_name[n] == '.')
      strcpy(extension, &file_name[n + 1]);
}
