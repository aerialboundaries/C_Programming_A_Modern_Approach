/* C Programming A Modern Approach
 * pp-13-16.c
 * 2026-03-12
 *
 * Modify Programming Project 1 from Chapter 12 so that it includes the
 * following function:
 *
 * void reverse(char *message);
 *
 * The function reverses the string pointed to by message. Hint: Use two
 * pointers, one initialy pointing to the first character of the string and the
 * other initilally pointing to the last character. Have the function reverse
 * these characters and then move the pointers tward each other, repeating the
 * process until the pointers meet.
 */

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

#include <stdio.h>

#define N 100

void reverse(char *message);

int main(void)
{
    int ch;
    char a[N + 1] = { 0 };
    char *p = a;

    printf("Enter a message: ");

    while (p < a + N && (ch = getchar()) != '\n' && ch != EOF) {
        *p++ = ch;
    }
    *p = '\0';

    reverse(a);
    printf("Reversal is: %s\n", a);
    //    printf("Reversal is: ");

    //     while (p > a) {
    //         printf("%c", *--p);
    //     }
    //     printf("\n");
    return 0;
}

void reverse(char *message)
{
    char *p = message, *q = message, tmp;

    while (*p)
        p++; // *p is '\0';
    p--; // *p is the last character

    while (p > q) {
        tmp = *q;
        *q = *p;
        *p = tmp;
        p--;
        q++;
    }
}
