/* Write a program that breaks dow an ISBN enttered b the user.
 *
 * Enter ISBN: 978-0-393-97950-3
 * GS1 prefix: 978
 * Group identifier: 0
 * Publisher code: 393
 * Item number: 97950
 * Checkdigit: 3
 *
 * Note: The number of digits in each group may vary:  you can't assumethat
 * groups have the lenth shown in this example.  Thestyour program with actual
 * ISBN values (usually found on the back ocover of a book and on the copyright
 * page).
 */

#include <stdio.h>

int main(void) {
  int gsi_prefix, group_identifier, publisher_code, item_number, check_digit;
  printf("Enter ISBN: ");
  scanf("%d-%d-%d-%d-%d", &gsi_prefix, &group_identifier, &publisher_code,
        &item_number, &check_digit);
  printf("GS1 prefix: %d\n", gsi_prefix);
  printf("Group identifier: %d\n", group_identifier);
  printf("Publiser code: %d\n", publisher_code);
  printf("Item number: %d\n", item_number);
  printf("Check digit: %d\n", check_digit);

  return 0;
}
