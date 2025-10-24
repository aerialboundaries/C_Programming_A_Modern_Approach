/* C Programming A Modern Approach ex5-9.c
 *
 * Are the following if statements equivalent? If not, why not?
 *
 * My answer : equivalent (correct)
 */

#include <stdio.h>

int main(void) {
  int score;

  score = 78;

  //(a)
  if (score >= 90)
    printf("A");
  else if (score >= 80)
    printf("B");
  else if (score >= 70)
    printf("C");
  else if (score >= 60)
    printf("D");
  else
    printf("F");

  // b
  if (score < 60)
    printf("F");
  else if (score < 70)
    printf("D");
  else if (score < 80)
    printf("C");
  else if (score < 90)
    printf("B");
  else
    printf("A");
}
