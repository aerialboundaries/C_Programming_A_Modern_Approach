/* C Programming A Modern Approach
 * ex-13-06-a.c
 * 2026-03-02
 *
 * Write a function named censor that modifies a string by replacing every
 * occurrence of foo by xxx. For example, the string "food fool" would become
 * "xxxd xxxl". Make the function asshort as possible without sacrificing
 * clarity.
 */

#include <stdio.h>
#include <string.h>

#define N 80

void censor(char str[]);

int main(void)
{
    int i = 0, ch;
    char str[N + 1];

    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n')
        if (i < N)
            str[i++] = ch;

    str[i] = '\0';

    censor(str);
    printf("%s\n", str);

    return 0;
}

void censor(char str[])
{
    char *p = str;

    while (*p != '\0') {
        char test[3] = { 0 };

        if (*p == 'f') {
            test[0] = *p;
            test[1] = *(p + 1);
            test[2] = *(p + 2);

            if (strcmp(test, "foo") == 0) {
                for (int i = 0; i < 3; i++) {
                    *p++ = 'x';
                }
            }
        }
        p++;
    }
}
