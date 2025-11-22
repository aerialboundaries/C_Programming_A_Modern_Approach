/* ex08-01
We discussed using the expressions sizeof(a) / sizeof(a[0]) to calculate the
number of elements in an array. The experssion sizeof(a) / sizeof(t), where t is
the type of a's elements, woude also work, but it's considered an inferior
technique. Why? */

/* Answer
 * The problem with sizeof(a) / sizeof(t) is that it can't easiliy be checked
 * for correctness by someone reading the program. (The reader woud have to
 * locate the declaration of a and make sure that its elements have type t.) */
