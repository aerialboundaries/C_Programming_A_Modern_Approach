/* main.c */
#include <stdio.h>

#include "queue.h"

int main(void)
{
  printf("--- Queue Test Start ---\n");

  insert(10);
  insert(20);
  insert(30);

  // 先に入れた10と20が順に出てくるはずです（FIFO）
  printf("Removed %d\n", remove_item());
  printf("Removed %d\n", remove_item());

  insert(40);
  insert(50);

  // 残りの要素（30, 40, 50）をすべて取り出します
  while (!is_empty()) {
    printf("Removed remaining: %d\n", remove_item());
  }

  return 0;
}
