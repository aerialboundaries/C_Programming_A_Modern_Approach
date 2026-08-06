/*
Write a program that displays the contents of a file as bytes and as characters.
Have the user specify the file name on the command line. Here's what the output
will look like when the program is used to display the pun.c file of Section 2.1:

Offset					Bytes                  Characters
------  -----------------------------  ----------
     0  23 69 6E 63 6C 75 64 65 20 3C  #include <
    10  73 74 64 69 6F 2E 68 3E 0D 0A  stdio.h>..
    20  0D 0A 69 6E 74 20 6D 61 69 6E  ..int main
    30  28 76 6F 69 64 29 0D 0A 7B 0D  (void)... 
    40  0A 20 20 70 72 69 6E 74 66 28  . printf( 
    50  22 54 6F 20 43 2C 20 6F 72 20  "To C, or 
    60  6E 6F 74 20 74 6F 20 43 3A 20  not to C:
    70  74 68 61 74 20 69 73 20 74 68  that is th 
    80  65 20 71 75 65 73 74 69 6F 6E  e question 
    90  2E 5C 6E 22 29 3B 0D 0A 20 20  .\n")；.. 
   100  72 65 74 75 72 6E 20 30 3B OD  return 0；. 
   110  0A 7D                          .}

Each line shows 10 bytes from the file, as hexadecimal numbers and as characters.
The number in the Offset column indicates the position within the file of the
first byte on the line. Only printing characters(as determined by the isprint 
function) are displayed;
other characters are shown as periods. Note that the appearance of a text file may vary,
depending on the character set and the operating system.The example above assumes
that pun.c is a Windows file, so OD and 0A bytes(the ASCII carriage-return and line-feed
characters) appear at the end of each line. Hint : Be sure to open the file in "rb" mode.
*/

// 2026-08-06

// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>
//
// #define MAX_BYTES 10
//
// int main(int argc, char *argv[]) {
//   if (argc != 2) {
//     fprintf(stderr, "Usage: hexdump file_name\n");
//     exit(EXIT_FAILURE);
//   }
//
//   printf("offset             Bytes             Characters\n");
//   printf("------ ----------------------------- ----------\n");
//
//   FILE *fp = fopen(argv[1], "rb");
//
//   if (fp == NULL) {
//     perror(argv[1]);
//     exit(EXIT_FAILURE);
//   }
//
//   int offset = 0, ch;
//
//   while (1) {
//     unsigned char buffer[MAX_BYTES];
//     int bytes_read = 0;
//
//     // read 10 bytes into buffer
//     for (int i = 0; i < MAX_BYTES; i++) {
//       ch = getc(fp);
//       if (ch == EOF)
//         break;
//       buffer[i] = (unsigned char)ch;
//       bytes_read++;
//     }
//
//     if (bytes_read == 0)
//       break;
//
//     printf("%6d  ", offset);
//
//     for (int i = 0; i < MAX_BYTES; i++) {
//       if (i < bytes_read)
//         printf("%02X ", buffer[i]);
//       else
//         printf("   ");
//     }
//
//     for (int i = 0; i < bytes_read; i++) {
//       printf("%c", isprint(buffer[i]) ? buffer[i] : '.');
//     }
//     printf("\n");
//     offset += bytes_read;
//   }
//
//   fclose(fp);
//
//   return 0;
// }

// Answer by KN
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  int i, n, offset;
  unsigned char buffer[10];

  if (argc != 2) {
    fprintf(stderr, "usage: viewfile file\n");
    exit(EXIT_FAILURE);
  }

  if ((fp = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  printf("Offset              Bytes              Characters\n");
  printf("------  -----------------------------  ----------\n");

  for (offset = 0;; offset += 10) {
    n = fread(buffer, 1, 10, fp);
    if (n == 0)
      break;

    printf("%6d  ", offset);

    for (i = 0; i < n; i++)
      printf("%.2X ", buffer[i]);
    for (; i < 10; i++)
      printf("   ");
    printf(" ");
    for (i = 0; i < n; i++) {
      if (!isprint(buffer[i]))
        buffer[i] = '.';
      printf("%c", buffer[i]);
    }
    printf("\n");
  }

  fclose(fp);
  return 0;
}
