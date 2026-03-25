#include <stdio.h>

// #define DEBUG
#include "debug.h"

int main(void)
{
    int i = 1, j = 2, k = 3;

#ifdef DEBUG
    printf("Output if DEBUG is defined: \n");
#else
    printf("Output if DEBUG is not defined: \n");
#endif

    PRINT_DEBUG(i);
    PRINT_DEBUG(j);
    PRINT_DEBUG(k);
    PRINT_DEBUG(i + j);
    PRINT_DEBUG(2 * i + j - k);

    return 0;
}

/***********************************************************************
 * (a) What is the output when the program is executed?
 *     Output if DEBUG is defined:
 *     Value of i : 1
 *     Value of j : 2
 *     Value of k : 3
 *     Value of i + j : 3
 *     Value of 2 * i + j - k : 1
 *
 * (b) What is the output if the #define directive is removed from
 *     testdebug.c?
 *     Output if DEBUG is not defined:
 *
 * (c) Explain why the output is different in parts (a) and (b)
 *     in (b) DEBUG is not defined and PRINT_DBUG(n) bocomes
 *     empty.
 *
 * (d) Is it necessary for the DEBUG macro to be defined before
 *     debug.h is included in order for PRINT_DEBUG to have the
 *     desired effect? Justify your answer
 *     Yes. Preprocessor processes as it reads code. So, if DEBUG
 *     is defined after debug.h is included, it is not read by
 *     debug.h
 ***********************************************************************/
