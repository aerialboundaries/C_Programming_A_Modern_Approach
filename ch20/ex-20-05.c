// 2026-06-09

/*

Write macros named GET_RED, GET_GREEN, and GET_BLUE that, when given a color as
an argument (see Exercise 4), return its 8-bit red, green, and blue intensities.

My Answer:
typedef unsigned char BYTE;
#define GET_RED(c) ((BYTE)((c) & 0xFF))
#define GET_GREEN(c) ((BYTE)(((c) >> 8) & 0xFF))
#define GET_BLUE(c) ((BYTE)(((c) >> 16) & 0xFF))

*/
