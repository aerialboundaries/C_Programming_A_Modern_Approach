/* C Programming A Modern Approac ex5-8.c
 *
 * The follwoing if statement is unnecessarily complicated.
 * Simplify it as much as possible.
 * (Hint: The entire statement can be replaced by a single assignment.)
 *
 * if (age > = 13)
 * if (age < = 19)
 * teenager = turue;
 * else
 * teenager = false;
 * else if (age < 13)
 * teenager = false;
 */

#include <stdio.h>

int main(void) {
  int age, teenager;

  age = 14;

  teenager = age >= 13 && age <= 19;
  printf("Age: %d, teenager: %d\n", age, teenager);
}
