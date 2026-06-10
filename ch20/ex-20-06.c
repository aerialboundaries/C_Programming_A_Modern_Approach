// 2026-06-09

/*
(a) Use the bitwise operators to write the following function:
unsigned short swap_bytes(unsigned short i);
swap_bytes should return the number that results from swapping the two bytes in
i. (Short integers occupy two bytes on most computers.) For example, if i has
the value 0x1234 (00010010 00110100 in binary), then swap_bytes should return
0x3412 (00110100 00010010 in binary). Test your function by writing a program
that reads a number in hexadecimal, then writes the number with its bytes
swapped:

Enter a hexadecimal number (up to four digits): 1234
Number with bytes swapped: 3412
Hint: Use the %hx conversion to read and write the hex numbers.

(b) Condense the swap_bytes function so that its body is a single statement.

My Answer: (a)
*/
#include <stdio.h>

unsigned short swap_bytes(unsigned short i)
{
  unsigned int swap;

  swap = (i << 8) | (i >> 8);
  return swap;
}

int main(void)
{
  unsigned short input;
  printf("Enter a hexadecimal number: ");
  scanf("%hx", &input);

  printf("Number with bytes swapped: %hx\n", swap_bytes(input));

  return 0;
}
