/* C Programming A Modern Approach
 * ex-14-10.c
 * 2026-03-17
 *
 * Functions can often - but not always - be written as parameterized macros.
 * Discuss what characteristics of a function would make it unsuitable as a
 * macro.
 *
 */
/* My Answer
 * 1. Long function.  It would be difficult to read if written as a macro.
 * 2. Function includes increment or decrement of variables. It may cause
 *    multiple evaluation in macro.
 * 3. Function which needs strict type. Macro doesn't check the type.
 * 4. Pointers cannot be passed to macro.
 * 5. Recursion cannot be realized in macro.
 */
