/*
Write a program that reads a date from the command line and displays it in the
following form:

September 13, 2010

Allow the user to enter the date as either 9-13-2010 or 9/13/2010; you may
assume that there are no spaces in the date. Print an error message if the date
doesn't have one of the specified forms. Hint: Use sscanf to extract the month,
day, and year from the command- line argument.
*/

// 2026-08-09

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int month, day, year;
  char *monthname[] = {"January",   "February", "March",    "April",
                       "May",       "June",     "July",     "August",
                       "September", "October",  "November", "December"};

  if (argc != 2) {
    fprintf(stderr, "Usage: %s date (ex: 9-13-2010 or 9/13/2010)\n", argv[0]);
    return EXIT_FAILURE;
  }

  if ((sscanf(argv[1], "%d/%d/%d", &month, &day, &year) == 3)) {
    printf("%s %d, %d\n", monthname[month - 1], day, year);
  } else if ((sscanf(argv[1], "%d-%d-%d", &month, &day, &year)) == 3) {
    printf("%s %d, %d\n", monthname[month - 1], day, year);
  } else {
    fprintf(stderr, "Date is not in the proper form\n");
    exit(EXIT_FAILURE);
  }

  return 0;
}
