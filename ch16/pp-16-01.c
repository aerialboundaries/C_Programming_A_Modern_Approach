/* C Programming A Modern Approach ********************************************
 * pp-16-01.c
 * 2026-04-01
 *
 * Write a program that asks the user to enter an international dialing code
 * and then looks it up in the country_codes array (see Section 16.3).
 * If it finds the code, the program should display the name of the
 * corresponding country; if not, the program should print an error message.
 *
 ******************************************************************************/

#include <ctype.h>
#include <stdio.h>

struct dialing_code {
  char *country;
  int code;
};

const struct dialing_code country_codes[] = {{"Argentina", 54},
                                             {"Bangladesh", 880},
                                             {"Brazil", 55},
                                             {"Burma (Myanmar)", 95},
                                             {"China", 86},
                                             {"Colombia", 57},
                                             {"Congo, DEm Rep. of", 243},
                                             {"Egypt", 20},
                                             {"Ethiopia", 251},
                                             {"France", 33},
                                             {"Germany", 49},
                                             {"India", 91},
                                             {"Indonesia", 62},
                                             {"Iran", 98},
                                             {"Italy", 39},
                                             {"Japan", 81},
                                             {"Mexico", 52},
                                             {"Nigeria", 234},
                                             {"Pakistan", 92},
                                             {"Philippines", 63},
                                             {"Poland", 48},
                                             {"Russia", 7},
                                             {"South Africa", 27},
                                             {"South Korea", 82},
                                             {"Spain", 34},
                                             {"Sudan", 249},
                                             {"Thailand", 66},
                                             {"Turkey", 90},
                                             {"Ukraine", 380},
                                             {"United Kingdom", 44},
                                             {"United States", 1},
                                             {"Vietnam", 84}};

// int main(void) {
//
//   int code = 0;
//
//   for (;;) {
//     printf("Enter country code: ");
//     if (scanf("%d", &code) != 1) {
//       printf("Invalid input\n");
//       continue;
//     }
//     break;
//   }
//
//   size_t len;
//   len = sizeof(country_codes) / sizeof(country_codes[0]);
//   size_t i;
//   int found = 0;
//
//   for (i = 0; i < len; i++) {
//     if (country_codes[i].code == code) {
//       printf("Country: %s\n", country_codes[i].country);
//       found = 1;
//       break;
//     }
//   }
//   if (found == 0)
//     printf("There was no match.\n");
//
//   return 0;
// }

// KN
#define COUNTRY_COUNT ((int)(sizeof(country_codes) / sizeof(country_codes[0])))

int main(void) {
  int code, i;

  printf("Enter dialing code:");
  scanf("%d", &code);

  for (i = 0; i < COUNTRY_COUNT; i++)
    if (code == country_codes[i].code) {
      printf("The country code with dialing code %d is %s\n", code,
             country_codes[i].country);
      return 0;
    }

  printf("No corresponding country found\n");
  return 0;
}
