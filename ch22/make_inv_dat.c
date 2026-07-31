/* Create initial inventory.dat with sample records */

#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
};

int main(void)
{
  FILE *fp;

  /* テスト用の初期データ */
  struct part initial_parts[] = {
      {101, "Disk drive", 15}, {102, "Keyboard", 30}, {103, "Monitor", 8}

  };

  size_t num_parts = sizeof(initial_parts) / sizeof(initial_parts[0]);

  /* バイナリ書き込みモード("wb")で開く */
  fp = fopen("inventory.dat", "wb");
  if (fp == NULL) {
    fprintf(stderr, "Can't create inventory file\n");
    exit(EXIT_FAILURE);
  }

  /* 構造体配列を一括でファイルに書き込む */
  if (fwrite(initial_parts, sizeof(struct part), num_parts, fp) != num_parts) {
    fprintf(stderr, "Error writing to inventory file\n");
    fclose(fp);
    exit(EXIT_FAILURE);
  }

  fclose(fp);
  printf("Successfully created inventory.dat with %zu records.\n", num_parts);

  return 0;
}
