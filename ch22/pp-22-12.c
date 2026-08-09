/*
Modify Programming Project 2 from Chapter 3 so that the program reads a series
of items from a file and displays the data in columns. Each line of the file
will have the following form:

item, price, mm/dd/yyyy

For example, suppose that the file contains the following lines:

583,13.5,10/24/2005
3912,599.99, 7/27/2008

The output of the program should have the following appearance:

Item      Unit       Purchase
          Price      Date
583       $  13.50   10/24/2005
3912      $ 599.99   7/27/2008

Have the program obtain the file name from the command line.
*/

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
#include <stdlib.h>

#define MAX_CHAR 100

int main(int argc, char *argv[])
{
  int item_number;
  float unit_price;
  int month, date, year;
  char str[MAX_CHAR];

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "Cannot open file %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  printf("Item\t\tUnit\t\tPurchase\n");
  printf("\t\tPrice\t\tDate\n");
  while (fgets(str, sizeof(str), fp)) {
    if (sscanf(str, "%d,%f,%d/%d/%d", &item_number, &unit_price, &month, &date,
               &year) == 5) {

      printf("%d\t\t$%4.2f\t\t%2d/%2d/%4d\n", item_number, unit_price, month,
             date, year);
    }
  }
  fclose(fp);
  return 0;
}
