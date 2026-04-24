/* C_Programming_A_Modern_Approach
 * ex-17-05.c
 * 2026-04-24
 *
 * Suppose that f and p are declared as follows:
 * struct {
 *   union {
 *     char a, b;
 *     int c;
 *   } d;
 *   int e[5];
 * } f, *p = &f;
 *
 * Which of the following statements are legal?
 * (a) p->b =1;
 * (b) p->e[3] = 10;
 * (c) (*p) .d.a = '*';
 * (d) p->d->c= 20;
 *
 * My Answer
 * b and c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************** My Answer ************************************/

/*****************************************************************************/

int main(void)
{
    return 0;
}
