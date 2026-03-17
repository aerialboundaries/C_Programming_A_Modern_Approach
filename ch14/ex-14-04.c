/* C Programming A Modern Approach
 * ex-14-04.c
 * 2026-03-15
 *
 * For each of the followingmacros, give an example that illustrates a problem
 * with the macro and show how to fix it.
 *
 * (a) #define AVA(x, y) (x+y)/2
 * (b) #define AREA(x,y) (x)*(y)
 *
 */

#include <stdio.h>

#define AVG(x, y) (((x) + (y)) / 2) // (a)
#define AREA(x, y) ((x) * (y))      // (b)

int main(void) {
  int x = 2, y = 4;
  printf("= :%d\n", AVG(x, y));
  printf("= :%d\n", AREA(x, y));

  return 0;
}

/* Answer by KN
 (a) One problem stems from the lack of parentheses around the replacement list.
For example, the statement

a = 1/AVG(b, c);
will be replaced by

a = 1/(b+c)/2;
Even if we add the missing parentheses, though, the macro still has problems,
because it needs parentheses around x and y in the replacement list. The
preprocessor will turn the statement

a = AVG(b<c, c>d);
into

a = ((b<c+c>d)/2);
which is equivalent to

a = ((b<(c+c)>d)/2);
Here's the final (corrected) version of the macro:

#define AVG(x,y) (((x)+(y))/2)
(b) The problem is the lack of parentheses around the replacement list. For
example,

a = 1/AREA(b, c);
becomes

a = 1/(b)*(c);
Here's the corrected macro:

#define AREA(x,y) ((x)*(y))*
 *
 */
