// 2026-06-09

/*

Write the following function:
unsigned int reverse_bits(unsigned int n);
reverse_bits should return an unsigned integer whose bits are the same as those
in n but in reverse order.
*/
#include <stdio.h>

unsigned int reverse_bits(unsigned int n);
void print_binary(unsigned int n);

int main(void)
{
  unsigned int n = 825;

  printf("Original decimal: %d\n", n);
  printf("Original binary: ");
  print_binary(n);
  printf("\n");

  printf("Reversed binary: ");
  print_binary(reverse_bits(n));
  printf("\n");
  return 0;
}

void print_binary(unsigned int n)
{
  for (int i = 31; i >= 0; i--) {
    if ((n & (1U << i)) != 0) {
      printf("1");
    } else {
      printf("0");
    }

    if (i % 4 == 0 && i != 0) {
      printf(" ");
    }
  }
}

unsigned int reverse_bits(unsigned int n)
{
  unsigned int reversed;

  for (int i = 0; i < 32; i++) {
    reversed <<= 1;
    if ((n & 1U) != 0) {
      reversed |= 1U;
    }

    n >>= 1;
  }
  return reversed;
}
