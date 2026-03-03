/* C Programming A Modern Approach
 * ex-13-01.c
 * 2026-02-26
 *
 * The following function calls supposedly write a single new-line character,
 * but some are incorrect. Identify which call don't work and explain why.
 *
 * (a) printf("%c", '\n');    (g) putchar('\n');
 * (b) printf("%c", "\n");    (h) putchar("\n");
 * (c) printf("%s", '\n');    (i) puts('\n');
 * (d) printf("%s", "\n");    (j) puts("\n");
 * (e) printf('\n');          (k) puts("");
 * (f) printf("\n");
 */

/* My Answer
 *
 * (a) correct
 * (b) Not correct. %c expects char, not string literal
 * (c) Not correct. %s expects string literal, not char
 * (d) Correct
 * (e) Not correct printf expects a pointer or string literal, not char
 * (f) correct
 * (g) correct
 * (h) Not correct. putchar expects char.
 * (i) Not correct. puts expects string literal or pointer
 * (j) Not correct. puts output \n automatically. Should be puts("");
 * (K) correct
 *
 * */
