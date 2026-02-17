/* C Programming A Modern Approach
 * ex-12-05.c
 * 2026-02-16
 *
 * Suppose that a is a one-dimensional array and p is a pointer variable.
 * Assuming that the assignment p = a has just been performed, which of
 * the following expressions are illegal because of mismatched types?
 * Of the remaining expressions, which are true (have a nonzero value)?
 *
 * (a) p == a[0]
 * (b) p == &a[0]
 * (c) *p == a[0]
 * (d) p[0] == a[0]
 *
 * My Answer:
 * (a) is illegal, because p is int* and a[0] is int.
 * (b) is legal, because p is int* and &a[0] is int*. value is true.
 * (c) is legal, *p is int and a[0] is int. value is true.
 * (d) is legal, p[0] is int and a[0] is int. value is true.
 *
 */
