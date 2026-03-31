/* C Programming A Modern Approach
 * ex-16-11.c
 * 2016-03-31
 *
 * Suppose that s is the following structure:
 * struct {
 *   double a;
 *   union {
 *     char b[4];
 *     double c;
 *     int d;
 *   } e;
 *   char f[4];
 * } s;
 *
 * If char values occupy one byte, int values occupy four bytes, and
 * double values occupy eight bytes, how much space will a C compiler
 * allocate for s? (Assume that the compiler leaves no "holes"
 * between members.)
 *
 * My Answer:
 * double a (8) + double c (8) + f[4] (4) = 20 bytes
 */
