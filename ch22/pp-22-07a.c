// 2026-08-06
// compress_file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if (argc != 2) {
    fprintf(stderr, "Usage %s <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE *fp;
  if ((fp = fopen(argv[1], "rb")) == NULL) {
    perror(argv[1]);
    exit(EXIT_FAILURE);
  }

  char rle_filename[strlen(argv[1]) + 5];
  snprintf(rle_filename, sizeof(rle_filename), "%s.rle", argv[1]);

  FILE *dest_fp;
  if ((dest_fp = fopen(rle_filename, "wb")) == NULL) {
    perror(rle_filename);
    fclose(fp);
    exit(EXIT_FAILURE);
  }

  int base_ch = getc(fp);
  if (base_ch != EOF) {
    int ch, seq = 1;

    while ((ch = getc(fp)) != EOF) {
      // if seq exceeds 255 writeout. for safety
      if (ch == base_ch && seq < 255) {
        seq++;
      } else {
        putc(seq, dest_fp);
        putc(base_ch, dest_fp);
        seq = 1;
        base_ch = ch;
      }
    }
    // write out the last buffer
    putc(seq, dest_fp);
    putc(base_ch, dest_fp);
  }

  fclose(fp);
  fclose(dest_fp);

  return 0;
}
