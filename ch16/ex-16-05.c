/* C Programming A Modern Approach
 * ex-16-05.c
 * 2016-03-30
 *
 * Write the following functions, assuming that the date structure
 * contains three members: month, day, and year (all of type int).
 *
 * (a) int day_of_year(struct date d);
 * Returns the day of the year (an integer between 1 and 366)
 * that corresponds to the date d.
 *
 * (b) int compare_dates(struct date d1, struct date d2);
 * Returns -1 if d1 is an earlier than d2, +1 if d1 is a latter
 * date than d2, and 0 if d1 and d2 are the same.
 */

/* My Answer (a) */
#include <stdio.h>

struct date {
    int month, day, year;
};

int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);

int main(void)
{

    struct date d = { 6, 4, 1968 }, d1 = { 10, 14, 2011 }, d2 = { 9, 22, 2016 };

    /// (a)
    printf("The day of %4d/%02d/%02d is: %d\n", d.year, d.month, d.day,
        day_of_year(d));
}

int day_of_year(struct date d)
{
    d.year % 4 = 0 || d.year % 400 = 0
}

int compare_dates(struct date d1, struct date d2)
{
}
