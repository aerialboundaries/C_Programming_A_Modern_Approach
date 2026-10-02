/*
Write a program that obtains the name of a locale from the command line and then displays
the values stored in the corresponding 1conv structure. For example, if the locale is
"fi_FI" (Finland), the output of the program might look like this:

decimal_point = ","
thousands_sep = " "
grouping = 3
mon_decimal_point = ","
mon_thousands sep =" "
mon_grouping = 3
positive_sign = ""
negative_sign = "-"
currency_symbol = "EUR"
frac_digits = 2
p_cs_precedes = 0
n_cs precedes = 0
p_sep_by_space = 2
n_sep_by_space =2
p_sign_posn = 1
n_sign_posn = 1
int_curr symbol = "EUR "
int_frac_digits =2
int p_cs_precedes = 0
int_n_cs precedes = 0
int_p_sep_by_space = 2
int_n_sep_by_space = 2
int_p_sign_posn = 1
int n_sign posn = 1

For readability, the characters in grouping and mon_grouping should be displayed as
decimal numbers.

*/

#include <locale.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <locale_name>\n", argv[0]);
    return 1;
  }

  // set locale
  if (setlocale(LC_ALL, argv[1]) == NULL) {
    fprintf(stderr, "Invalid locale: %s\n", argv[1]);
    return 1;
  }

  struct lconv *my_loc = localeconv();

  printf("decimal_point = \"%s\"\n", my_loc->decimal_point);
  printf("thousands_sep = \"%s\"\n", my_loc->thousands_sep);
  printf("grouping = %d\n", (int)my_loc->grouping[0]);
  printf("mon_decimal_point = \"%s\"\n", my_loc->mon_decimal_point);
  printf("mon_thousands_sep = \"%s\"\n", my_loc->mon_thousands_sep);
  printf("mon_grouping = %d\n", (int)my_loc->mon_grouping[0]);
  printf("positive_sign = \"%s\"\n", my_loc->positive_sign);
  printf("negative_sign = \"%s\"\n", my_loc->negative_sign);
  printf("currency_symbol = \"%s\"\n", my_loc->currency_symbol);
  printf("frac_digits = %d\n", my_loc->frac_digits);
  printf("p_cs_precedes = %d\n", my_loc->p_cs_precedes);
  printf("n_cs_precedes = %d\n", my_loc->n_cs_precedes);
  printf("p_sep_by_space = %d\n", my_loc->p_sep_by_space);
  printf("n_sep_by_space = %d\n", my_loc->n_sep_by_space);
  printf("p_sign_posn = %d\n", my_loc->p_sign_posn);
  printf("n_sign_posn = %d\n", my_loc->n_sign_posn);
  printf("int_curr_symbol = \"%s\"\n", my_loc->int_curr_symbol);
  printf("int_frac_digits = %d\n", my_loc->int_frac_digits);
  printf("int_p_cs_precedes = %d\n", my_loc->int_p_cs_precedes);
  printf("int_n_cs_precedes = %d\n", my_loc->int_n_cs_precedes);
  printf("int_p_sep_by_space = %d\n", my_loc->int_p_sep_by_space);
  printf("int_n_sep_by_space = %d\n", my_loc->int_n_sep_by_space);
  printf("int_p_sign_posn = %d\n", my_loc->int_p_sign_posn);
  printf("int_n_sign_posn = %d\n", my_loc->int_n_sign_posn);

  return 0;
}
