/*
Modify the fcopy.c program of Section 22.4 so that it uses fread and fwrite to
copy the file in blocks of 512 bytes. (The last block may contain fewer than 512
bytes, of course.)
*/

/* Copies a file */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
  FILE *source_fp, *dest_fp;
  unsigned char buf[BUFFER_SIZE];
  size_t num_read;

  if (argc != 3) {
    fprintf(stderr, "usage: fcopy source dest\n");
    exit(EXIT_FAILURE);
  }

  if ((source_fp = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[2]);
    fclose(source_fp);
    exit(EXIT_FAILURE);
  }

  while ((num_read = fread(buf, 1, BUFFER_SIZE, source_fp)) > 0) {
    if (fwrite(buf, 1, num_read, dest_fp) != num_read) {
      fprintf(stderr, "Error writing to destination file\n");
      fclose(source_fp);
      fclose(dest_fp);
      exit(EXIT_FAILURE);
    }
  }

  fclose(source_fp);
  fclose(dest_fp);
  return 0;
}
