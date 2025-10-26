/* C Programming A Modern Approach pp5-11.c
 *
 * Write a program that asks the user for a two-digit number,
 * then prints the English word for the number:
 *
 * Enter a two-digit number: 45
 * You entered the number forty-five.
 *
 * Hint: Break the number into two digits.  Use one switch
 * statement to print the word for the first digit ("twenty,"
 * "thirty," and so forth). Use a second switch statement
 * to print the word for the second digit. Don't forget that
 * the numbers between 11 and 19 require special treatment.*/

/* My Answer
#include <stdio.h>

int main(void) {

  int n, d1, d2;
  printf("Enter a two-digit number: ");
  scanf("%d", &n);

  if (n > 99 || n < 10) {
    printf("Illegal number\n");
    return 0;
  }

  d1 = n / 10;
  d2 = n % 10;

  if (n == 10)
    printf("You entered the number ten.\n");
  if (n == 11)
    printf("You entered the number eleven.\n");
  if (n == 12)
    printf("You entered the number twelve.\n");
  if (n == 13)
    printf("You entered the number thirteen.\n");
  if (n == 14)
    printf("You entered the number fourteen.\n");
  if (n == 15)
    printf("You entered the number fifteen.\n");
  if (n == 16)
    printf("You entered the number sixteen.\n");
  if (n == 17)
    printf("You entered the number seventeen.\n");
  if (n == 18)
    printf("You entered the number eighteen.\n");
  if (n == 19)
    printf("You entered the number nineteen.\n");
  if (n >= 20) {

    switch (d1) {
    case 2:
      printf("You entered the number twenty");
      break;
    case 3:
      printf("You entered the number thirty");
      break;
    case 4:
      printf("You entered the number fourty");
      break;
    case 5:
      printf("You entered the number fifty");
      break;
    case 6:
      printf("You entered the number sixty");
      break;
    case 7:
      printf("You entered the number seventy");
      break;
    case 8:
      printf("You entered the number eighty");
      break;
    case 9:
      printf("You entered the number ninety");
      break;
    }

    switch (d2) {
    case 0:
      printf(".\n");
      break;
    case 1:
      printf("-one.\n");
      break;
    case 2:
      printf("-two.\n");
      break;
    case 3:
      printf("-three.\n");
      break;
    case 4:
      printf("-four.\n");
      break;
    case 5:
      printf("-five.\n");
      break;
    case 6:
      printf("-six.\n");
      break;
    case 7:
      printf("-seven.\n");
      break;
    case 8:
      printf("-eight.\n");
      break;
    case 9:
      printf("-nine.\n");
      break;
    }
  }
  return 0;
}
*/

/* Correct Answer by Gemini */
#include <stdio.h>

int main(void) {
  int n, d1, d2;

  printf("Enter a two-digit number: ");
  if (scanf("%d", &n) != 1) {
    printf("Invalid input.\n");
    return 1;
  }

  if (n > 99 || n < 10) {
    printf("Illegal number\n");
    return 0;
  }

  d1 = n / 10;
  d2 = n % 10;

  printf("You entered the number: ");

  if (d1 == 1) {
    switch (n) {
    case 10:
      printf("ten.\n");
      break;
    case 11:
      printf("eleven.\n");
      break;
    case 12:
      printf("twelve.\n");
      break;
    case 13:
      printf("thirteen.\n");
      break;
    case 14:
      printf("fourteen.\n");
      break;
    case 15:
      printf("fifteen.\n");
      break;
    case 16:
      printf("sixteen.\n");
      break;
    case 17:
      printf("seventeen.\n");
      break;
    case 18:
      printf("eighteen.\n");
      break;
    case 19:
      printf("nineteen.\n");
      break;
    }
    return 0;
  }

  switch (d1) {
  case 2:
    printf("twenty");
    break;
  case 3:
    printf("thirty");
    break;
  case 4:
    printf("forty");
    break;
  case 5:
    printf("fifty");
    break;
  case 6:
    printf("sixty");
    break;
  case 7:
    printf("seventy");
    break;
  case 8:
    printf("eighty");
    break;
  case 9:
    printf("ninty");
    break;
  }

  if (d2 != 0) {
    printf("-");
  }

  switch (d2) {
  case 0:
    printf(".\n");
    break;
  case 1:
    printf("one.\n");
    break;
  case 2:
    printf("two.\n");
    break;
  case 3:
    printf("three.\n");
    break;
  case 4:
    printf("four.\n");
    break;
  case 5:
    printf("five.\n");
    break;
  case 6:
    printf("six.\n");
    break;
  case 7:
    printf("seven.\n");
    break;
  case 8:
    printf("eight.\n");
    break;
  case 9:
    printf("nine.\n");
    break;
  }
  return 0;
}
