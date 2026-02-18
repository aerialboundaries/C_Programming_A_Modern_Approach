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

// My Anwer for (a)
#include <stdio.h>

#define N 100

int main(void)
{
    int ch, i = 0;
    char a[N] = { 0 };

    printf("Enter a message: ");

    while (i < N && (ch = getchar()) != '\n' && ch != EOF) {
        a[i++] = ch;
    }

    printf("Reversal is: ");

    while (i > 0) {
        printf("%c", a[--i]);
    }
    printf("\n");
    return 0;
}
