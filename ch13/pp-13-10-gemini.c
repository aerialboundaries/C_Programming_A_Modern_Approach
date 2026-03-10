/* C Programming A Modern Approach
 * pp-13-10.c
 * 2026-03-10
 *
 * Modify Programming Project 11 from Chapter 7 so that it includes the
 * following function:
 *
 * void reverse_name(char *name);
 *
 * The function expects name to point to a string containing a first name
 * followed by a last name. It modifies the string so that the last name comes
 * first, following by a comma, a space, the first initial, and a period. The
 * original string may contain extra spaces before the first name, between the
 * first and last names, and after the last name.
 */

/* C Programming A Modern Approach pp07-11.c
 * 2025-11-19
 *
 * Write a program that takes a first name and last name entered
 * by the user and displays the last name, a comma, and the
 * first initial, followed by a period:
 *
 * Enter a first and last name: Lloyd Fosdick
 * Fosdick, L.
 *
 * The user's input may contain extra spaces before the first
 * name, between the first and last names, and after the last
 * name.*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

void reverse_name(char *name);

int main(void)
{

    int ch = 0; // read input
    int i = 0; // subscript of name
    char name[80];

    printf("Enter a first and last name: ");

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (i < 79)
            name[i++] = (char)ch;
    }

    name[i] = '\0';

    reverse_name(name);

    printf("%s\n", name);

    return 0;
}

void reverse_name(char *name)
{
    char first_initial;
    char last_name[80];
    char *p = name;
    int i = 0;

    // skip the first spaces
    while (*p && isspace(*p))
        p++;

    // Record the initial
    first_initial = *p;

    // skip the rest of fisr name
    while (*p && !isspace(*p))
        p++;

    // skip the space before last name
    while (*p && isspace(*p))
        p++;

    // Copy lastname to array of last_name
    while (*p && !isspace(*p)) {
        last_name[i++] = *p++;
    }
    last_name[i] = '\0';

    sprintf(name, "%s, %c.", last_name, first_initial);
}
