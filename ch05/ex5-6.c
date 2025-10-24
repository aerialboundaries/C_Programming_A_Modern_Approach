/* C Programming A Modern Approach ex5-6.c
 *
 * Is the following if statement legal?
 *
 * If (n == 1-10)
 * printf("n is between 1 and 10\n");
 * If so, what dows it do whtn n is equal to 5?
 *
 * My Answer: The statement is legal.  When n equals to 5,
 * the evaluation is made as ((5 == 1) - 10) so, (0 - 10),
 * it returns -10.
 *
 *
 * My Answer revised: The statement is legal.  When n equals to 5,
 * the evaluation is made as ((5 == (1 - 10)) so,
 * it returns 0.
 */
