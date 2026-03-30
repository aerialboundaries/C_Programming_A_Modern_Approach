/* C Programming A Modern Approach
 * ex-16-02.c
 * 2016-03-28
 *
 * (a) Declare structure variables named c1, c2, and c3, each having
 *     numbers real and imaginary of type double.
 *
 * (b) Modify the decralation part (a) so that c1's members initially
 *     have values 0.0 and 1.0, while c2's member are 1.0 and 0.0
 *     initially. (c3 is not initialized.)
 *
 * (c) Write statements that copy the members of c2 int c1. Can this
 *     be done in one statement, or does it require two?
 *
 * (d) Write statements that add the corresponding members of c1 and
 *     c2, storing the result in c3.
 */

/* My Answer
 * (a) struct {
 *              int a;
 *              double b;
 *     } c1, c2, c3;
 *
 * (b) struct {
 *              float a;
 *              double b;
 *     } c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3;
 *
 * (c) In one statement.
 *     c2 = c1;
 *
 * (d) c3.a = c2.a += c1.a
 *     c3.b = c2.b += c1.b
 * */
