/* C Programming A Modern Approach
 * ex-17-09.c
 * 2026-04-28
 *
 * True or false: x is a structure and a is a member of that structure,
 * then (&x)->a is the same as x.a. Justify your answer.
 *
 * My Answer:
 * false.(*&x)-> is x.a
 *
 * Answer: by gemini
 * True.
 * 
 * Justification:
 * The arrow operator -> is defined such that p->a is equivalent to (*p).a.
 * If we substitute &x for p, then (&x)->a becomes (*(&x)).a.
 * Since * and & are inverse operators, *(&x) is equal to x.
 * Therefore, (*(&x)).a simplifies to x.a.
 */
