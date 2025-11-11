/* C Programming A Modern Approach pp6-10.c
 * 2025-11-08
 *
 * Programming Project 9 n Chapter 5 asked you to write a program that
 * determines which of two dates comes earlier on the calender.
 * Generalize the program so that the user may enter any number of dates.
 * The user will enter 0/0/0 to indicate that no more dates will be entered.
 *
 * Enter a adate (mm/dd/yy): 3/6/08
 * Enter a adate (mm/dd/yy): 5/17/07
 * Enter a adate (mm/dd/yy): 6/3/07
 * Enter a adate (mm/dd/yy): 0/0/0
 * 5/17/07 is the earliest date
 */

/* C Programming A Modern Approach pp5-9.c
 *
 * Write a  program that prompts the user to enter two dates and then
 * indicates which date comes earlier on the calendar:
 *
 * Enter first date (mm/dd/yy): 3/6/08
 * Enter second date (mm/dd/yy): 5/17/07
 * 5/17/07 is earlier than 3/6/08
 */

// #include <stdio.h>
//
// int main(void) {
//
//   int m1, d1, y1, m2, d2, y2;
//
//   printf("Enter first date (mm/dd/yy): ");
//   scanf("%d/%d/%d", &m1, &d1, &y1);
//   printf("Enter second date (mm/dd/yy): ");
//   scanf("%d/%d/%d", &m2, &d2, &y2);
//
//   if (y1 < y2 || (y1 == y2 && m1 < m2) || (y1 == y2 && m1 == m2 && d1 < d2))
//   {
//     printf("%d/%d/%.2d is earlier than %d/%d/%.2d", m1, d1, y1, m2, d2, y2);
//   } else if (y2 < y1 || (y2 == y1 && m2 < m1) ||
//              (y2 == y1 && m2 == m1 && d2 < d1)) {
//     printf("%d/%d/%.2d is earlier than %d/%d/%.2d", m2, d2, y2, m1, d1, y1);
//   } else {
//     printf("The two dates are the same.\n");
//   }
//
//   return 0;
// }

#include <stdio.h>

int main(void) {

  int m, d, y, tmp_m = 12, tmp_d = 31, tmp_y = 99;

  for (;;) {
    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &m, &d, &y);
    if (m == 0 && d == 0 && y == 0)
      break;

    if (y < tmp_y || (y == tmp_y && m < tmp_m) ||
        (y == tmp_y && m == tmp_m && d < tmp_d)) {
      tmp_y = y;
      tmp_m = m;
      tmp_d = d;
    }
  }
  printf("%d/%d/%.2d is the earliest date\n", tmp_m, tmp_d, tmp_y);
  return 0;
}
