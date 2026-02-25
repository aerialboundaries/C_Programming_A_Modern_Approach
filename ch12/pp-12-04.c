/* C Programming A Modern Approach
 * pp-12-04.c
 * 2026-02-25
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
 *
 * pp-12-04.c
 * Simplify Programming Project 2(b) by taking advantage of the fact that an
 * array name can be used as a pointer.
 */

// My Anwer for (b)

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define N 80

int main(void)
{
    int ch, a[N], *p = a, *left, *right;
    bool palindrome = true;

    printf("Enter a message: ");

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (isalpha(ch)) {
            if (p < a + N) {
                *p++ = tolower(ch);
            }
        }
    }

    left = a;
    right = p - 1;

    while (left < right) {
        if (*left != *right) {
            palindrome = false;
            break;
        }
        left++;
        right--;
    }

    if (palindrome)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}
