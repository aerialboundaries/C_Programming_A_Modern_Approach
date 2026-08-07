// 2026-08-07
// uncompress_file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage %s <filename.rle>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *filename = argv[1];
  int len = strlen(filename);

  // check ext: if ends with .rle
  if (len < 5 || strcmp(filename + len - 4, ".rle") != 0) {
    fprintf(stderr, "Error : File must end with .rle\n");
    exit(EXIT_FAILURE);
  }

  // generate destination file without .rle
  char dest_filename[len - 3]; // .rle + \0 strlen does not count \0, so add 1
  strncpy(dest_filename, filename, len - 4);
  dest_filename[len - 4] = '\0';

  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror(filename);
    exit(EXIT_FAILURE);
  }

  FILE *dest_fp = fopen(dest_filename, "wb");
  if (dest_fp == NULL) {
    perror(dest_filename);
    fclose(fp);
    exit(EXIT_FAILURE);
  }

  // uncompress logic to read 2bytes at once
  int count, ch;
  while ((count = getc(fp)) != EOF) {
    ch = getc(fp);
    if (ch == EOF)
      break;

    for (int i = 0; i < count; i++) {
      putc(ch, dest_fp);
    }
  }

  fclose(fp);
  fclose(dest_fp);

  return 0;
}
