/* C Programming A Modern Approadh
 * pp08-09.c
 * 2025-11-28
 *
 * Write a program that generates a "random walk" across a 10 x 10 array.
 * The arra will cotain characters (all '.' initially). The programs must
 * randomly "walk" from element to element, always going up, down, left, or
 * right by one element. The elements visited by the program will be labeled
 * with the letters A through Z, in the order visited. Here's an example
 * of the desired output:
 *
 * A . . . . . . . . .
 * B C D . . . . . . .
 * . F E . . . . . . .
 * H G . . . . . . . .
 * I . . . . . . . . .
 * J . . . . . . . . .
 * K . . R S T U V Y .
 * L M P Q . . . W X .
 * . N O . . . . . . .
 * . . . . . . . . . .
 *
 * Hint: Use the srand and rand functions (see deal.c) to generage random
 * numbers. After generating a number, look at its remainder when divided
 * by 4. There are four possible values for the remainder - 0, 1, 2, and 3
 * - indicating the direction of the next move. Before performing a move,
 *   check that (a) it won't go outside the array, and (b) it doesn't take
 *   us to an element that already has a letter assigned. If either
 *   condition is violated, try moving in another directions. If all four
 *   directions are blocked, the program must terminate. Here's an example
 *   of premature termination:
 *
 * A B G H I . . . . .
 * . C F . J K . . . .
 * . D E . M L . . . .
 * . . . . N O . . . .
 * . . W X Y P Q . . .
 * . . V U T S R . . .
 * . . . . . . . . . .
 * . . . . . . . . . .
 * . . . . . . . . . .
 * . . . . . . . . . .
 *
 * Y is blocked on all four sides, so there's no place to put Z.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 10
#define C 10

int main(void) { return 0; }
