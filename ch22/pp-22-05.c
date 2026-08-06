// The xor . c program of Section 20.1 refuses to encrypt bytes that --in
// original or encrypted form -- are control characters. We can now remove this
// restriction. Modify the program so that the names of the input and output
// files are command-line arguments. Open both files in binary mode, and remove
// the test that checks whether the original and encrypted characters are
// printing characters.
//

#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[])
{
  if (argc != 3) {
    fprintf(stderr, "Usage: xor input file output file");
    exit(EXIT_FAILURE);
  }

  FILE *input, *output;

  input = fopen(argv[1], "rb");
  if (input == NULL) {
    perror(argv[1]);
    exit(EXIT_FAILURE);
  }

  output = fopen(argv[2], "wb+");
  if (output == NULL) {
    perror(argv[2]);
    fclose(input);
    exit(EXIT_FAILURE);
  }

  int orig_char, new_char;

  while ((orig_char = getc(input)) != EOF) {
    new_char = orig_char ^ KEY;
    putc(new_char, output);
  }

  rewind(output);

  int ch;
  while ((ch = getc(output)) != EOF)
    putchar(ch);

  fclose(input);
  fclose(output);

  return 0;
}
