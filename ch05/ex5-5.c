/* C Programming A Modern Approach ex5.5-c
 * Is the following if statement legal?
 *
 * If (n >= 1 <= 10)
 * printf("n is between 1 and 10\n");
 *
 * If so, what does it do when n is equal to 0?
 */

/* My Answer: if n = 0, (n >= 1 <=10) returns 1.
 * the expression is evaluated ((n >= 1) <=10).
 * so, the expression means (0 <= 10).  Thus
 * the final evaluation is 1.
 */
