/* C Programming A Modern Approach
 * pp-13-17.c
 * 2026-03-11
 *
 * Modify Programming Project 2 from Chapter 12 so that it includes the
 * following function:
 *
 * bool is_palindrome(const char *message);
 *
 * The function returns true if the string pointed to by message is a
 * palindrome.
 */
/* C Programming A Modern Approach
 * pp-12-02-b.c
 * 2026-02-23
 *
 * (a) Write a program that reads a message, then checks whether it's a
 * palindrome (the letters in the message are the same from left to right as
 * from right to left):
 *
 * Enter a message: He lived as a devil, eh?
 * Palindrome
 *
 * Enter a message: Madam, I am Adam.
 * Not a palindrome
 *
 * Ignore all characters that aren't letters. Use integer variables to keep
 * track of positions in the  array.
 *
 * (b) Revise the program to use pointers instead of integers to keep track of
 * positions in the array.
 */

// My Anwer for (b)

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define N 80
bool is_palindrome(const char *message);

int main(void)
{
    int ch;
    char a[N], *p = a;
    ;
    // bool palindrome = true;

    printf("Enter a message: ");

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (isalpha(ch)) {
            if (p < a + N) {
                *p++ = tolower(ch);
            }
        }
    }
    *p = '\0';

    if (is_palindrome(a))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}

bool is_palindrome(const char *message)
{
    const char *p = message, *q = message;
    bool palindrome = true;
    while (*p)
        p++; // p is '\0'
    --p; // p is the last letter before '\0'

    while (q < p) {
        if (*q != *p) {
            return false;
            break;
        }
        q++;
        p--;
    }
    return palindrome;
}
