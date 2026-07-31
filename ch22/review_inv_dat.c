/* Read and display records from inventory.dat */

#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
};

int main(void)

{
  FILE *fp;

  struct part inventory[MAX_PARTS];
  int num_parts;
  int i;

  fp = fopen("inventory.dat", "rb");
  if (fp == NULL) {
    fprintf(stderr, "Can't open inventory file\n");
    exit(EXIT_FAILURE);
  }

  num_parts = fread(inventory, sizeof(struct part), MAX_PARTS, fp);
  fclose(fp);

  printf("Item Number  Item Name                  Quantity\n");
  printf("-----------  -------------------------  --------\n");

  for (i = 0; i < num_parts; i++) {
    printf("%-11d  %-25s  %8d\n", inventory[i].number, inventory[i].name,
           inventory[i].on_hand);
  }

  return 0;
}
