/* C Programming A Modern Approach pp4-6.c
 * European contries use a 13 - digit code, kown as a European Article Number
 * (EAN) intead of the 12-digit Universal Product Code (UPC) found in North
 * America.  Each EAN ends with a check digit, just as a UPC does.  The
 * Technique for calculating the check digit is alsosimilar: Add the second,
 * forth, sixth, eighth, tenth, and eleventh digits. Multiply the first sum by 3
 * and add it to the secon sum. Subtract 1 from the total. Compute the remainder
 * when the adjusted total is divided by 10. Subtract the remainder from 9
 *
 * Enter the first 12 digits of an EAN: 869148426000
 * Check digit : 8
 */

#include <stdio.h>

int main(void) {

  int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, sum1, sum2, sum3,
      check;

  printf("Enter the first 12 digits of an EAN: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5, &i6,
        &i7, &i8, &i9, &i10, &i11, &i12);

  sum1 = i2 + i4 + i6 + i8 + i10 + i12;
  sum2 = i1 + i3 + i5 + i7 + i9 + i11;
  sum3 = sum1 * 3 + sum2 - 1;
  check = 9 - sum3 % 10;

  printf("Check digit : %d\n", check);

  return 0;
}
