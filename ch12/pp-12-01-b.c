/* C Programming A Modern Approach
 * pp-12-01.c
 * 2026-02-18
 *
 * (a) Write a program that reads a message, then prints the reversal of the
 * message: Enter a message: Don't get mad, get even. Reversal is: .neve teg
 * ,dam teg t'noD
 *
 * Hint: Read the message one character at a time (using getchar) and store the
 * characters in an array. Stop reading when the array is full or character read
 * is '\n'.
 *
 * (b) Revise the program to use a pointer instead of an integer to keep trak of
 * the current position in the array.
 */

// My Anwer for (b)
#include <stdio.h>

#define N 100

int main(void)
{
    int ch;
    char a[N] = { 0 };
    char *p = a;

    printf("Enter a message: ");

    while (p < a + N && (ch = getchar()) != '\n' && ch != EOF) {
        *p++ = ch;
    }

    printf("Reversal is: ");

    while (p > a) {
        printf("%c", *--p);
    }
    printf("\n");
    return 0;
}
