// 2026-06-09

/*
Write the following functions:
unsigned int rotate_left (unsigned int i, int n);
unsigned int rotate_right (unsigned int i, int n);
rotate left should return the result of shifting the bits in i to the left by n
places, with the bits that were "shifted off" moved to the right end of i. (For
example, the call rotate left (0x12345678, 4) should return 0x23456781 if
integers are 32 bits long.) rotate right is similar, but it should "rotate" bits
to the right instead of the left.

My Answer:
*/
#include <stdio.h>

unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);

int main(void)
{
  unsigned int i = 0x12345678;
  int n = 4;

  printf("%x rotated left by %d bits : %x\n", i, n, rotate_left(i, n));
  printf("%x rotated right by %d bits : %x\n", i, n, rotate_right(i, n));

  return 0;
}

unsigned int rotate_left(unsigned int i, int n)
{
  return i << n | i >> (sizeof(i) * 8 - (n));
}

unsigned int rotate_right(unsigned int i, int n)
{
  return i >> n | i << (sizeof(i) * 8 - (n));
}
