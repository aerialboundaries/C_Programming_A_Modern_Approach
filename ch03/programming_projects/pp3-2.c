/* C Programming A Modern Approach ch03 pp3-2.c */

/* Write a program that formats product information entered by the user.  A
 * session with the program shuld look like this: Enter item number: 583 Enter
 * unit price 13.5 Enter purchase date (mm/dd/yyyy): 10/24/2010
 *
 * Item         Unit          Purchase
 *              Price         Date
 * 583          $  13.50      10/24/2010
 *
 * The item number and date should be left justified: the unit price should be
 * right justified. Allow dollar amounts up to $9999.99.  Hint: Use tabs so to
 * line up the columns.
 */

#include <stdio.h>

int main(void) {
  int item_number;
  float unit_price;
  int month, date, year;

  printf("Enter item number: ");
  scanf("%d", &item_number);
  printf("Enter unit price: ");
  scanf("%f", &unit_price);
  printf("Enter purchase date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &month, &date, &year);

  printf("Item\t\tUnit\t\tPurchase\n");
  printf("\t\tPrice\t\tDate\n");
  printf("%d\t\t$%4.2f\t\t%2d/%2d/%4d\n", item_number, unit_price, month, date,
         year);

  return 0;
}
