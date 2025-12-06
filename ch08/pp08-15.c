/* C Programming A Modern Approach
 * pp08-15.c
 * 2025-12-06
 *
 * One of the oldest known encryption techniques is the Caesar cipher,
 * attributed to Julius Caesar. It involves replacing each letter in
 * a message with another letter that is a fixed number of positions
 * later in the alphabet. (If the replacement would go past the letter Z,
 * the cipher "wraps around" to the beginning of the alphabet. For example,
 * if each letter is replaced by the letter two poistions after it, then
 * Y would be replaced by A, andZ would be replaced by B.) Write a program
 * that encrypts a message using a Caesar cipher. The user will enter the
 * message to be encrypted and shift amount(the number of position by which
 * letters should be shifted):
 *
 * Enter message to be encrypted: Go ahead, make my day.
 * Enter shift amount(1-25): 3
 * Encrypted message: Jr dkhdg, pdnh pb gdb.
 *
 * Notice that the program can decrypt a message if the user enters
 * 26 minus the original key:
 *
 * Enter message to be ecrypted: Jr dkhdg, pdnh pb gdb.
 * Enter shift amount (1-25): 23
 * Encrypted message Go ahead, make my day.
 *
 * You may asssume that the message does not exceed 80 characters.
 * Characters other than letters should be left unchanged. Lower-case
 * letters remain lower-case when encrypted, and upper-case letters
 * remain upper-case. Hint: To handle the wrap-around problem, use the
 * expression ((ch - 'A') + n) % 26 + 'A' to calculate the encrypted
 * version of an upper-case letter, where ch stores the letter and n
 * stores the shift amount. (You'll need a similar expression for lower-
 * case letters.) */

#include <stdio.h>

#define MAX_LEN 80

int main(void) {
  int ch, n = 0, shift;
  char message[MAX_LEN] = {0};
  char encrypted;

  printf("Enter message to be encrypted: ");

  while ((ch = getchar()) != '\n' && n < MAX_LEN) {
    message[n] = ch;
    n++;
  }

  printf("Enter shift amount (1-25): ");
  scanf("%d", &shift);

  printf("Encrypted message: ");

  for (int i = 0; i < n; i++) {
    if ((ch = message[i]) >= 'A' && ((ch = message[i]) <= 'Z')) {
      encrypted = ((ch - 'A') + shift) % 26 + 'A';
    } else if ((ch = message[i]) >= 'a' && ((ch = message[i]) <= 'z')) {
      encrypted = ((ch - 'a') + shift) % 26 + 'a';
    } else {
      encrypted = message[i];
    }
    printf("%c", encrypted);
  }

  return 0;
}
