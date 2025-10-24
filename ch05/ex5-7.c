/* C Programming A Modern Approach ex5-7.c
 * What does the following statement print if i has the value 17?
 * What does it print if i has the value -17?
 *
 * printf("%d\n", i >=  0 ? i : - i);
 *
 * My Answer:
 * in case 17, prints -17
 * in case -17 prints -17
 *
 *$ ./a.out
 * i = 17: 17
 * i = -17: 17
 */

#include <stdio.h>

int main(void) {
  int i;

  i = 17;
  printf("i = 17: %d\n", i >= 0 ? i : -i);

  i = -17;
  printf("i = -17: %d\n", i >= 0 ? i : -i);

  return 0;
}
