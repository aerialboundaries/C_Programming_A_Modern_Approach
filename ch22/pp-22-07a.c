// 2026-08-06
// compress_file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    perror(argv[1]);
    exit(EXIT_FAILURE);
  }

  FILE *fp;
  if ((fp = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "Cannot open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  char rle_filename[strlen(argv[1]) + 4];
  snprintf(rle_filename, sizeof(rle_filename), "%s.rle", argv[1]);

  FILE *dest_fp;
  if ((dest_fp = fopen(rle_filename, "wb")) == NULL) {
    fprintf(stderr, "Cannot open %s\n", rle_filename);
    ;
    fclose(fp);
    exit(EXIT_FAILURE);
  }

  int base_ch, ch, seq = 1;
  base_ch = getc(fp);

  while ((ch = getc(fp)) != EOF || ferror(fp)) {
    if (ch == base_ch) {
      seq++;
    } else {
      putc(seq, dest_fp);
      putc(base_ch, dest_fp);
      seq = 1;
      base_ch = ch;
    }
    if (ch == EOF) {
      putc(seq, dest_fp);
      putc(ch, dest_fp);
    }
  }

  fclose(fp);
  fclose(dest_fp);

  return 0;
}
