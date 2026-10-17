/*
(C99) In each of the following statements, assume that the variable i has the
indicated original type. Using macros from the <inttypes.h> header, modify each
statement so that it will work correctly if the type of i is changed to the
indicated new type.

(a) printf("%d", i);    Original type: int    New type: int8_t
(b) printf("%12.4d", i); Original type: int   New type: int32_t
(c) printf("%-6o", i);  Original type: unsigned int   New type: uint16_t
(d) printf("%#x", i);   Original type: unsigned int New type: uint64_t
*/

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
  // (a)
  int8_t i = INT8_C(99);
  printf("i = %" PRId8 "\n", i); // Original type: int    New type: int8_t

  // (b)
  int32_t ib = INT32_C(31200);
  printf("ib = %12.4" PRId32 "\n",
         ib); // Original type: int   New type: int32_t

  // (c)
  uint16_t ic = UINT16_C(31200);
  printf("ic = %-6" PRIo16 "\n",
         ic); // Original type : unsigned int New type : uint16_t

  // (d)
  uint64_t id = UINT64_C(31200);
  printf("id = %#" PRIx64 "\n",
         id); // Original type : unsigned int New type : uint64_t

  return 0;
}
