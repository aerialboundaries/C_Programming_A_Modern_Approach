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

char *capitalize(char str[], int n);

int main(void)
{
    int i = 0, ch;
    char str[N + 1];

    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n')
        if (i < (N + 1))
            str[i++] = ch;

    str[i] = '\0';

    printf("%s\n", capitalize(str, N + 1));

    return 0;
}

char *capitalize(char str[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        str[i] = toupper(str[i]);

    return str;
}
