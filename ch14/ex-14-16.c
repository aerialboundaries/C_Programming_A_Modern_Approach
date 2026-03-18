/* C Programming A Modern Approach
 * ex-14-16.c
 * 2026-03-18
 *
 * (C99) Assume that following macro definitions are in effect.
 * #define IDENT(x) PRAGMA(ident #x)
 * #define PRAGMA(x) _Pragma(#x)
 * What will the following line look like after macro expansion?
 * IDENT(foo)
 *
 */

/* My Answer
 * #pragma ident "foo"
 *
 */
