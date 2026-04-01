/* C Programming A Modern Approach
 * ex-16-17.c
 * 2026-03-31
 *
 * Suppose that b and i are declared as follows:
 * enum {FALSE, TRUE} b;
 * int i;
 *
 * Which of the following statements are legal?
 * Which ones are "safe" (alway yield a meaningful result):
 *
 * (a) b = FALSE;
 * (b) b = i;
 * (c) b++;
 * (d) i = b;
 * (e) i = 2 * b + 1;
 *
 * My Answer:(KN)
 * All the statements are legal, since C allows integers and enumeration
 * values to be mixed without restriction. Only (a), (d), and (e) are safe.
 * (b) is not meaningful if i has a value other than 0 or 1. (c) will not
 * yield a meaningful result if b has the value 1.
 *
 */
