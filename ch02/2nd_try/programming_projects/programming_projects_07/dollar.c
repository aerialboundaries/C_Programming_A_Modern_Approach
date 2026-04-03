#include <stdio.h>

int bill20;
int bill10;
int bill5;
int bill1;
int amount;

int main(void) {
  printf("Enter amount: ");
  scanf("%d", &amount);
  bill20 = amount / 20;
  bill1 = amount - bill20 * 20;
  bill10 = bill1 / 10;
  bill1 = bill1 - bill10 * 10;
  bill5 = bill1 / 5;
  bill1 = bill1 - bill5 * 5;

  printf("$20 bills: %d\n $10 bills: %d\n  $5 bills: %d\n  $1 bills: %d\n",
         bill20, bill10, bill5, bill1);
  return 0;
}
