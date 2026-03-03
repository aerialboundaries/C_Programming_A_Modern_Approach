/* C Programming A Modern Approach
 * ex-13-11.c
 * 2026-03-02
 *
 * The Q&A section at the end of this chapter shows how the strcmp function
 * might be written using array subscripting. Modify the function to use pointer
 * arithmetic instead.
 */

#include <stdio.h>
#include <string.h>

#define N 80

int my_strcmp(char *s, char *t);

int main(void)
{
    char s[80] = { "Thbs is a pen." };
    char t[80] = { "That is a pen." };

    printf("my_strcpm: %d\n", my_strcmp(s, t));

    return 0;
}

int my_strcmp(char *s, char *t)
{
    int i;

    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}
