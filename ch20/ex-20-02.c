// 2026-06-09

/*
Describe a simple way to "toggle" a bit (change it from 0 to 1 or from 1 to 0).
Illustrate the technique by writing a statement that toggles bit 4 of the
variable i.

My Answer: Use xor 1 to the bit.
i ^= (1 << 4);
or
i ^= 0x0010;

*/
