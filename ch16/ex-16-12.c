/* C Programming A Modern Approach
 * ex-16-11.c
 * 2016-03-31
 *
 * Suppose that u is the following union:
 *
 * union {
 *   double a;
 *   struct {
 *     char b[4];
 *     double c;
 *     int d;
 *   } e;
 *   char f[4];
 * } u;
 *
 * If char values occupy one byte, int values occupy four bytes,
 * and double values occupy eight bytes, how much space will a
 * C compiler allocate for u? (Assume that the compiler leaves
 * no "holes" between members.)
 *
 * My Answer:
 * 16 bytes (size of struct e)
 *
 */
