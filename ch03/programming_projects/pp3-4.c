/* Write a program that prompts the user to enter a telephone number in the form
(xxx)xxx-xxxx and then displays the number inthe form xxxx.xxx.xxx:

Enter phone number [(xxx) xxx-xxxx]: (404) 817-6900
Your entered 404.817.6900
*/

#include <stdio.h>

int main(void) {
  int area, key, number;
  printf("Enter phone number [(xxx xxx-xxxx)]: ");
  scanf("(%d) %d-%d", &area, &key, &number);
  printf("You entered %d.%d.%d\n", area, key, number);

  return 0;
}
