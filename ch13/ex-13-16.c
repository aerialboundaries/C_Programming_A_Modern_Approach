/* C Programming A Modern Approach
 * ex-13-16.c
 * 2026-03-05
 *
 * Use the tecniques of Section 13.6 to condense the count_spaces function
 * of Section 13.4. In paticular, replace the for statement by a while loop.
 */
#include <stdio.h>

// int count_spaces(const char *s)
// {
//     int count = 0;
//
//     for (; *s != '\0'; s++)
//         if (*s == ' ')
//             count++;
//     return count;
// }

int count_spaces2(const char *s)
{
    int count = 0;

    while (*s)
        if (*s++ == ' ')
            count++;
    return count;
}

int main(void)
{
    char test[] = "This is a pen, that is a pencil.";

    printf("%d\n", count_spaces2(test));

    return 0;
}
