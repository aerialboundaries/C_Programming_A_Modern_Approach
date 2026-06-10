// 2026-06-10

/*

The following function supposedly combines two bytes to form an unsigned short
integer. Explain why the function doesn't work and show how to fix it.

unsigned short create_short (unsigned char high_byte,
unsigned char low_byte)
{
  return high_byte << 8 + low_byte;
}

My answer:
it is processed as high_byte << (8 + low_byte)
Correction: (high_byte << 8) + low_byte;

*/
