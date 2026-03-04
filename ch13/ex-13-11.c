/* C Programming A Modern Approach
 * ex-13-11.c
 * 2026-03-02
 *
 * The Q&A section at the end of this chapter shows how the strcmp function
 * might be written using array subscripting. Modify the function to use pointer
 * arithmetic instead.
 */

#include <stdio.h>

#define N 80

int my_strcmp(const char *s, const char *t);

int main(void)
{
    char s[80] = { "This is a pen." };
    char t[80] = { "This is a pen." };

    printf("my_strcpm: %d\n", my_strcmp(s, t));

    return 0;
}

int my_strcmp(const char *s, const char *t)
{
    while (*s == *t) {
        if (*s == '\0') {
            return 0;
        }
        s++;
        t++;
    }
    return (unsigned char)*s - (unsigned char)*t;
}
