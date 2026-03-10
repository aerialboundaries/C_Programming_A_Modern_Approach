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

#include <stdio.h>
#include <string.h>

void reverse_name(char *name);

int main(void)
{

    int ch; // read input
    int i = 0; // subscript of name
    char name[80];

    printf("Enter a first and last name: ");

    while ((ch = getchar()) == ' ')
        /* skip initial spaces */;
    name[i++] = ch;

    while ((ch = getchar()) != ' ') {
        name[i++] = ch;
    }
    name[i++] = ' ';
    /* store the first name */;

    while ((ch = getchar()) == ' ')
        /* skip spaces between first and last name */;
    name[i++] = ch;

    while ((ch = getchar()) != '\n') {
        name[i++] = ch;
    }
    name[i] = '\0';
    /* store the last name */;

    reverse_name(name);

    printf("%s\n", name);

    return 0;
}

void reverse_name(char *name)
{
    int j = 0;

    char f_name[80];
    char l_name[80];
    char *p = name;

    f_name[0] = *p;
    f_name[1] = '\0';

    while (*p) {
        while (*p != ' ')
            p++;
        while (*p == ' ')
            p++;
        while (*p)
            l_name[j++] = *p++;
    }
    l_name[j] = '\0';
    strcat(strcat(strcat(strcpy(name, l_name), ", "), f_name), ".\0");
}
