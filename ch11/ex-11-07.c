/* C Programming A Modern Approach
 * ex-11-07.c
 * 2022-02-13
 *
 * Write the follwing function:
 *
 * void split_date(int day_of_year, int year, int *month, int *day);
 *
 * day_of_year is an integer between 1 and 366, specifying a particular
 * day within the year desinated by year. month and day point to variables
 * in which the fuction will store the equivalent month (1-12) and day
 * within that month (1-31).
 */

void split_date(int day_of_year, int year, int *month, int *day) {
  int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
    days_in_month[1] = 29;

  for (int i = 0; i < 12; i++) {
    day_of_year -= days_in_month[i];
    if (day_of_year <= 0) {
      *month = i + 1;
      *day = day_of_year + days_in_month[i];
      break;
    }
  }
}
