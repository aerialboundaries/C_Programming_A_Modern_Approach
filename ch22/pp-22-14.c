/*
Modify Programming Project 15 from Chapter 8 so that the program prompts the
user to enter the name of a file containing the message to be encrypted:

Enter name of file to be encrypted: message.txt
Enter shift amount (1-25): 3

The program then writes the encrypted message to a file with the same name but
an added extension of .enc. In this example, the original file name is
message.txt, so the encrypted message will be stored in a file named
message.txt.enc. There's no limit on the size of the file to be encrypted or on
the length of each line in the file.
*/

/* C Programming A Modern Approach
pp08-15.c
2025-12-06

One of the oldest known encryption techniques is the Caesar cipher,
attributed to Julius Caesar. It involves replacing each letter in
a message with another letter that is a fixed number of positions
later in the alphabet. (If the replacement would go past the letter Z,
the cipher "wraps around" to the beginning of the alphabet. For example,
if each letter is replaced by the letter two poistions after it, then
Y would be replaced by A, and Z would be replaced by B.) Write a program
that encrypts a message using a Caesar cipher. The user will enter the
message to be encrypted and shift amount(the number of position by which
letters should be shifted):

Enter message to be encrypted: Go ahead, make my day.
Enter shift amount(1-25): 3
Encrypted message: Jr dkhdg, pdnh pb gdb.

Notice that the program can decrypt a message if the user enters
26 minus the original key:

Enter message to be ecrypted: Jr dkhdg, pdnh pb gdb.
Enter shift amount (1-25): 23
Encrypted message Go ahead, make my day.

You may asssume that the message does not exceed 80 characters.
Characters other than letters should be left unchanged. Lower-case
letters remain lower-case when encrypted, and upper-case letters
remain upper-case. Hint: To handle the wrap-around problem, use the
expression ((ch - 'A') + n) % 26 + 'A' to calculate the encrypted
version of an upper-case letter, where ch stores the letter and n
stores the shift amount. (You'll need a similar expression for lower-
case letters.) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 1024

int main(void)
{
  int ch, shift;
  char filename[MAX_FILENAME];
  char out_filename[MAX_FILENAME + 4];

  printf("Enter name of file to be encrypted: ");
  if (fgets(filename, sizeof(filename), stdin) == NULL)
    return 1;

  // delete new line character
  filename[strcspn(filename, "\n")] = '\0';

  /* generate out file name */
  snprintf(out_filename, sizeof(out_filename), "%s.enc", filename);

  printf("Enter shift amount (1-25): ");
  if (scanf("%d", &shift) != 1)
    return EXIT_FAILURE;

  FILE *in_fp = fopen(filename, "r");
  if (in_fp == NULL) {
    printf("Can't open input file.\n");
    return EXIT_FAILURE;
  }
  FILE *out_fp = fopen(out_filename, "w");
  if (out_fp == NULL) {
    printf("Can't open output file.\n");
    return EXIT_FAILURE;
  }

  while ((ch = getc(in_fp)) != EOF) {
    if ((ch >= 'A' && ch <= 'Z')) {
      fputc(((ch - 'A') + shift) % 26 + 'A', out_fp);
    } else if (ch >= 'a' && ch <= 'z') {
      fputc(((ch - 'a') + shift) % 26 + 'a', out_fp);
    } else {
      fputc(ch, out_fp);
    }
  }

  fclose(in_fp);
  fclose(out_fp);

  return 0;
}
