// 2026-06-10

/*
Design a union that makes it possible to view a 32-bit value as either a float
or the structure described in Exercise 14. Write a program that stores 1 in
the structure's sign field, 128 in the exponent field, and 0 in the fraction
field, then prints the float value stored in the union. (The answer should
be-2.0 if you've set up the bit-fields correctly.)
*/

/*
When stored according to the IEEE floating-point standard, a float value
consists of a 1- bit sign (the leftmost-or most significant-bit), an 8-bit
exponent, and a 23-bit fraction, in that order. Design a structure type that
occupies 32 bits, with bit-field members corresponding to the sign, exponent,
and fraction. Declare the bit-fields to have type unsigned int. Check the manual
for your compiler to determine the order of the bit-fields.
*/
#include <stdio.h>

union {
  struct {
    unsigned int fraction : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } f1;

  float f;
} flt;

int main(void)
{
  flt.f1.sign = 1;
  flt.f1.exponent = 128;
  flt.f1.fraction = 0;

  printf("%4.2f\n", flt.f);

  return 0;
}
