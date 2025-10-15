/* Write a program that asks the user to tnter the numbers from 1 to 16 (in any
 * order) and then displays the numbers in a 4 by 4 ararngement, followed by the
 * sums of the rows, columns, and dagonals:
 *
 * Enter the numbers from 1 to 16 in any order:
 *
 * 16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1
 *
 * 16  3 2 13
 * 5  10 11 8
 * 9  6 7 12
 * 4  15  14  1
 *
 * Row sums: 34 34  34  34
 * coumn sums: 34 34  34  34
 * diagonal sums:   34  34
 *
 * If the row, column, and diagonal sums are all the same (as tthey are in this
 * expample), the numbers are said to form a magic square.  The magic square
 * shown here appears in a 1514 engraving by arttist and amthematicial Albrecht
 * Durer. (Note that the middlde numbers in the last row give the dateof the
 * engraving.)
 */

#include <stdio.h>

int main(void) {
  int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16;
  printf("Enter the numbers from 1 to 16 in any order: ");
  scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &n1, &n2, &n3, &n4, &n5, &n6, &n7,
        &n8, &n9, &n10, &n11, &n12, &n13, &n14, &n15, &n16);
  printf("%2d\t%2d\t%2d\t%2d\n", n1, n2, n3, n4);
  printf("%2d\t%2d\t%2d\t%2d\n", n5, n6, n7, n8);
  printf("%2d\t%2d\t%2d\t%2d\n", n9, n10, n11, n12);
  printf("%2d\t%2d\t%2d\t%2d\n", n13, n14, n15, n16);

  printf("Row sums: \t%d\t%d\t%d\t%d\n", n1 + n5 + n9 + n13,
         n2 + n6 + n10 + n14, n3 + n7 + n11 + n15, n4 + n8 + n12 + n16);
  printf("Column sums: \t%d\t%d\t%d\t%d\n", n1 + n2 + n3 + n4,
         n5 + n6 + n7 + n8, n9 + n10 + n11 + n12, n13 + n14 + n15 + n16);
  printf("Diagonal sums: \t%d\t%d\n", n1 + n6 + n11 + n16, n4 + n7 + n10 + n13);

  return 0;
}
