/* C Programming A Modern Approach
 * ex-13-10.c
 * 2026-03-02
 *
 * The following function supposedly creates an identical copy of a string.
 * What's wrong with the fuction?
 *
 * char *duplicate(const char *p)
 * {
 *    char *q;
 *    strcpy(q, p);
 *    return q;
 * }
 *
 * My Answer:
 *
 * The value of q is undefined, so the call of strcpy attempts to copy
 * the string pointed to by p into some unknown area of memory.
 * Exercise 2 in Chapter 17 discusses how to write this function correctly.
 *
 */
