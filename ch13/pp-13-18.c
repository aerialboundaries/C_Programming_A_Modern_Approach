/* C Programming A Modern Approach
 * pp-13-18.c
 * 2026-03-12
 *
 * Write a program that accepts a date from the user in the form mm/dd/yyyy
 * and then displays it in the form momth dd, yyyy where month is the
 * name of the month:
 *
 * Enter a date (mm/dd/yyyy): 2/17/2011
 * You entered the date February 17, 2011
 * Store the month names in an array that contains pointers to strings.
 */
#include <stdio.h>

const char *month(int mm);

int main(void)
{
    int mm, dd, yyyy;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &mm, &dd, &yyyy);
    printf("You entered the date %s %d, %d", month(mm), dd, yyyy);

    return 0;
}

const char *month(int mm)
{
    static const char *months[]
        = { "January", "February", "March", "April", "May", "June", "July",
              "August", "September", "October", "November", "December" };

    if (mm < 1 || mm > 12)
        return NULL;

    return months[mm - 1];
}
