/* Allows the user to view regions of computer memory */

#include <ctype.h>
#include <stdint.h> // uintptr_tを使用するために必要
#include <stdio.h>

typedef unsigned char BYTE;

int main(void)
{
  uintptr_t addr; // for 64bit
  int i, n;
  BYTE *ptr;

  // Use %p to display pointer
  printf("Address of main function: %p\n", (void *)main);
  printf("Address of addr variable: %p\n", (void *)&addr);

  unsigned long input_addr;
  printf("\nEnter a (hex) address: ");
  scanf("%lx", &input_addr);
  addr = (uintptr_t)input_addr;

  printf("Enter a number of bytes to view: ");
  scanf("%d", &n);

  printf("\n");
  printf("     Address          Bytes                    Characters\n");
  printf(" -----------------  -------------------------  ----------\n");

  ptr = (BYTE *)addr;
  for (; n > 0; n -= 10) {
    printf(" %016LX  ", (unsigned long long)ptr);
    for (i = 0; i < 10 && i < n; i++)
      printf("%.2X ", *(ptr + i));
    for (; i < 10; i++)
      printf("   ");
    printf(" ");
    for (i = 0; i < 10 && i < n; i++) {
      BYTE ch = *(ptr + i);
      if (!isprint(ch))
        ch = '.';
      printf("%c", ch);
    }
    printf("\n");
    ptr += 10;
  }

  return 0;
}
