/* C Programming A Modern Approach
 * ex-13-05-a.c
 * 2026-03-02
 *
 * (a) Write a function named capitalize that capitalizes all letters in its
 * argument. The argument will be a null-terminated string containing arbitrary
 * characters, not just letters. Use array subscripting to access the characters
 * in the string. Hint: Use the toupper function to confvert each charactre to
 * upper-case
 *
 * (b) Rewrite the capitalize function, this time using pointer arithmetic to
 * access the characters in the string.
 */

#include <ctype.h>
#include <stdio.h>

#define N 80

void capitalize(char str[]);

int main(void)
{
    int i = 0, ch;
    char str[N + 1];

    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n')
        if (i < N)
            str[i++] = ch;

    str[i] = '\0';

    capitalize(str);
    printf("%s\n", str);

    return 0;
}

void capitalize(char str[])
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        str[i] = toupper(str[i]);
}
